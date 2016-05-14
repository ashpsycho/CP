/*
ID: a1lavan1
LANG: C++
TASK: money
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 10001
using namespace std;
int main(){
	ifstream fin("money.in");
	ofstream fout("money.out");
	long long i,ans,j,k,n,m,arr[MAX],inp[30];
	fin>>n>>m;
	for(i=0;i<MAX;i++)arr[i]=0;
	for(i=0;i<n;i++)fin>>inp[i];
	arr[0]=1;
	for(i=0;i<n;i++){
		for(j=m;j>0;j--){
			for(k=j-inp[i];k>=0;k-=inp[i])arr[j]+=arr[k];
		}
	}
	fout<<arr[m]<<"\n";
	return 0;
}