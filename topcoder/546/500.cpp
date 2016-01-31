#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string to_str(long long N){
	stringstream fin;
	fin<<N;
	string ans;
	fin>>ans;
	return ans;
}
long long toLL(string s){
	stringstream fin;
	fin<<s;
	long long ans;
	fin>>ans;
	return ans;
}
bool isp(string s,int d1,int c1,int d2,int c2){
	int i,n=s.size();
	if((c1+c2)>n)return 0;
	string s1="";
	for(i=0;i<(n-(c1+c2));i++)s1+="9";
	for(i=0;i<c1;i++)s1+=(char)('0'+d1);
	for(i=0;i<c2;i++)s1+=(char)('0'+d2);
	return (toLL(s1)>=toLL(s));
}
class FavouriteDigits{
	public:
	long long findNext(long long N,int d1,int c1,int d2,int c2){
		if(d1<d2){
			swap(d1,d2);
			swap(c1,c2);
		}
		string s=to_str(N),s1;
		while(s.size()<17)s="0"+s;
		int i,j,k,m,n=s.size(),lo[n],nonz=0;
		for(i=0;i<n;i++)lo[i]=s[i]-'0';
		for(i=0;i<n;i++){
			for(j=lo[i];j<10;j++){
				s[i]='0'+j;
				if(j>lo[i])
					for(k=i+1;k<n;k++)lo[k]=0,s[k]='0';
				k=c1;
				m=c2;
				if(j==d1 && k>0)k--;
				else if(j==d2 && m>0 &&(j!=0 || nonz==1)) m--;
				if(isp(s.substr(i+1,n-(i+1)),d1,k,d2,m))break;
			}
			if(j>0)nonz=1;
			if(j==d1 && c1>0)c1--;
			if(j==d2 && c2>0 && (j!=0 || nonz==1))c2--;
		}
		return toLL(s);
	}
};