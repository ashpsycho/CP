#include <bits/stdc++.h>
using namespace std;
#define T pair<long long,long long>
#define x first
#define y second
class BigFatInteger2{
	public:
	string isDivisible(int A,int B,int C,int D){
		long long i,j;
		string s1="divisible", s2="not "+s1;
		vector<T> a,b;
		for(i=2;(i*i)<=A;i++){
			for(j=0;(A%i)==0;j++,A/=i);
			if(j>0)a.push_back(T(i,j*B));
		}	
		if(A>1)a.push_back(T(A,1LL*B));
		for(i=2;(i*i)<=C;i++){
			for(j=0;(C%i)==0;j++,C/=i);
			if(j>0)b.push_back(T(i,j*D));
		}	
		if(C>1)b.push_back(T(C,1LL*D));
		for(i=0;i<b.size();i++){
			for(j=0;j<a.size();j++){
				if(b[i].x==a[j].x)break;
			}
			if(j==a.size())return s2;
			if(b[i].y>a[j].y)return s2;
		}
		return s1;
	}
};