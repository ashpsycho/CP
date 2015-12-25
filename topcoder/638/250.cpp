#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
class T{
	public:
	int x,y,z;
	T(){};
	T(int x1,int y1,int z1){
		x=x1;
		y=y1;
		z=z1;
	}
};
int arr[11][11][11],brr[11][11][11];
int check(vector<string>xy,vector<string>yz,vector<string>zx){
	int i,j,k,n=xy.size();
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(xy[i][j]=='N')continue;
			for(k=0;k<n && brr[i][j][k]==0;k++);
			if(k==n)return 0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(yz[i][j]=='N')continue;
			for(k=0;k<n && brr[k][i][j]==0;k++);
			if(k==n)return 0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(zx[i][j]=='N')continue;
			for(k=0;k<n && brr[j][k][i]==0;k++);
			if(k==n)return 0;
		}
	}
	return 1;
}
class ShadowSculpture{
	public:
	string possible(vector<string> xy,vector<string> yz,vector<string> zx){
		int i,j,k,n=xy.size(),tot=0;
		T dir[6]={T(1,0,0),T(-1,0,0),T(0,1,0),T(0,-1,0),T(0,0,1),T(0,0,-1)};
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)arr[i][j][k]=1;
		}		
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(xy[i][j]=='Y')continue;
				for(k=0;k<n;k++)arr[i][j][k]=0;
			}
		}
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(yz[i][j]=='Y')continue;
				for(k=0;k<n;k++)arr[k][i][j]=0;
			}
		}
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(zx[i][j]=='Y')continue;
				for(k=0;k<n;k++)arr[j][k][i]=0;
			}
		}
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)tot+=arr[i][j][k];
		if(tot==0){	
			for(i=0;i<n;i++){	
				for(j=0;j<n;j++)if(xy[i][j]=='Y'||yz[i][j]=='Y'||zx[i][j]=='Y')break;
				if(j<n)break;
			}
			return (i==n)?"Possible":"Impossible";
		}
		while(tot>0){
			queue<T>q;
			T a,b;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					for(k=0;k<n;k++){
						if(arr[i][j][k]==1)break;
					}
					if(k<n)break;
				}
				if(j<n)break;
			}
			if(i==n)break;
			q.push(T(i,j,k));
			arr[i][j][k]=0;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					for(k=0;k<n;k++)brr[i][j][k]=0;
			while(!q.empty()){
				a=q.front();
				q.pop();
				tot--;
				brr[a.x][a.y][a.z]=1;
				for(i=0;i<6;i++){
					b=T(a.x+dir[i].x,a.y+dir[i].y,a.z+dir[i].z);
					if(arr[b.x][b.y][b.z]==1){
						arr[b.x][b.y][b.z]=0;
						q.push(b);
					}
				}
			}
			if(check(xy,yz,zx))return "Possible";
		}	
			
		return "Impossible";
	}	
};