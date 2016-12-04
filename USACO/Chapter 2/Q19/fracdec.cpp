/*
ID: a1lavan1
LANG: C++
TASK: fracdec
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
stringstream mid;
vector<int> v;
void print(){
	char c;
	int i;
	for( i=0;mid>>c;i++){
		fout<<c;
		if((i%76)==75)fout<<"\n";
	}
	if((i%76)!=0)fout<<"\n";
}
int main(){
	long long i,ans,j,k,n,m,arr[MAX];
	static int vis[100000][10];
	fin>>n>>m;
	for(i=0;i<100000;i++)
		for(j=0;j<10;j++)vis[i][j]=0;
	mid<<(n/m)<<".";
	n=(n%m);
	if(n==0){
		mid<<"0";
		print();
		return 0;
	}
	i=0;
	while(n!=0){
		n=(n*10);
		if(vis[n%m][n/m]>0)break;
		vis[n%m][n/m]=i+1;
		v.push_back(n/m);
		i++;
		n=(n%m);
	}
	i=0;
	if(n!=0){
		for(;i<(vis[n%m][n/m]-1);i++)
			mid<<v[i];
		mid<<"(";
	}
	for(;i<v.size();i++)mid<<v[i];
	if(n!=0)mid<<")";
	print();
	return 0;
}