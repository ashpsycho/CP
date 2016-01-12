#include<bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
double fn(double a,double b,double c){
	double s=(a+b+c)/2.0;
	return sqrtl(s*(s-a)*(s-b)*(s-c));
}
class MaxTriangle{
	public:
	double calculateArea(int A,int B){
		int i,j,n;
		vector<T>v1,v2;
		n=A;
		for(i=0;(i*i)<=n;i++){
			j=n-(i*i);
			j=(int)roundl(sqrtl(j));
			if(((i*i)+(j*j))==n)v1.push_back(T(i,j));
		}
		n=B;
		for(i=0;(i*i)<=n;i++){
			j=n-(i*i);
			j=(int)roundl(sqrtl(j));
			if(((i*i)+(j*j))==n)v2.push_back(T(i,j));
		}
		double ans=-1.0,a=sqrt(A),b=sqrt(B),c;
		for(i=0;i<v1.size();i++){
			for(j=0;j<v2.size();j++){
				c=sqrtl(1LL*(v1[i].x-v2[j].x)*(v1[i].x-v2[j].x) + 1LL*(v1[i].y-v2[j].y)*(v1[i].y-v2[j].y));
				ans=max(ans,fn(a,b,c));
				c=sqrtl(1LL*(v1[i].x-v2[j].x)*(v1[i].x-v2[j].x) + 1LL*(v1[i].y+v2[j].y)*(v1[i].y+v2[j].y));
				ans=max(ans,fn(a,b,c));
				c=sqrtl(1LL*(v1[i].x+v2[j].x)*(v1[i].x+v2[j].x) + 1LL*(v1[i].y-v2[j].y)*(v1[i].y-v2[j].y));
				ans=max(ans,fn(a,b,c));
				c=sqrtl(1LL*(v1[i].x+v2[j].x)*(v1[i].x+v2[j].x) + 1LL*(v1[i].y+v2[j].y)*(v1[i].y+v2[j].y));
				ans=max(ans,fn(a,b,c));
			}
		}
		return ans;
	}
};