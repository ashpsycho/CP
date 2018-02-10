#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
string inp[11];
long double p[401],mid[401];

int toInt(string str){
	stringstream fin;
	fin<<str;
	int n;
	fin>>n;
	return n;
}

int calc(int x,int y){
	int i,j,k;
	for(i=0;i<401;i++)p[i]=0;
	p[0]=1;
	for(i=0;i<x;i++){
		for(j=0;j<401;j++)mid[j]=0;
		for(j=0;j<=(i*y);j++){
			for(k=1;k<=y;k++){
				mid[j+k]+=(p[j]/((long double)y));
			}
		}
		for(j=0;j<401;j++)p[j]=mid[j];
	}
}

long double eval(string s,int h){

	int dPos=(int)s.find('d'),plus=(int)s.find('+'),minus=(int)s.find('-');
	int x=toInt(s.substr(0,dPos)),y,z;
	if(plus!=string::npos){
		y=toInt(s.substr(dPos+1,plus-(dPos+1)));
		z=toInt(s.substr(plus+1,s.size()-(plus+1)));
	}
	else if(minus!=string::npos){
		y=toInt(s.substr(dPos+1,minus-(dPos+1)));
		z=-1*toInt(s.substr(minus+1,s.size()-(minus+1)));
	}
	else{
		y=toInt(s.substr(dPos+1,s.size()-(dPos+1)));
		z=0;
	}
	calc(x,y);
	long double ans=0.0;
	cout<<x<<" "<<y<<" "<<z<<" "<<(h-z)<<"\n";
	for(int i=max(0,h-z);i<=(x*y);i++)ans+=p[i];
	return ans;
}
int main(){
	long long t,te,i,j,k,h,n,m;
	long double ans=0.0;
	FILE *fp;
	fp=fopen("output.txt","w");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>h>>n;
		ans=0.0;
		for(i=0;i<n;i++){
			cin>>inp[i];
			ans=max(ans,eval(inp[i],h));
		}
		printf("Case #%lld: %.9Lf\n",te+1,ans);
		fprintf(fp,"Case #%lld: %.9Lf\n",te+1,ans);
	}
	return 0;
}