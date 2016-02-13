#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i,j,k,n=s.size(),ans=0,x,y;
	for(i=0;i<n;i++){
		for(j=1;(j+i)<=n;j++){
			for(k=x=y=0;k<j;k++){
				if(s[i+k]=='U')x++;
				if(s[i+k]=='D')x--;
				if(s[i+k]=='L')y++;
				if(s[i+k]=='R')y--;
			}
			if(x==0 && y==0)ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}