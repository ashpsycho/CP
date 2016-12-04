/*
ID: a1lavan1
LANG: C++
TASK: nuggets
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("nuggets.in");
	ofstream fout("nuggets.out");
	long long i,ans,j,k,n,m,inp[10],arr[MAX];
	fin>>n;
	for(i=j=0;i<n;i++){
		fin>>inp[i];
		j=__gcd(j,inp[i]);
	}
	sort(arr,arr+n);
	if(j!=1 || arr[0]==1){
		fout<<"0\n";
		return 0;
	}
	for(i=0;i<MAX;i++)arr[i]=0;
	arr[0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<(MAX-inp[i]);j++){
			if(arr[j]==1)arr[j+inp[i]]=1;
		}
	}
	for(k=i=0;i<MAX;i++)if(arr[i]==0)k=i;
	fout<<k<<"\n";
	return 0;
}