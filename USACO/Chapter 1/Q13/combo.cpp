/*
ID: a1lavan1
LANG: C++
TASK: combo
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 3
using namespace std;
int main(){
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	long long i,ans=0,j,k,n,m,arr[2][MAX],l,v[3];
	fin>>n;
	for(i=0;i<2;i++)
		for(j=0;j<MAX;j++)fin>>arr[i][j];
	for(v[0]=0;v[0]<n;v[0]++){
		for(v[1]=0;v[1]<n;v[1]++){
			for(v[2]=0;v[2]<n;v[2]++){
				bool x = false;
				for(l=0;l<2;l++){
					for(m=0;m<MAX;m++)if(abs(v[m]-arr[l][m])>2 && abs(n-abs(v[m]-arr[l][m]))>2)break;
					x|= (m==MAX);
				}
				if(x==true) ans++;
			}
		}
	}
	fout<<ans<<"\n";
	return 0;
}