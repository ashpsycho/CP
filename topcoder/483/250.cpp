#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string to_str(int n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	while(ans.size()<6)ans="0"+ans;
	return ans;
}
string to_s(int n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans;
}
int lcp(string a,string b){
	int ans=0;
	for(;ans<6&&a[ans]==b[ans];ans++);
	return ans;
}
class BestApproximationDiv1{
	public:
	string findFraction(int maxD,string s){
		s=s.substr(2,6);
		int i,j,k,num=0,den=1,curr=0;
		for(i=1;i<=maxD;i++)
			for(j=0;j<i;j++){
				k=(1000000*j)/i;
				k=lcp(s,to_str(k));
				if(k>curr){
					curr=k;
					num=j;
					den=i;
				}
			}
		return to_s(num)+"/"+to_s(den)+" has "+to_s(curr+1)+" exact digits";
	}
};