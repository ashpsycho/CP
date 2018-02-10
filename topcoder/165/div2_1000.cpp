#include<bits/stdc++.h>
using namespace std;
string dp[25][25],s;

string tostr(char c){
	string ans="x";
	ans[0]=c;
	return ans;
}

string rec(int st,int en){
	if(st>en|| dp[st][en]!="")return dp[st][en];
	if(s[st]==s[en]){
		return dp[st][en]=""+tostr(s[st])+rec(st+1,en-1)+tostr(s[en]);
	}
	string s1=""+tostr(s[st])+rec(st+1,en)+tostr(s[st]),s2=""+tostr(s[en])+rec(st,en-1)+tostr(s[en]);
	if(s1.size()>s2.size() || (s1.size()==s2.size() && s[st]>s[en]))s1=s2;
	return dp[st][en]=s1;
}

class ShortPalindromes{
	public:
	string shortest(string S){
		s=S;
		for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
				dp[i][j]="";
			}
			dp[i][i]=s[i];
		}
		return rec(0,s.size()-1);
	}
};