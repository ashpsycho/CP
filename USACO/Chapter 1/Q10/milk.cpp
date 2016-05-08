/*
ID: a1lavan1
LANG: C++
TASK: milk
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	long long i,ans=0,j,k,n,m;
	T arr[MAX];
	fin>>m>>n;
	for(i=0;i<n;i++)fin>>arr[i].x>>arr[i].y;
	sort(arr,arr+n);
	for(i=j=0;i<n && j<m;i++){
		ans+=(arr[i].x*min(m-j,arr[i].y));
		j+=arr[i].y;
	}
	fout<<ans<<"\n";
	return 0;
}