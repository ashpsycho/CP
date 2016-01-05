#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long a,b,t,te,i,j,k,n;
	long double ans,curr,p,arr[100001];
	ifstream fin("input.txt");
	FILE *fp;
	fp=fopen("output.txt","w");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>a>>b;
		for(i=0;i<a;i++)fin>>arr[i];
		ans=(2+b);
		for(i=0,p=1.0;i<a;i++){
			curr=(p*(a+b+1-2*i)) +((1.0-p)*(a+2*b+2-2*i));
			ans=min(ans,curr);
			p*=arr[i];
		}
		curr=(p*(a+b+1-2*i)) +((1.0-p)*(a+2*b+2-2*i));
		ans=min(ans,curr);
		printf("Case #%d: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);

	}
	return 0;
}
