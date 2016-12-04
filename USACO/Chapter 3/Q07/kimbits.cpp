/*
ID: a1lavan1
LANG: C++
TASK: kimbits
*/
#include <bits/stdc++.h> 
#define MAX 32
using namespace std;
long long i,j,k,n,m,arr[MAX][MAX],K;
string ans="";
void rec(int n,int m,int K){
	if(K==0){
		for(int i=0;i<n;i++)ans+="0";
		return;
	}
	K--;
	for(i=1;i<=n;i++){
		for(j=0,k=K;j<m && j<i;j++){
			if(arr[i-1][j]>k)break;
			k-=arr[i-1][j];
		}
		if(j<m && j<i)break;
		K=k;
	}
	for(j=0;j<(n-(i));j++)ans+="0";
	ans+="1";
	rec(i-1,m-1,K);
}
int main(){
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			arr[i][j]=0;
		}
	}
	// PRECOMPUTATION TIME
	arr[0][0]=1;
	for(i=1;i<MAX;i++){
		arr[i][0]=1;
		for(j=1;j<=i;j++)
			arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
	}
	fin>>n>>m>>K;
	rec(n,m,K-1);
	fout<<ans<<"\n";
	return 0;
}