/*
ID: a1lavan1
LANG: C++
TASK: hamming
*/
#include <bits/stdc++.h> 
using namespace std;

vector<int> intersect(vector<int> a,vector<int> b){
	//sort(a.begin(),a.end());
	//sort(b.begin(),b.end());
	vector<int> ans;
	for(int i=0,j=0;i<a.size() && j<b.size();){
		if(a[i]<b[j])i++;
		else {
			if(a[i]==b[j])ans.push_back(a[i]);
			j++;
		}
	}
	return ans;
}

int main(){
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	long long i,j,k,n,b,d, vis[500],tot;
	fin>>n>>b>>d;
	tot=(1<<b);
	vector<int> adj[500];
	//Calculate neighbours for all
	for(i=0;i<tot;i++){
		for(j=0;j<tot;j++){
			if(__builtin_popcount(i^j)>=d)adj[i].push_back(j);
		}
	}
	for(i=0;i<500;i++)vis[i]=0;
	//Insert 0
	vector<int> ans,curr=adj[0];
	ans.push_back(0);
	n--;
	while(n>0){
		j=curr[0];
		curr.erase(curr.begin());
		curr=intersect(curr,adj[j]);
		n--;
		ans.push_back(j);
	}
	for(i=0;i<ans.size();i++){
		fout<<ans[i];
		if(i==(ans.size()-1) || (i%10)==9)fout<<'\n';
		else fout<<" ";
	}
	return 0;
}