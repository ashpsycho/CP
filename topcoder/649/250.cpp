#include <bits/stdc++.h>
using namespace std;
class Decipherability{
	public:
	string check(string s,int K){
		int i,j,n=s.size();
		if(K==s.size())return "Certain";
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++){
				if(s[i]!=s[j])continue;
				if(K>=(j-i))return "Uncertain";
			}
		
		return "Certain";
	}	
};