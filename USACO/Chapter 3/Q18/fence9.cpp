/*
ID: a1lavan1
LANG: C++
TASK: fence9
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("fence9.in");
	ofstream fout("fence9.out");
	long double i,j,k,n,m,p;
	fin>>n>>m>>p;
	long long ans=0;
	for(i=1;i<m;i+=1.0){
		j=roundl(floorl((n*i)/m ));
		k=roundl(ceill((p*m+(n-p)*i)/m ));
		if(k!=j)ans+=(k-(j+1));
	}
	fout<<(long long)ans<<"\n";
	cout<<(long long)ans<<"\n";
	return 0;
}