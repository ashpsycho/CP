#include <bits/stdc++.h>
#define eps 1e-17
using namespace std;
long double p,getp[3001][3001],prob[3001],ans[3001],curr;
void fill_getp(){
	int i,j,k;
	if(abs(p)<eps){
		for(i=0;i<3001;i++)
			getp[i][0]=1.0;
		return;
	}
	if(abs(1.0-p)<eps){
		for(i=0;i<3001;i++)
			getp[i][i]=1.0;
		return;
	}
	for(i=0;i<3001;i++){
		getp[i][0]=1;
		for(j=0;j<i;j++){
			getp[i][0]*=((long double)1.0-p);
		}
		for(j=1;j<=i;j++){
			getp[i][j]=getp[i][j-1];
			getp[i][j]*=(long double)(i-(j-1));
			getp[i][j]/=(long double)(j);
			getp[i][j]*=(p/((long double)1.0-p));
		}
	}
}
int main(){
	long long t,te,i,j,k,n,K,m;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>K>>p;
		fill_getp();
		for(i=0;i<3001;i++){
			prob[i]=ans[i]=0.0;
			for(j=K;j<=i;j++)prob[i]+=getp[i][j];
		}
		for(i=1;i<=n;i++){
			for(j=0;j<=i;j++){
				curr=ans[i-j]+prob[j];
				ans[i]=max(ans[i],curr);
			}
		}
		fill_getp();
		printf("Case #%lld: %.9Lf\n",te+1,ans[n]);
	}
	return 0;
}