#include <bits/stdc++.h>
using namespace std;
class PalindromicSubstringsDiv1{
	public:
	double expectedPalindromes(vector<string> S1,vector<string> S2){
		string s1="",s2="",s;
		int i,j,k;
		for(i=0;i<S1.size();i++)s1+=S1[i];
		for(i=0;i<S2.size();i++)s2+=S2[i];
		s=s1+s2;
		int n=s.size();
		static double dp[5001][5001],ans=0.0;
		for(i=0;i<5001;i++)
			for(j=0;j<5001;j++)dp[i][j]=0.0;
		for(i=0;i<5001;i++)dp[i][0]=dp[i][1]=1.0;
		for(i=1;i<n;i++){
			for(j=i-1,k=2;j>=0;j--,k++){
				if(s[i]!='?' && s[j]!='?'){
					if(s[i]==s[j])dp[i][k]=dp[i-1][k-2];
				}
				else
					dp[i][k]=(dp[i-1][k-2])/26.0;
			}
		}
		for(i=0;i<n;i++)
			for(j=1;j<=n;j++)ans+=dp[i][j];
		return ans;
	}
};