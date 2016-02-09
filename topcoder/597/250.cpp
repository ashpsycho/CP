#include <bits/stdc++.h>
using namespace std;
class LittleElephantAndString{
	public:
	int getNumber(string A,string B){
		string a=A,b=B;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a!=b)return -1;
		int i,j,k,n=A.size();
		for(i=0;i<n;i++){
			b=B.substr(i,(n-i));
			for(j=k=0;j<b.size() && k<A.size();k++){
				if(b[j]==A[k])j++;
			}
			if(j==b.size())break;
		}
		return i;
	}
};