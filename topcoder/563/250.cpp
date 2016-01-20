#include <bits/stdc++.h>
using namespace std;
class FoxAndHandle{
	public:
	string lexSmallestName(string s){
		int i,j,k,n=s.size(),Count[26],b[26],a[26],b1[26],a1[26];
		for(i=0;i<26;i++)Count[i]=a[i]=b[i]=0;
		for(i=0;i<n;i++)Count[s[i]-'a']++;
		string ans="";
		for(i=0;i<n;i++){
			k=s[i]-'a';
			if(a[k]==(Count[k]/2)){
				b[k]++;
				continue;
			}
			if(b[k]==(Count[k]/2)){
				a[k]++;
				ans+=s[i];
				continue;
			}
			for(j=0;j<26;j++)a1[j]=a[j],b1[j]=b[j];
			for(j=i;j<n;j++){
				if(a[s[j]-'a']==(Count[s[j]-'a']/2))continue;
				if(s[j]<s[i])break;
				else{
					if(b1[s[j]-'a']==(Count[s[j]-'a']/2)){
						j=n;
						break;
					}
					b1[s[j]-'a']++;
				}
			}
			if(j==n){
				ans+=s[i];
				a[k]++;
			}
			else{
				b[k]++;
			}
		}
		return ans;
	}
};