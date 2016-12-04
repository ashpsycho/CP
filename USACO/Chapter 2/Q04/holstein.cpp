/*
ID: a1lavan1
LANG: C++
TASK: holstein
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 25
using namespace std;
int main(){
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	long long i,ans,j,k,n,m,arr[MAX], req[25],inp[15][25],po,po2[30],cur[25],x;
	po2[0]=1;
	for(i=1;i<30;i++)po2[i]=2*po2[i-1];
	fin>>n;
	for(i=0;i<n;i++)fin>>req[i];
	fin>>m;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)fin>>inp[i][j];
	}
	for(i=1;i<=m;i++){
		for(j=0,po=(1<<m);j<po;j++){
			if(__builtin_popcount(j)!=i)continue;
			for(x=0;x<n;x++)cur[x]=0;
			for(k=0;k<m;k++){
				if((j&po2[k])==0)continue;
				for(x=0;x<n;x++)cur[x]+=inp[k][x];
			}
			for(x=0;x<n;x++)if(cur[x]<req[x])break;
			if(x==n)break;
		}
		if(j<po)break;
	}
	fout<<__builtin_popcount(j)<<" ";
	for(i=0;i<=m;i++){
		if((j&po2[i])){
			fout<<(i+1);
			j=j-po2[i];
			fout<<((j==0)?'\n':' ');
		}
	}
	return 0;
}