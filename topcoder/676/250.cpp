#include <bits/stdc++.h>
using namespace std;
class WaterTank{
	public:
	bool isp(vector<int> t, vector<int>x, int C,double mid){
		double curr=0.0,rate;
		for(int i=0;i<t.size();i++){
			rate=x[i];
			rate-=mid;
			curr=curr+(rate*t[i]);
			if(curr<0)curr=0;
			if(curr>C)return false;
		}
		return true;
	}
	double minOutputRate(vector<int> t, vector<int> x, int c){
		double beg=0.0,end=10000000.0,mid,eps=1.0e-7;
		while((end-beg)>eps){
			mid=(beg+end)/2;
			if(isp(t,x,c,mid))end=(mid);
			else beg=(mid+eps);
		}
		return mid;
	}
};