/*
ID: a1lavan1
LANG: C++
TASK: inflate
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 10001
using namespace std;
int main(){
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	long long i,ans,j,k,n,m,arr[MAX];
	T inp[MAX];
	fin>>n>>m;
	for(i=0;i<m;i++)fin>>inp[i].x>>inp[i].y;
	for(i=0;i<n;i++)arr[i]=0;
	for(i=0;i<m;i++){
		for(j=0;j<=(n-inp[i].y);j++)
			arr[j+inp[i].y]=max(arr[j]+inp[i].x,arr[j+inp[i].y]);
	}
	fout<<arr[n]<<"\n";
	return 0;
}