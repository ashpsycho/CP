#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;

long long mod=1000000007;
class FoxAndFencingEasy{
	public:
	string WhoCanWin(int m1,int m2,int d){
		if(d<=m1)return "Ciel";
		if((d+m1)<=m2)return "Liss";
		if((2*m1)<m2)return "Liss";
		if((2*m2)<m1)return "Ciel";
		return "Draw";
	}	
};