/*
ID: a1lavan1
LANG: C++
TASK: sort3
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 1001
using namespace std;
int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	long long i,ans=0,j,k,n,m,arr[MAX],Count[3],match[3][3];
	fin>>n;
	for(i=0;i<3;i++){
		Count[i]=0;
		for(j=0;j<3;j++)match[i][j]=0;
	}
	for(i=0;i<n;i++)fin>>arr[i],arr[i]--,Count[arr[i]]++;
	for(i=1;i<3;i++)Count[i]+=Count[i-1];
	for(i=j=0;i<3;i++){
		for(;j<Count[i];j++){
			if(arr[j]==i)continue;
			match[i][arr[j]]++;
		}
	}
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			k=min(match[i][j],match[j][i]);
			ans+=k;
			match[i][j]-=k;
			match[j][i]-=k;
		}
	}
	ans+=(2*max(match[0][1],match[1][0]));
	fout<<ans<<"\n";
	return 0;
}