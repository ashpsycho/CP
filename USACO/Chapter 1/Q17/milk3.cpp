/*
ID: a1lavan1
LANG: C++
TASK: milk3
*/
#include <bits/stdc++.h> 
#define T pair<int, int>
#define x first
#define y second
#define MAX 100001
using namespace std;

class TT{
public:
	int a[3];
	TT (){}
	TT(int A,int B,int C){
		a[0]=A;
		a[1]=B;
		a[2]=C;
	}
};

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	int i,j,k,n,m,arr[21][21][21],cap[3];
	fin>>cap[0]>>cap[1]>>cap[2];
	queue<TT>q;
	TT a,b;
	q.push(TT(0,0,cap[2]));
	T moves[6]={T(0,1),T(0,2),T(1,0),T(1,2),T(2,1),T(2,0)};
	for(i=0;i<21;i++){
		for(j=0;j<21;j++)
			for(k=0;k<21;k++)arr[i][j][k]=0;
	}	
	int ans[21];
	vector<int> v;
	arr[0][0][cap[2]]=1;
	for(i=0;i<21;i++)ans[i]=0;
	while(!q.empty()){
		a=q.front();
		q.pop();
		for(k=0;k<6;k++){
			i=a.a[moves[k].x];
			j=cap[moves[k].y]-a.a[moves[k].y];
			b=a;
			if(i<j){
				b.a[moves[k].y]+=b.a[moves[k].x];
				b.a[moves[k].x]=0;
			}
			else{
				b.a[moves[k].x]-=j;
				b.a[moves[k].y]+=j;	
			}
			if(arr[b.a[0]][b.a[1]][b.a[2]]==0)q.push(b);
			arr[b.a[0]][b.a[1]][b.a[2]]=1;
		}
	}
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)if(arr[0][i][j]==1)ans[j]=1;
	for(i=0;i<21;i++)if(ans[i]==1)v.push_back(i);
	for(i=0;i<v.size();i++){
		fout<<v[i];
		fout<<(i!=(v.size()-1)?' ':'\n');
	}
	return 0;
}