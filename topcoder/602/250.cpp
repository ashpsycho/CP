#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class TypoCoderDiv1{
	public:
	int getmax(vector<int> v,int X){
		int i,j,k,n=v.size(),arr[50][2200];
		for(i=0;i<50;i++)
			for(j=0;j<2200;j++){
				arr[i][j]=-1;
			}
		queue<T>q;
		T a,b;
		q.push(T(X,0));
		for(i=0;i<n;i++){
			for(j=0,k=q.size();j<k;j++){
				a=q.front();
				q.pop();
				if(a.x<2200){
					b=T(a.x+v[i],a.y);
					if(b.x<2200)
						arr[i][b.x]=max(arr[i][b.x],b.y);
					else{
						b.y++;
						q.push(b);
					}
				}
				b=T(max(0,a.x-v[i]),a.y);
				if(a.x<2200)
					arr[i][b.x]=max(arr[i][b.x],b.y);
				else{
					if(b.x<2200){
						b.y++;
						arr[i][b.x]=max(arr[i][b.x],b.y);
					}
				}
			}
			for(j=0;j<2200;j++)if(arr[i][j]!=-1)q.push(T(j,arr[i][j]));
		}
		for(i=0,k=0;i<2200;i++)k=max(k,arr[n-1][k]);
		while(!q.empty()){
			a=q.front();
			q.pop();
			k=max(k,a.y);
		}
		return k;
	}
};