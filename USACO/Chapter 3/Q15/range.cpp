/*
ID: a1lavan1
LANG: C++
TASK: range
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("range.in");
	ofstream fout("range.out");
	long long i,ans,j,k,n,m;
	fin>>n;
	string arr[500];
	for(i=0;i<n;i++)fin>>arr[i];
	static int isp[250][250][2];
	for(i=0;i<250;i++)
		for(j=0;j<250;j++)
			for(k=0;k<2;k++)isp[i][j][k]=0;
	for(i=0;i<250;i++)
		for(j=0;j<250;j++)isp[i][j][0]=(arr[i][j]=='1');
	for(i=2;i<251;i++){
		ans=0;
		for(j=i-1;j<n;j++){
			for(k=i-1;k<n;k++){
				if(arr[j][k]=='0')continue;
				if(isp[j-1][k-1][0]==0)continue;
				if(isp[j-1][k][0]==0)continue;
				if(isp[j][k-1][0]==0)continue;
				isp[j][k][1]=1;
				ans++;
			}
		}
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)isp[j][k][0]=isp[j][k][1],isp[j][k][1]=0;
		if(ans==0)break;
		fout<<i<<" "<<ans<<"\n";
		cout<<i<<" "<<ans<<"\n";
	}
	return 0;
}