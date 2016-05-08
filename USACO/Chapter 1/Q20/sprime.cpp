/*
ID: a1lavan1
LANG: C++
TASK: sprime
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;

bool isPrime(int n){
	int i;
	if(n<2)return false;
	for( i=2;(i*i)<=n;i++)if((n%i)==0)break;
	return ((i*i)>n);
}

vector<int> ans;
void rec(int remain,int curr){
	if(remain ==0){
		ans.push_back(curr);
		return;
	}
	for(int i=1,j;i<10;i++){
		j=curr*10+i;
		if(isPrime(j))rec(remain-1,j);
	}
}

int main(){
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	long long i,j,k,n,m;
	fin>>n;
	rec(n,0);
	for(i=0;i<ans.size();i++)fout<<ans[i]<<"\n";
	return 0;
}