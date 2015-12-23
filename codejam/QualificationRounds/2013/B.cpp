#include <bits/stdc++.h>
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,inp[101][101],mi;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>m;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				fin>>inp[i][j];
			}
		}
		while(true){
			mi=101;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)mi=min(mi,inp[i][j]);
			if(mi==101)break;
			for(i=0;i<n;i++){
				k=0;
				for(j=0;j<m;j++){
					if(inp[i][j]==101)continue;
					else if(mi!=inp[i][j])break;
					else k++;
				}
				if(j==m && k>0)break;
			}
			if(i<n){
				for(j=0;j<m;j++)inp[i][j]=101;
				continue;
			}
			for(j=0;j<m;j++){
				k=0;
				for(i=0;i<n;i++){
					if(inp[i][j]==101)continue;
					else if(mi!=inp[i][j])break;
					else k++;
				}
				if(i==n && k>0)break;
			}
			if(j<m){
				for(i=0;i<n;i++)inp[i][j]=101;
				continue;
			}
			else break;

		}
		string ans=((mi==101)?"YES":"NO");
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
