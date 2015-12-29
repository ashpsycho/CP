#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;

long long mod=1000000007;
class FoxAndFencing{
	public:
	string WhoCanWin(int m1,int m2,int r1,int r2,int d){
		string s1="Ciel",s2="Liss";
		if(d<=(m1+r1))return s1;
		if((d+m1)<=(m2+r2))return s2;
		if(m1>m2){
			if((m1+r1)>(m2+r2+m2))return s1;
		}
		else if(m2>m1){
			if((m2+r2)>(m1+r1+m1))return s2;
		}
		return "Draw";
	}	
};