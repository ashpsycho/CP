/*
ID: a1lavan1
LANG: C++
TASK: cowtour
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 151
using namespace std;

long double calc(T a, T b){
	long double x=((long double)1.0)*(a.x-b.x)*(a.x-b.x);
	long double y=((long double)1.0)*(a.y-b.y)*(a.y-b.y);
	return sqrt(x+y);
}

int main(){
	ifstream fin("cowtour.in");
	FILE *fout;
	fout =fopen("cowtour.out","w");
	long long i,j,k,n,m;
	long double ans=0.0,dist[MAX][MAX],curr,mid;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)dist[i][j]=400000000.0;
	for(i=0;i<MAX;i++)dist[i][i]=0.0;
	T arr[MAX];
	string inp[MAX];
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i].x>>arr[i].y;
	for(i=0;i<n;i++){
		fin>>inp[i];
		for(j=0;j<n;j++)if(inp[i][j]=='1')
			dist[i][j]=calc(arr[i],arr[j]);
	}
	// Time for APSP
	for(k=0;k<n;k++){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(dist[i][j]>(dist[i][k]+dist[k][j]))
					dist[i][j]=dist[i][k]+dist[k][j];
			}
	}
	for(i=0,ans=400000000.0;i<n;i++){
		for(j=0;j<n;j++){
			if(dist[i][j]<400000000.0)continue;
			for(k=0,curr=mid=0.0;k<n;k++)
				if(dist[i][k]<400000000.0)curr=max(curr, dist[i][k]);
			mid=curr;
			for(k=0,curr=0.0;k<n;k++)
				if(dist[j][k]<400000000.0)curr=max(curr, dist[j][k]);
			ans=min(ans,mid+curr+calc(arr[i],arr[j]));
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(dist[i][j]<400000000.0)ans=max(ans,dist[i][j]);
		}
	}
	fprintf(fout,"%.6Lf\n",ans);
	return 0;
}