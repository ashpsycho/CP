/*
ID: a1lavan1
LANG: C++
TASK: crypt1
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 11
long long i,ans=0,j,k,n,m,arr[MAX],v[5],a,b;
using namespace std;
bool check(int N){
	for(;N>0;N/=10){
		for(i=0;i<n;i++)if(arr[i]==(N%10))break;
		if(i==n)return false;
	}
	return true;
}
int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i];
	for(v[0]=0;v[0]<n;v[0]++)
		for(v[1]=0;v[1]<n;v[1]++)
			for(v[2]=0;v[2]<n;v[2]++)
				for(v[3]=0;v[3]<n;v[3]++)
					for(v[4]=0;v[4]<n;v[4]++){
						a=100*arr[v[0]]+10*arr[v[1]]+arr[v[2]];
						b=10*arr[v[3]]+arr[v[4]];
						if((a*arr[v[3]])>999 || !check(a*arr[v[3]]))continue;
						if((a*arr[v[4]])>999 || !check(a*arr[v[4]]))continue;
						if((a*b)>9999 || !check(a*b))continue;
						ans++;
					}	
	fout<<ans<<"\n";
	return 0;
}