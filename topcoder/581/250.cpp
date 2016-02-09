#include <bits/stdc++.h>
using namespace std;
class SurveillanceSystem{
	public:
	string getContainerInfo(string s,vector<int> v,int L){
		int i,j,k,n=s.size(),coun[50][51],a[51],arr[51];
		string ans;
		for(i=0;i<51;i++)a[i]=arr[i]=0;
		for(i=0;i<n;i++)ans=ans+"-";
		for(i=0;i<50;i++)
			for(j=0;j<51;j++)coun[i][j]=0;
		for(i=0;i<=(n-L);i++){
			for(j=k=0;j<L;j++)if(s[i+j]=='X')k++;
			for(j=0;j<L;j++)coun[i+j][k]++;
			arr[k]++;
		}
		for(i=0;i<v.size();i++)a[v[i]]++;
		for(i=0;i<51;i++){
			if(a[i]==0)continue;
			for(j=0;j<n;j++){
				if(coun[j][i]>0 && ans[j]!='+')ans[j]='?';
				if((arr[i]-coun[j][i])<a[i])ans[j]='+';
			}
		}
		return ans;
	}
};