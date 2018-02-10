#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
#define eps 1e-10
long double PI=3.14159265;
using namespace std;
int color(long double p, long double x, long double y){
	if((((x-50)*(x-50))+((y-50)*(y-50)))>2500)return 0;
	if(abs(x-50)<eps && abs(y-50)<eps)return (abs(p)>eps); 
	long double angle= (atanl((x-50)/(y-50))*180.0)/PI;
	if(y<50.0)angle+=180.0;
	if(angle<(-eps))angle+=360.0;
	angle=(angle/3.6);
	return (angle<=p);
}
int main(){
	long long t,te,i,j,k,n,m;
	long double p,x,y;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>p>>x>>y;
		string ans=(color(p,x,y)==0)?"white":"black";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}