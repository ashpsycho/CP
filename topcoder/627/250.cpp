#include <bits/stdc++.h>
using namespace std;
int fn(vector<int> v){
	int i,j;
	priority_queue<int>q;
	for(i=0;i<v.size();i++)q.push(v[i]);
	while(q.size()>1){
		i=q.top();
		q.pop();
		j=q.top();
		q.pop();
		i--;
		j--;
		if(i>0)q.push(i);
		if(j>0)q.push(j);
	}
	if(q.size()==1)return q.top();
	return 0;
}
class HappyLetterDiv1{
	public:
	string getHappyLetters(string s){
		int i,j,k,n=s.size(),arr[26];
		for(i=0;i<26;i++)arr[i]=0;
		for(i=0;i<n;i++)arr[s[i]-'a']++;
		vector<int>v;
		string ans="";
		for(i=0;i<26;i++){
			v.clear();
			for(j=0;j<26;j++)if(j!=i && arr[j]>0)v.push_back(arr[j]);
			if(fn(v)<arr[i])ans+=(char)('a'+i);
		}
		return ans;
	}
};