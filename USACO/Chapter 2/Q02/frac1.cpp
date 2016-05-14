/*
ID: a1lavan1
LANG: C++
TASK: frac1
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;

bool fn(T a, T b){
	return ((a.x*b.y)<(a.y*b.x));
}

int main(){
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	long long i,ans,j,k,n,m;
	fin>>n;
	vector<T> v;
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			if(__gcd(i,j)!=1)continue;
			v.push_back(T(j,i));
		}
	}
	sort(v.begin(),v.end(),fn);
	for(i=0;i<v.size();i++)fout<<v[i].x<<"/"<<v[i].y<<"\n";
	return 0;
}