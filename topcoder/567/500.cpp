#include <bits/stdc++.h>
using namespace std;
class StringGame{
	public:
	vector<int> getWinningStrings(vector<string> v){
		int i,j,n=v.size(),arr[50][26];
		vector<int>ans;
		for(i=0;i<n;i++){
			for(j=0;j<26;j++)arr[i][j]=0;
			for(j=0;j<v[i].size();j++)arr[i][v[i][j]-'a']++;
		}
		set<int>s,a,s1;
		set<int>::iterator it1,it2;
		for(i=0;i<n;i++){
			s.clear();
			a.clear();
			for(j=0;j<n;j++)if(j!=i)s.insert(j);
			for(j=0;j<26;j++)a.insert(j);
			for(j=0;j<26;j++){
				for(it1=a.begin();it1!=a.end();++it1){
					for(it2=s.begin();it2!=s.end();++it2){
						if(arr[i][(*it1)]<arr[(*it2)][(*it1)])break;
					}
					if(it2==s.end())break;
				}
				if(it1==a.end())break;
				s1.clear();
				for(it2=s.begin();it2!=s.end();++it2)if(arr[i][(*it1)]==arr[(*it2)][(*it1)])s1.insert(*it2);
				s=s1;
				a.erase(it1);
			}
			if(s.size()==0)ans.push_back(i);
		}
		return ans;
	}
};