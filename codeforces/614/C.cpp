#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
int main(){
    long long i,j,k,n,a,b;
    long double mi,ma,m,c,d;
    cin>>n>>a>>b;
    mi=(long double)10000000000000LL;
    ma=(long double)0LL;
    long double pi=3.14159265358979323846;
    T arr[100001],x,y;
    for(i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        j=((arr[i].x-a)*(arr[i].x-a))+((arr[i].y-b)*(arr[i].y-b));
        mi=min(mi,(long double)j);
        ma=max(ma,(long double)j);
    }
    for(i=0;i<n;i++){
    	x=arr[i];
    	y=arr[(i+1)%n];
    	x=T(x.x-a,x.y-b);
    	y=T(y.x-a,y.y-b);
    	m=(x.x*y.y)-(x.y*y.x);
    	m=m*(m/((long double)((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y))));
        c=(x.x*x.x + x.y*x.y);
        d=(y.x*y.x + y.y*y.y);
        c=c-m;
        d=d-m;
        c=sqrtl(c);
        d=sqrtl(d);
        c=c+d;
        d=sqrtl(((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y)));
        if(abs(c-d)<0.01){
        	mi=min(mi,m);
        }
	}
	cout<<setprecision(19) <<(pi*(ma-mi)) <<"\n";
    return 0;
}
