/*
ID: a1lavan1
LANG: C++
TASK: lamps
*/
#include <bits/stdc++.h> 
#define MAX 10001
using namespace std;
int arr[MAX], check[MAX],n;
void toggle(int beg,int inc){
	for(int i=beg;i<n;i+=inc)arr[i]=(3-arr[i]);
}
int main(){
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	long long i,j,k,tot=0;
	fin>>n>>k;
	for(i=0;i<n;i++)arr[i]=1,check[i]=3;
	while(fin>>i && i!=-1)check[i-1]=1;
	while(fin>>i && i!=-1)check[i-1]=2;
	vector<string> ans;
	string s;
	for(i=0;i<n;i++)s+='a';
	for(i=0;i<16;i++){
		if((k<__builtin_popcount(i))||(k&1)!=(1&__builtin_popcount(i)))continue;
		cout<<i<<"\n";
		for(j=0;j<n;j++)arr[j]=1;
		if((i&1))toggle(0,1);
		if((i&2))toggle(0,2);
		if((i&4))toggle(1,2);
		if((i&8))toggle(0,3);
		for(j=0;j<n;j++)if((arr[j]&check[j])==0)break;
		if(j<n)continue;
		tot++;
		for(j=0;j<n;j++)s[j]='0'+(2-arr[j]);
		ans.push_back(s);
	}
	if(tot==0)fout<<"IMPOSSIBLE\n";
	sort(ans.begin(),ans.end());
	for(i=0;i<tot;i++)fout<<ans[i]<<"\n";
	return 0;
}