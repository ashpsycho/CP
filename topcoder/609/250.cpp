#include <bits/stdc++.h>
using namespace std;
class MagicalStringDiv1{
	public:
	int getLongest(string s){
		int i,j,k,n=s.size();
		string s1;
		for(k=25;k>=0;k--){
			s1="";
			for(j=0;j<k;j++)s1=s1+">";
			for(j=0;j<k;j++)s1=s1+"<";
			for(i=j=0;i<n && j<s1.size();i++){
				if(s[i]==s1[j])j++;
			}
			if(j==s1.size())break;
		}
		return 2*k;
	}
};