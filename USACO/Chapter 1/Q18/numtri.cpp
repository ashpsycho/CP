/*
ID: a1lavan1
LANG: C++
TASK: numtri
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 1001
using namespace std;
int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	static int i,last=0,j,k,n,m,arr[MAX][MAX],ans[MAX][MAX];                   
	fin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++){
			fin>>arr[i][j];
			ans[i][j]=arr[i][j];
		}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(i!=0)ans[i][j]=max(ans[i][j],arr[i][j]+ans[i-1][j]);
			if(j!=0)ans[i][j]=max(ans[i][j],arr[i][j]+ans[i-1][j-1]);
			last = max(last,ans[i][j]);
		}
	}
	fout<<last<<"\n";
	return 0;
}