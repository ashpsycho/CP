#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
using namespace std;

double solve(double c,double f,double x){
	int i,j,k,n=x;
	double curr,ans=(x/2.0),rate=2.0,tim=0.0;
	for(i=1;i<=n;i++){
		curr=tim + (x/rate);
		ans=min(ans,curr);
		tim+=(c/rate);
		rate+=f;
	}
	return ans;
}

int main(){
	long long t,te,i,j,k,n,m;
	long double ans;
	double c,f,x;
	ifstream fin("input.txt");
	FILE *fp;
	fp=fopen("output.txt","w");
//	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>c>>f>>x;
		ans=solve(c,f,x);
	//	fout<<"Case #"<<(te+1)<<": "<<setprecision(20)<<ans<<"\n";
	//	cout<<"Case #"<<(te+1)<<": "<<setprecision(20)<<ans<<"\n";
		printf("Case #%d: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);
	}
	return 0;
}
