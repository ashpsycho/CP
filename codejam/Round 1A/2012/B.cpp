#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long tot,t,te,i,j,k,n,m,ans,need[1001][2],cur[1001];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		for(i=0;i<n;i++){
			cur[i]=0;
			fin>>need[i][0]>>need[i][1];
		}
		for(ans=tot=0;;ans++){
			for(i=0;i<n;i++)if(cur[i]!=2)break;
			if(i==n)break;
			for(i=0;i<n;i++){
				if(cur[i]<2 && need[i][1]<=tot)break;
			}
			if(i<n){
				tot+=(2-cur[i]);
				cur[i]=2;
				continue;
			}
			for(i=0,j=-1;i<n;i++){
				if(cur[i]==0 && need[i][0]<=tot){
					if(j==-1)j=i;
					if(need[i][1]>need[j][1])j=i;
				}
			}
			if(j!=-1){
				tot+=1;
				cur[j]=1;
			}
			else break;
		}
		for(i=0;i<n;i++)if(cur[i]!=2)break;
		if(i<n){
			fout<<"Case #"<<(te+1)<<": Too Bad"<<"\n";
			cout<<"Case #"<<(te+1)<<": Too Bad"<<"\n";
			continue;		
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
