#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;

long double prob[201],ans,mid[201],arr[201];
void update(long double x){
	int i;
	for(i=0;i<17;i++)mid[i]=0.0;
	for(i=0;i<17;i++){
		mid[i+1]+=(prob[i]*x);
		mid[i]+=(prob[i]*((long double)1.0-x));
	}
	for(i=0;i<17;i++)prob[i]=mid[i];
}

int main(){
	int t,te,i,j,k,n,m,ans1;
	ifstream fin("input.txt");
	FILE *fp;
	fp=fopen("output1.txt","w");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>k;
		for(i=0;i<n;i++)fin>>arr[i];
		sort(arr,arr+n);
		ans=0.0;
		for(i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)==k){
				for(j=0;j<n;j++)prob[j]=0.0;
				prob[0]=1.0;
				for(j=0,m=1;j<n;j++,m*=2){
					if(i&m)update(arr[j]);
				}
				if(prob[k/2]>=ans)ans1=i;
				ans=max(ans,prob[k/2]);
			}
		}
		printf("Case #%d: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);
		for(i=0;i<n;i++)cout<<arr[i]<<" ";
		cout<<"\n";
		for(i=0,j=1;i<n;i++,j*=2)if(j&ans1)cout<<arr[i]<<" ";
		cout<<"\n";
	}
	return 0;
}