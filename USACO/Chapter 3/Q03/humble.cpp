/*
ID: a1lavan1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h> 
#define MAX 101
using namespace std;
int main(){
	ifstream fin("humble.in");
	ofstream fout("humble.out");
	static long long i,ans,j,k,n,m,x,arr[MAX],curr[MAX];
	fin>>m>>n;
	for(i=0;i<m;i++)fin>>arr[i];
	sort(arr,arr+m);
	vector<int> v;
	v.push_back(1);
	for(i=0;i<m;i++)curr[i]=0;
	for(i=0;i<n;i++){
		for(k=j=0;j<m;j++){
			while(v[i]>=(arr[j]*v[curr[j]]))curr[j]++;
			if((arr[j]*v[curr[j]])<(arr[k]*v[curr[k]]))
				k=j;
		}
		v.push_back(arr[k]*v[curr[k]]);
		curr[k]++;
	}
	fout<<v[n]<<"\n";
	return 0;
}