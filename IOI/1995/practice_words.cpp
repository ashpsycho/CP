#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 700001
using namespace std;
int main(){
	static int t,te,i=0,j,k,n,m,ans[MAX],len[MAX],fin,finle=0;
	string s;
	vector<string> arr;
	while(cin>>s && s!="."){
		i++;
		arr.push_back(s);
		for(j=i-2;j>=0 && arr[j][0]==arr[i-1][0];j--){
			if(arr[j]==arr[i-1].substr(0,arr[j].size()))break;
		}
		if(j<0 || arr[j][0]!=arr[i-1][0])len[i-1]=1,ans[i-1]=-1;
		else ans[i-1]=j,len[i-1]=1+len[j];
		if(len[i-1]>finle){
			finle=len[i-1];
			fin=i-1;
		}
	}
	vector<string> v;
	for(i=fin;i!=-1;i=ans[i]){
		v.push_back(arr[i]);
	}
	reverse(v.begin(),v.end());
	for(i=0;i<v.size();i++)cout<<v[i]<<"\n";
	return 0;
}