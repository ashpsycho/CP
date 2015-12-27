#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 52
using namespace std;
int crypt(char c){
	if(c<='Z')return c-'A';
	else return (26)+(c-'a');
}
int main(){
	int t,te,i,j,k,n,m,ans=0,arr[MAX],check[MAX];
	cin>>n>>m;
	string w,s;
	cin>>w>>s;
	if(s.size()<w.size()){
		cout<<"0\n";
		return 0;
	}
	for(i=0;i<52;i++)arr[i]=check[i]=0;
	for(i=0;i<w.size();i++){
		arr[crypt(s[i])]++;
		check[crypt(w[i])]++;
	}
	for(i=0;i<52;i++)if(arr[i]!=check[i])break;
	if(i==52)ans++;
	for(i=w.size();i<s.size();i++)
	{
		arr[crypt(s[i])]++;
		arr[crypt(s[i-(w.size())])]--;
		for(j=0;j<52;j++)if(arr[j]!=check[j])break;
		if(j==52)ans++;
	}
	cout<<ans<<"\n";
	return 0;
}