#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 10001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,arr[MAX],moves,check[MAX],xora[MAX][4];
	cin>>n>>moves;
	for(i=0;i<n;i++)check[i]=-1,arr[i]=0;
	while(cin>>i && i!=-1)check[i-1]=1;
	while(cin>>i && i!=-1)check[i-1]=0;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)xora[i][j]=0;
	for(i=0;i<n;i++){
		if(i&1)xora[i][0]=1;
		else xora[i][1]=1;
		xora[i][2]=1;
		if((i%3)==0)xora[i][3]=1;
	}
	vector<string>ans;
	string s;
	for(i=0;i<16;i++){
		for(j=0;j<n;j++)arr[j]=1;
		if(__builtin_popcount(i)>moves)continue;
		if((__builtin_popcount(i)%2)!=(moves%2))continue;
		for(j=1,m=0;j<16;j*=2,m++){
			if((j&i)!=0)
				for(k=0;k<n;k++)arr[k]^=xora[k][m];
		}
		for(j=0;j<n;j++){
			if(check[j]==-1)continue;
			if(check[j]!=arr[j])break;
		}
		if(j<n)continue;
		s="";
		for(j=0;j<n;j++)s+=(char)('0'+arr[j]);
		ans.push_back(s);
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)cout<<ans[i]<<"\n";
	if(ans.size()==0)cout<<"IMPOSSIBLE\n";
	return 0;
}