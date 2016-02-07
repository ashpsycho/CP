#include <bits/stdc++.h>
using namespace std;
int abs1(int x){
	return max(x,-x);
}
class FoxAndMountainEasy{
	public:
	string possible(int n,int h0,int hn,string his){
		if(((h0+hn)%2)!=(n%2))return "NO";
		string s1="YES",s2="NO";
		int i,j,k;
		for(j=i=k=0;i<his.size();i++){
			if(his[i]=='U')j++;
			else j--;
			k=min(k,j);
		}
		k=-k;
		if(h0>=k)i=0;
		else i=k-h0;
		j=j+max(k,h0);
		if((i+his.size())>n)return s2;
		i+=his.size();
		if(abs1(j-hn)>(n-i))return s2;
		return s1;
	}
};