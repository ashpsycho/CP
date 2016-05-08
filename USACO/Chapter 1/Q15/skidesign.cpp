/*
ID: a1lavan1
LANG: C++
TASK: skidesign
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	long long i,ans=100000000,j,k,n,m,arr[MAX];
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i];
	for(i=0;i<=(83);i++){
		j=i+17;
		k=0;
		for(m=0;m<n;m++){
			if(arr[m]<i)k+=((i-arr[m])*(i-arr[m]));
			if(arr[m]>j)k+=((j-arr[m])*(j-arr[m]));
		}
		ans=min(ans,k);
	}
	fout<<ans<<"\n";
	return 0;
}