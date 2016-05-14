/*
ID: a1lavan1
LANG: C++
TASK: subset
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 10001
using namespace std;
int main(){
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	long long i,ans,j,k=0,n,m,arr[MAX];
	fin>>n;
	for(i=0;i<MAX;i++)arr[i]=0;
	arr[0]=1;
	for(i=1,k=0;i<=n;i++,k+=i){
		for(j=k;j>=0;j--)arr[j+i]+=arr[j];
		for(j=0;j<20;j++)cout<<arr[j]<<" ";
		cout<<"\n";
	}
	ans=0;
	if((((n*(n+1))/2)&1)==0)ans=arr[(n*(n+1))/4]/2;
	fout<<ans<<"\n";
	return 0;
}