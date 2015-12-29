#include <bits/stdc++.h>
using namespace std;
class PenguinPals{
	public:
	int findMaximumMatching(string s){
		int i,j,k,n=s.size(),ans=0;
		if(n==0)return 0;
		for(i=1;i<n;i++)if(s[i]==s[i-1])break;
		if(i==n)return (n-1)/2;
		for(i=0;i<n && s[i]==s[0];i++);
		if(i==n)return (n/2);
		string s1="";
		for(j=k=0;k<n;k++,i=(i+1)%n){
			j++;
			if(s[i]!=(s[(i+1)%n])){
				ans+=(j/2);
				if(j&1)s1+=s[i];
				j=0;
			}
		}
		return ans+findMaximumMatching(s1);
	}
};