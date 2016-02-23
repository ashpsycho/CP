#include <bits/stdc++.h>
using namespace std;
long double arr[10][10],ans[10][10];
void expo(int n){
	int i,j,k;
	long double temp[10][10];
	while(n>0){
		if(n&1){
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					temp[i][j]=0.0;
					for(k=0;k<10;k++)temp[i][j]+=(ans[i][k]*arr[k][j]);
				}
			}
			for(i=0;i<10;i++)
				for(j=0;j<10;j++)ans[i][j]=temp[i][j];
		}
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				temp[i][j]=0.0;
				for(k=0;k<10;k++){
					temp[i][j]+=(arr[i][k]*arr[k][j]);
				}
			}
		}
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)arr[i][j]=temp[i][j];
		n=n/2;
	}
	return;
}
class TheSwapsDivOne{
	public:
	double find(vector<string>v,int K){
		string s="";
		int i,j,k,n;
		for(i=0;i<v.size();i++)s=s+v[i];
		n=s.size();
		long double fin=0.0,a[10],b=2.0/(long double)n,c=2.0/(long double)(n*(n-1));
		for(i=0;i<10;i++)a[i]=0;
		for(i=0;i<n;i++)a[s[i]-'0']++;
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				ans[i][j]=arr[i][j]=0.0;
				if(i==j)ans[i][j]=1.0;
				if(a[i]==0)continue;
				if(i==j){
					arr[i][j]=(1.0-b);
					arr[i][j]+=(c*(a[i]-1));
				}
				else arr[i][j]=(c*a[j]);
			}
		}
		expo(K);
		for(i=0;i<n;i++){
			for(j=0;j<10;j++)
				fin=fin+(j*ans[s[i]-'0'][j]*(i+1)*(n-i));
		}
		fin=fin/(long double)((n*(n+1))/2);
		return fin;
	}
};
