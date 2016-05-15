/*
ID: a1lavan1
LANG: C++
TASK: fact4
*/
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");
	long long i,ans=1,j,k,n,m,arr[MAX];
	fin>>n;
	for(i=1;i<=n;i++)arr[i]=i;
	for(i=1,j=0;i<=n;i++){
		while((arr[i]%5)==0){
			arr[i]/=5;
			j++;
		}
	}
	for(i=1;j>0 && i<=n;i++){
		while((arr[i]%2)==0 &&  j>0){
			j--;
			arr[i]/=2;
		}
	}
	for(i=1;i<=n;i++)ans=(ans*arr[i])%10;
	fout<<ans<<"\n";
	return 0;
}