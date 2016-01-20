#include <bits/stdc++.h>
using namespace std;
bool isp(vector<string> cub,string s){
	int i,j,n=s.size(),m=cub.size(),check[m][26],arr[m];
	if(n>m)return 0;
	for(i=0;i<m;i++)
		for(j=0;j<26;j++)check[i][j]=0;
	for(i=0;i<m;i++)
		for(j=0;j<cub[i].size();j++)check[i][cub[i][j]-'A']=1;
	for(i=0;i<m;i++)arr[i]=i;
	do{
		for(i=0;i<n;i++){
			if(check[arr[i]][s[i]-'A']==0)break;
		}
		if(i==n)return 1;
	}while(next_permutation(arr,arr+m));
	return 0;
}
class PlayingCubes{
	public:
	vector<int> composeWords(vector<string> cub,vector<string> w){
		int i,n=w.size();
		vector<int>ans;
		for(i=0;i<n;i++){	
			if(isp(cub,w[i]))ans.push_back(i);
		}
		return ans;
	}
};