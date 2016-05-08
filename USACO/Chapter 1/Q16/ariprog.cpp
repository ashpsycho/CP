/*
ID: a1lavan1
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 130001
using namespace std;
int main(){
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	static int i,j,k,n,m,arr[MAX],a,d;
	fin>>n>>m;
	set<int> s;
	vector<int>v;
	set<int> :: iterator it;
	for(i=0;i<MAX;i++)arr[i]=0;
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			s.insert(i*i+j*j),arr[i*i+j*j]=1;
		}
	}
	for(it=s.begin();it!=s.end();++it)v.push_back(*it);
	vector<T> ans;
	for(i=0;i<v.size();i++){
		for(j=i+1;j<v.size();j++){
			if(((v[j]-v[i])%(n-1))!=0)continue;
			for(k=1,a=v[i],d=(v[j]-v[i])/(n-1);k<(n-1);k++)
				if(arr[a+(k*d)]==0)break;
			if(k==(n-1))ans.push_back(T(d,a));
		}
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)fout<<ans[i].y<<" "<<ans[i].x<<"\n";
	if(ans.size()==0)fout<<"NONE\n";
	return 0;
}