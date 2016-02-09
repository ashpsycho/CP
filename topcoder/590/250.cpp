#include<bits/stdc++.h>
#define T pair<char,int>
#define x first
#define y second
using namespace std;
class FoxAndChess{
	public:
	string ableToMove(string st,string en){
		vector<T> v1,v2;
		string s1="Possible",s2="Impossible";
		int i,n=st.size();
		for(i=0;i<n;i++){
			if(st[i]!='.')v1.push_back(T(st[i],i));
			if(en[i]!='.')v2.push_back(T(en[i],i));
		}
		if(v1.size()!=v2.size())return s2;
		for(i=0;i<v1.size();i++){
			if(v1[i].x!=v2[i].x)return s2;
			if(v1[i].x=='L' && v2[i].y>v1[i].y)return s2;
			if(v1[i].x=='R' && v2[i].y<v1[i].y)return s2;
		}
		return s1;
	}
};