#include<bits/stdc++.h>
#include <sstream>
using namespace std;
string to_str(int n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans;
}
class TheNumberGame{
	public:
	string determineOutcome(int a,int b){
		string s1,s2,a1="Manao wins",b1="Manao loses";
		s1=to_str(a);
		s2=to_str(b);
		if(s1.size()<s2.size())return b1;
		for(int i=0;i<=(s1.size()-s2.size());i++)if(s2==s1.substr(i,s2.size()))return a1;
		reverse(s1.begin(),s1.end());
		for(int i=0;i<=(s1.size()-s2.size());i++)if(s2==s1.substr(i,s2.size()))return a1;
		return b1;
	}
};