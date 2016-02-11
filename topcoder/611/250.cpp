#include <bits/stdc++.h>
using namespace std;
vector<int> red(vector<int> v){
	int i,j,k,n=v.size();
	sort(v.begin(),v.end());
	for(i=n-1;i>=0;i--){
		for(j=0,k=1;j<i;j++){
			if((v[i]%v[j])==0)k=k*(v[j]/__gcd(k,v[j]));
		}
		if(k==v[i])v.erase(v.begin()+i);
	}
	return v;
}
class LCMSet{
	public:
	string equal(vector<int> A,vector<int> B){
		int i;
		A=red(A);
		B=red(B);
		string s1="Equal", s2="Not equal";
		if(A.size()!=B.size())return s2;
		for(i=0;i<A.size();i++)if(A[i]!=B[i])break;
		return (i==A.size())?s1:s2;
	}
};