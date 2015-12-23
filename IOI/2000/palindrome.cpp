#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int lcs(string a,string b){
	int n=a.size(),i,j,k=0,arr[2][n+1];
	for(i=0;i<2;i++)
		for(j=0;j<=n;j++)arr[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j])arr[1][j+1]=1+arr[0][j];
			else arr[1][j+1]=max(arr[0][j+1],arr[1][j]);
			k=max(k,arr[1][j+1]);
		}
		for(j=0;j<=n;j++){
			arr[0][j]=arr[1][j];
			arr[1][j]=0;
		}
	}
	return k;
}
int main(){
	int t,te,i,j,k,n,m,ans,arr[MAX];
	cin>>n;
	string s;
	cin>>s;
	string s1=s;
	reverse(s1.begin(),s1.end());
	j=lcs(s,s1);
	cout<<(n-j);
	return 0;
}
