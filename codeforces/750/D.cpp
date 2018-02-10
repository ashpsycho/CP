#include <bits/stdc++.h> 
#define T pair<int ,int >
#define TT pair<T, int>
#define x first
#define y second
#define MAX 401
using namespace std;
int main(){
	int t,te,i,ans,j,k,n,m,arr[MAX][MAX],inp[MAX], dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
	cin>>n;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++)arr[i][j]=0;
		if(i<n)cin>>inp[i];
	}
	set<TT> cur,nex;
	set<TT>::iterator it;
	cur.insert(TT(T(200,200),0));
	TT a;
	T b;
	for(i=0;i<n;i++){
		nex.clear();
		for(it=cur.begin();it!=cur.end();++it){
			a=*it;
			b=a.x;
			for(j=0;j<inp[i];j++){
				arr[b.x][b.y]=1;
				if(j!=(inp[i]-1)){
					b.x+=dir[a.y][0];
					b.y+=dir[a.y][1];
				}
			}
			nex.insert(TT(T(b.x+dir[(a.y+7)%8][0],b.y+dir[(a.y+7)%8][1]),(a.y+7)%8));
			nex.insert(TT(T(b.x+dir[(a.y+1)%8][0],b.y+dir[(a.y+1)%8][1]),(a.y+1)%8));
		}
		cur.clear();
		for(it=nex.begin();it!=nex.end();++it){
			cur.insert(*it);
		}
	}
	for(i=k=0;i<MAX;i++){
		for(j=0;j<MAX;j++)k+=arr[i][j];
	}
	cout<<k<<"\n";
	return 0;
}