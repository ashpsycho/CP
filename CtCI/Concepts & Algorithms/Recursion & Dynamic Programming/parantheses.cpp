#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,sum;
	cout<<"Enter no of parantheses\n";
	cin>>n;
	vector<string> ans[n+1];
	ans[1].push_back("()");
	for(i=1;i<n;i++){
		for(j=0;j<ans[i].size();j++){
			for(k=sum=0;k<ans[i][j].size();k++){
				if(sum==0){
					ans[i+1].push_back("("+ans[i][j].substr(0,k)+")"+ans[i][j].substr(k,ans[i][j].size()-k));
				}
				if(ans[i][j][k]=='(')sum++;
				else sum--;
			}
			ans[i+1].push_back("("+ans[i][j]+")");
		}
	}
	for(i=0;i<ans[n].size();i++)cout<<ans[n][i]<<"\n";
}