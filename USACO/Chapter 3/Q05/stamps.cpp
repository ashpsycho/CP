/*
ID: a1lavan1
LANG: C++
TASK: stamps
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 2100001
using namespace std;
int main(){
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	static int i,ans,j,K,k,n,m,arr[MAX],inp[50],tot=0,used;
	static bool isp[MAX];
	for(i=0;i<MAX;i++)arr[i]=10000,isp[i]=0;
	fin>>K>>n;
	for(i=0;i<n;i++)fin>>inp[i];
	isp[0]=1;
	arr[0]=0;
	sort(inp, inp+n);
	for(i=1;i<MAX;i++){
		for(j=0;j<n && inp[j]<=i;j++){
			if(isp[i-inp[j]]==0 || arr[i-inp[j]]==K)continue;
			isp[i]=1;
			arr[i]=min(arr[i],1+arr[i-inp[j]]);
		}
	}
	for(i=0;i<MAX;i++)if(isp[i]==0)break;
	fout<<(i-1)<<"\n";
	return 0;
}