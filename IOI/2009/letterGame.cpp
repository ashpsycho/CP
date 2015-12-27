#include <bits/stdc++.h>
#define T pair<string,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,allcount[26],coun[26],scores[26],ans=0;
	string cs="qwertyuiopasdfghjklzxcvbnm";
	string score="76122541352146557637746525";
	for(i=0;i<26;i++)scores[cs[i]-'a']=score[i]-'0';
	vector<string> inp;
	string s,s1,s2,all;
	while(cin>>s && s!=".")inp.push_back(s);
	n=inp.size();
	sort(inp.begin(),inp.end());
	vector<T> arr;
	for(i=0;i<inp.size();i++){
		arr.push_back(T(inp[i],i));
		sort(arr[i].x.begin(),arr[i].x.end());
	}
	vector<string> brr;
	sort(arr.begin(),arr.end());
	for(i=0;i<n;i++)brr.push_back(arr[i].x);
	cin>>all;
	for(i=0;i<26;i++)allcount[i]=0;
	for(i=0;i<all.size();i++)allcount[all[i]-'a']++;
	for(i=0;i<n;i++){
		for(j=0;j<26;j++)coun[j]=0;
		for(j=0;j<brr[i].size();j++)coun[brr[i][j]-'a']++;
		for(j=0;j<26;j++){
			if(coun[j]>allcount[j])break;
		}
		if(j<26)continue;
		for(j=k=0;j<26;j++)k+=(coun[j]*scores[j]);
		ans=max(ans,k);
		s="";
		for(j=0;j<26;j++)
			for(k=coun[j];k<allcount[j];k++)s=s+(char)('a'+j);
		for(j=1,te=(1<<(int)s.size());j<te;j++){
			s1="";
			for(k=1,t=0;k<te;k*=2,t++){
				if(j&k)s1+=s[t];
			}
			t=lower_bound(brr.begin(),brr.end(),s1)-brr.begin();
			if(t>=brr.size()||brr[t]!=s1)continue;
			for(t=0,k=0;k<brr[i].size();k++)t+=scores[brr[i][k]-'a'];
			for(k=0;k<s1.size();k++)t+=scores[s1[k]-'a'];
			ans=max(ans,t);	
		}
	}
	vector<string> fin;
	for(i=0;i<n;i++){
		for(j=0;j<26;j++)coun[j]=0;
		for(j=k=0;j<inp[i].size();j++)k+=scores[inp[i][j]-'a'],coun[inp[i][j]-'a']++;
		for(j=0;j<26;j++)if(coun[j]>allcount[j])break;
		if(j<26)continue;
		if(k==ans){
			fin.push_back(inp[i]);
			continue;
		}
		s="";
		for(j=0;j<26;j++)
			for(k=coun[j];k<allcount[j];k++)s=s+(char)('a'+j);
		for(j=1,te=(1<<(int)s.size());j<te;j++){
			s1="";
			for(k=1,t=0;k<te;k*=2,t++){
				if(j&k)s1+=s[t];
			}
			t=lower_bound(brr.begin(),brr.end(),s1)-brr.begin();
			if(t>=brr.size()||brr[t]!=s1)continue;
			for(t=0,k=0;k<inp[i].size();k++)t+=scores[inp[i][k]-'a'];
			for(k=0;k<s1.size();k++)t+=scores[s1[k]-'a'];
			if(t!=ans)continue;
			t=lower_bound(brr.begin(),brr.end(),s1)-brr.begin();
			te=upper_bound(brr.begin(),brr.end(),s1)-brr.begin();
			for(k=t;k<te;k++){
				if(i<=arr[k].y)continue;
				if(arr[k].x!=arr[t].x)continue;
				s2=min(inp[i],inp[arr[k].y])+" "+max(inp[i],inp[arr[k].y]);
				fin.push_back(s2);
			}
		}
	}
	cout<<ans<<"\n";
	sort(fin.begin(),fin.end());
	for(i=0;i<fin.size();i++)cout<<fin[i]<<"\n";
	return 0;
}