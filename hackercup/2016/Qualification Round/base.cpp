#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
//	FILE *fp;
//	fp=fopen("output.txt","w");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		

		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	//	printf("Case #%d: %.9Lf\n",te+1,ans);
	//	fprintf(fp,"Case #%d: %.9Lf\n",te+1,ans);

	}
	return 0;
}