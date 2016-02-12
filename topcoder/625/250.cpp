#include <bits/stdc++.h>
using namespace std;
class PalindromePermutations{
	public:
	double palindromeProbability(string s){
		int i,j,k,n=s.size(),arr[26];
		for(i=0;i<26;i++)arr[i]=0;
		for(i=0;i<n;i++)arr[s[i]-'a']++;
		for(i=j=0;i<26;i++)j+=(1&arr[i]);
		if(j!=(n&1))return 0.0;
		long double ans=1.0;
		for(i=0;i<26 && (arr[i]&1)==0;i++);
		if(n&1){
			ans=(ans*arr[i])/(long double)n;
			n--;
			arr[i]--;
		}
		for(i=0;i<26;i++){
			for(j=1+(arr[i]/2);j<=arr[i];j++)ans=ans*j;
		}
		for(i=1+(n/2);i<=n;i++)ans/=(long double)i;
		return ans;
	}
};