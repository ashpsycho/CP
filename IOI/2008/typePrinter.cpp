#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,k1,m1,arr[MAX],curr;
	cin>>n;
	static string inp[25000],inp1[25000];
	for(i=0;i<n;i++)cin>>inp[i];
	sort(inp,inp+n);
	while(true){
		for(i=j=0;i<n;i++)if(inp[i].size() >=inp[j].size())j=i;
		if(j==(n-1))break;
		for(k=0;k<inp[j].size() && k<inp[j+1].size() && inp[j][k]==inp[j+1][k];k++);
		for(m=j-1;m>=0;m--){
			for(k1=0;k1<inp[j].size() && k1<inp[m].size() && inp[j][k1]==inp[m][k1];k1++);
			if(k1<=k)break;
		}
		for(m1=j+1;m1<n;m1++){
			for(k1=0;k1<inp[j].size() && k1<inp[m1].size() && inp[j][k1]==inp[m1][k1];k1++);
			if(k1<k)break;
		}
		for(i=curr=0;i<=m;i++,curr++)inp1[curr]=inp[i];
		for(i=j+1;i<m1;i++,curr++)inp1[curr]=inp[i];
		for(i=m+1;i<=j;i++,curr++)inp1[curr]=inp[i];
		for(i=m1;i<n;i++,curr++)inp1[curr]=inp[i];
		for(i=0;i<n;i++)inp[i]=inp1[i];
	}
	vector<char>ans;
	for(i=k=0;i<n;i++){
		if(i!=0){
			for(j=0;j<inp[i].size() && j<inp[i-1].size() && inp[i][j]==inp[i-1][j];j++);
			for(k=j;j<inp[i-1].size();j++)ans.push_back('-');
		}
		for(;k<inp[i].size();k++)ans.push_back(inp[i][k]);
		ans.push_back('P');
	}
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();i++)cout<<ans[i]<<"\n";
	return 0;
}