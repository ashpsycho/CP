#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define T pair<ll,ll>
#define x first
#define y second
int fn(ll h1, ll h2, ll d){
	if(d>=(h1+h2))return (4*h1*h1+4*h2*h2);
	ll ans=4*d*(h1+h2-d);
	ans+=(h1+d-h2)*(h1+d-h2);
	ans+=(h2+d-h1)*(h2+d-h1);
	cout<<h1<<" "<<h2<<" "<<d<<" "<<ans<<"\n";
	return ans;
}

long double fin(long long h){
	long double x=h;
	return (x/8.0);
}

int main(){
	long long t,te,i,j,k,n,m,a1,b1,c1,h1,a2,b2,c2,x1;
	FILE *fp;
	fp=fopen("output.txt","w");	cin>>t;
	static T inp[1000001];
	for(te=0;te<t;te++){
		cin>>n;
		cin>>x1>>a1>>b1>>c1;
		cin>>h1>>a2>>b2>>c2;
		for(i=0,j=x1,k=h1;i<n;i++){
			inp[i]=T(j,k);
			j=1+((j*a1)+b1)%c1;
			k=1+((k*a2)+b2)%c2;
		}
		sort(inp,inp+n);
		stack<T>s;
		s.push(T(0,4*inp[0].y*inp[0].y));
		for(i=1;i<n;i++){
			cout<<inp[i].x<<" "<<inp[i].y<<"\n";
			cout<<i<<" "<<s.top().x<<" "<<s.top().y<<"\n";
			if((inp[s.top().x].y+inp[s.top().x].x-inp[i].x)>=inp[i].y)continue;
			while(!s.empty() && (inp[i].y+inp[s.top().x].x-inp[i].x)>=inp[s.top().x].y)s.pop();
			if(s.empty())
				s.push(T(i,4*inp[i].y*inp[i].y));
			else
				s.push(T(i,s.top().y+fn(inp[s.top().x].y,inp[i].y,inp[i].x-inp[s.top().x].x)));
		}
		cout<<i<<" "<<s.top().x<<" "<<s.top().y<<"\n";	
		long double ans=fin(s.top().y+4*inp[s.top().x].y*inp[s.top().x].y);
		printf("Case #%lld: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%lld: %.9Lf\n",te+1,ans);
	}
	return 0;
}