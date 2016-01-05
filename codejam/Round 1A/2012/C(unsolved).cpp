#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<long double,long double>
#define x first
#define y second
using namespace std;
long double fn(vector<T> v){
	int i,j,k,curr=0,n=v.size(),v1[n],v2[n];
	for(i=0;i<n;i++)v[i].y-=(1.0e-9);
	for(i=0;i<n;i++){
		v1[i]=v[i].x;
		v2[i]=v[i].y;
	}
	sort(v1,v1+n);
	sort(v2,v2+n);
	for(i=j=0;i<n;i++){
		if(v2[j]<v1[i]){
			curr--;
			j++;
			continue;
		}
		curr++;
		if(curr>=2)return v1[i];
		i++;
	}
	return 100001;
}
int main(){
	long long t,te,i,j,k,n,m;
	long double sp[50],dis[50],ans=-1;
	ifstream fin("input.txt");
	FILE *fp;
	fp=fopen("output.txt","w");
	fin>>t;
	string inp;
	for(te=0;te<t;te++){
		fin>>n;
		for(i=0;i<n;i++)
			fin>>inp>>sp[i]>>dis[i];
		vector<T> v;
		T a;
		ans=100001;
		for(i=0;i<n;i++){
			v.clear();
			for(j=0;j<n;j++){
				if(sp[j]==sp[i]){
					if(abs(dis[i]-dis[j])<=5)v.push_back(T((long double)0.0,(long double)10001.0));
					continue;
				}
				else if(sp[j]<sp[i]){
					a.x=max((long double)0.0,(dis[j]-(dis[i]+5))/(sp[i]-sp[j]));
					a.y=max((long double)0.0,(dis[j]-(dis[i]-5))/(sp[i]-sp[j]));
					v.push_back(a);
				}
				else{
					a.x=max((long double)0.0,(dis[i]-(dis[j]+5))/(sp[j]-sp[i]));
					a.y=max((long double)0.0,(dis[i]-(dis[j]-5))/(sp[j]-sp[i]));
					v.push_back(a);
				}
			}
			ans=min(ans,fn(v));
		}
		if(ans>10000){
			printf("Case #%d: Possible\n",te+1);
			fprintf(fp,"Case #%d: Possible\n",te+1);
			continue;
		}
		printf("Case #%d: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);

	}
	return 0;
}
