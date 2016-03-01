#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
vector<long long> v;
vector<T>p;
bool fn(T a, T b){
	return (a.y<b.y);
}
class Ear{
	public:
	long long getCount(vector<string>rX,vector<string>bX,vector<string>bY){
		long long i,j,k,ans=0,d,e,f,g;
		long double a,b,c,eps=1e-9;
		stringstream f1,f2,f3;
		for(i=0;i<rX.size();i++)f1<<rX[i];
		for(i=0;i<bX.size();i++)f2<<bX[i];
		for(i=0;i<bY.size();i++)f3<<bY[i];
		while(f1>>j)v.push_back(j);
		while(f2>>j && f3>>k)p.push_back(T(j,k));
		sort(v.begin(),v.end());
		sort(p.begin(),p.end(),fn);
		for(i=1;i<p.size();i++){
			for(j=0;p[j].y<p[i].y;j++){
				b=p[j].y*(p[i].x-p[j].x);
				c=p[j].y-p[i].y;
				a=p[j].x;
				a=a+(b/c);
				b=min((long long)floor(a-eps),p[i].x-1);
				c=max((long long)ceil(a+eps),p[i].x+1);
				for(k=d=e=f=g=0;k<v.size();k++){
					if(v[k]<=b)d++;
					else if(v[k]<=(p[j].x-1))e++;
					else if(v[k]>p[j].x){
						if(v[k]<c)f++;
						else g++;
					}
				}
				d=(d+e);
				d=((d*(d-1))/2LL)-((e*(e-1))/2LL);
				g=g+f;
				g=((g*(g-1))/2LL)-((f*(f-1))/2LL);
				ans=(ans+(d*g));
			}
		}
		return ans;
	}
};