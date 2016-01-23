#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
class TT{
public:
	long long h,sqadd,add,tot;
	TT(){};
	TT(long long h1,long long a,long long b,long long c){
		h=h1;
		sqadd=a;
		add=b;
		tot=c;
	}
};
using namespace std;
int main(){
	static long long t,te,i,j,k,n,m,ans,mod=1000000007,add,sqadd,tot=0;
	static T inp[200001];
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		stack<TT>q;
		TT a;
		for(i=0;i<n;i++)cin>>inp[i].x>>inp[i].y;
		sort(inp,inp+n);
		add=sqadd=0;
		ans=0;
		for(i=0;i<n;i++){
			while(!q.empty() && q.top().h<inp[i].y){
				q.pop();
			}
			if(!q.empty() && q.top().h==inp[i].y){
				a=q.top();
				q.pop();
				ans=(ans + a.sqadd)%mod;
				ans=(ans + (a.tot*((inp[i].x*inp[i].x)%mod))%mod)%mod;
				ans=(ans + mod - ((a.add*inp[i].x)%mod))%mod;
				a.sqadd=(a.sqadd+(inp[i].x*inp[i].x)%mod)%mod;
				a.add=(a.add+(2*inp[i].x)%mod)%mod;
				a.tot++;
				q.push(a);
			}
			else{
				a.sqadd=(inp[i].x*inp[i].x)%mod;
				a.add=(2*inp[i].x)%mod;
				a.tot=1;
				a.h=inp[i].y;
				q.push(a);
			}
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}