#include <bits/stdc++.h>
#include <sstream>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
long long dist(T a,T b){
	return (abs(a.x-b.x) + abs(a.y-b.y));
}
class ThreeTeleports{
	public:
	int shortestDistance(int xm,int ym,int xh,int yh,vector<string>inp){
		long long i,j,k=dist(T(xm,ym),T(xh,yh)),time[7];
		T points[7],a,b;
		points[0]=T(xm,ym);
		for(i=0;i<3;i++){
			stringstream fin;
			fin<<inp[i];
			fin>>a.x>>a.y>>b.x>>b.y;
			points[1+i*2]=a;
			points[2+i*2]=b;
		}
		for(i=1;i<7;i++)time[i]=3000000000LL;
		long long adj[7][7];
		for(i=0;i<7;i++)
			for(j=0;j<7;j++)adj[i][j]=dist(points[i],points[j]);
		for(i=1;i<7;i+=2)
			adj[i][i+1]=adj[i+1][i]=min(adj[i][i+1],10LL);
		queue<int>q;
		q.push(0);
		time[0]=0;
		while(!q.empty()){
			j=q.front();
			q.pop();
			for(i=0;i<7;i++){
				if(time[i]>(time[j]+adj[j][i])){
					time[i]=time[j]+adj[j][i];
					q.push(i);
				}
			}
		}
		b=T(xh,yh);
		for(i=0;i<7;i++){
			j=dist(points[i],b)+time[i];
			k=min(k,j);
		}
		return k;
	}
};