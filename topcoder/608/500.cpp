#include <bits/stdc++.h>
using namespace std;
long double g[50][50];
int n;
long double calc(int exp){
	long double ans=0.0,arr[n][n],temp[n][n],mult[n][n];
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)arr[i][j]=0.0,mult[i][j]=g[i][j];
		arr[i][i]=1.0;
	}
	while(exp>0){
		if(exp&1){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					temp[i][j]=0.0;
					for(k=0;k<n;k++)
						temp[i][j]=temp[i][j]+ (arr[i][k]*mult[k][j]);
				}
			}
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)arr[i][j]=temp[i][j];
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp[i][j]=0.0;
				for(k=0;k<n;k++)
					temp[i][j]=temp[i][j]+(mult[i][k]*mult[k][j]);
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)mult[i][j]=temp[i][j];
		exp/=2;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)ans+=arr[i][j];
	return ans;
}
class BigO{
	public:
	int minK(vector<string> G){
		n=G.size();
		int i,j,k;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)g[i][j]=(G[i][j]=='Y')?1.0:0.0;
		long double a=calc(1000),b=calc(2000),c=(b/a);
		if(abs(b-a)<1.0)c=1.0;
		if(c>(powl(2.0,60.0)))return -1;
		return (int)roundl(log2(c));
	}
};