#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,a,arr[100001],A,B;
	long double ans,b,c,ans1;
	ifstream fin("input.txt");
	FILE *fp;
	fp=fopen("output.txt","w");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>A>>B;
		for(i=0;i<n;i++)fin>>arr[i];
		ans=ans1=0;
		for(i=a=0;i<n;i++)a+=arr[i];
		j=(A/a);
		A-=(j*a);
		B-=(j*a);
		for(a=0,i=0;a<=B && i<n;a=a+arr[i],i++){
			if((a+arr[i])<A)continue;
			b=max(A,a);
			c=min(B,a+arr[i]);
			ans+=((((c+b-2*a)/2.0)*(c-b))/((long double)(B-A)));
		}
		for(i=0,k=a;a<=B && i<n;a=a+arr[i],i++){
			if((a+arr[i])<A)continue;
			b=max(A,a);
			c=min(B,a+arr[i]);
			ans1+=((((c+b-2*a)/2.0)*(c-b))/((long double)(B-A)));
		}
		if(a>B){
			printf("Case #%d: %.9Lf\n",te+1,ans);
			fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);	
			continue;	
		}
		j=(a-k);
		m=(B-k)/j;
		ans=ans+(ans1*m);
		a=k+(m*j);
		for(i=0;a<=B;a=a+arr[i],i=(i+1)%n){
			if((a+arr[i])<A)continue;
			b=max(A,a);
			c=min(B,a+arr[i]);
			ans+=((((c+b-2*a)/2.0)*(c-b))/((long double)(B-A)));
		}
		printf("Case #%d: %.12Lf\n",te+1,ans);
		fprintf(fp,"Case #%d: %.12Lf\n",te+1,ans);
	}
	return 0;
}
