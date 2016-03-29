#include <bits/stdc++.h>
using namespace std;
class Unique{
	public:
	string removeDuplicates(string s){
		int i,n=s.size(),j;
		for(i=n-1;i>=0;i--){
			for(j=0;j<i;j++)if(s[i]==s[j])break;
			if(j<i)s.erase(s.begin()+i);
		}
		return s;
	}
};