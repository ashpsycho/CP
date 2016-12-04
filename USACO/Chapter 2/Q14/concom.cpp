/*
ID: a1lavan1
LANG: C++
TASK: concom
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 102
using namespace std;
int main(){
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	long long i,j,k,n,m,arr[MAX][MAX],curr[MAX],vis[MAX];
	fin>>n;
	vector<T> ans;
	vector<int> v;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)arr[i][j]=0;
	for(i=0;i<n;i++){
		fin>>j>>k>>m;
		arr[j][k]=m;
	}
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			vis[j]=0;
			curr[j]=arr[i][j];
		}
		v.clear();
		while(1){
			for(j=0;j<MAX;j++){
				if(vis[j]==0 && curr[j]>50 && j!=i)break;
			}
			if(j==MAX)break;
			v.push_back(j);
			vis[j]=1;
			for(k=0;k<MAX;k++)curr[k]+=arr[j][k];
		}
		for(j=0;j<v.size();j++)ans.push_back(T(i,v[j]));
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)fout<<ans[i].x<<" "<<ans[i].y<<"\n";
	return 0;
}