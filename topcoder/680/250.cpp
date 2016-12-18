#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class BearFair{
	public:
	string isFair(int n,int b, vector<int> lim,vector<int> coun){
		vector<T>v;
		string yes="fair",no="unfair";
		int i,j,k;
		for(i=0;i<lim.size();i++){
			v.push_back(T(lim[i],coun[i]));
		}
		v.push_back(T(0,0));
		v.push_back(T(b,n));
		sort(v.begin(),v.end());
		for(i=1,j=k=0;i<v.size();i++){
			if(v[i].y<v[i-1].y)return no;
			if(v[i].x==v[i-1].x && v[i].y!=v[i-1].y)return no;
			if((v[i].x-v[i-1].x)<(v[i].y-v[i-1].y))return no;
			j+=min(v[i].y-v[i-1].y, (v[i].x/2)-(v[i-1].x/2));
			k+=min(v[i].y-v[i-1].y, ((1+v[i].x)/2)-((1+v[i-1].x)/2));
		}
		if((j<(n/2)) || (k<(n/2)))return no;
		return yes;
	}
};