/*
ID: a1lavan1
LANG: C++
TASK: prefix
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 200002
using namespace std;
int main(){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	vector<string> inp;
	string s="",s1;
	while(fin>>s1 && s1!=".")inp.push_back(s1);
	while(fin>>s1)s+=s1;
	long long i,ans=0,j,k,n,m,arr[MAX];
	n=s.size();
	for(i=0;i<=n;i++)arr[i]=0;
	arr[0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<inp.size();j++){
			if(inp[j].size()>i || (arr[i-inp[j].size()]==0))continue;
			for(k=i-inp[j].size();k<i;k++)
				if(s[k]!=inp[j][k-(i-inp[j].size())])break;
			if(k==i)arr[i]=1, ans=i;
		}
	}
	fout<<ans<<"\n";
	return 0;
}