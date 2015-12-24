#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 1<<18
using namespace std;
int main(){
	static int t,te,i,j,k,n,m,inp[9],vis[MAX],curr[9];
	vector<int>add[9];
	add[0].push_back(0);
	add[0].push_back(1);
	add[0].push_back(3);
	add[0].push_back(4);
	add[1].push_back(0);
	add[1].push_back(1);
	add[1].push_back(2);
	add[2].push_back(1);
	add[2].push_back(2);
	add[2].push_back(4);
	add[2].push_back(5);
	add[3].push_back(0);
	add[3].push_back(3);
	add[3].push_back(6);
	add[4].push_back(1);
	add[4].push_back(3);
	add[4].push_back(4);
	add[4].push_back(5);
	add[4].push_back(7);
	add[5].push_back(2);
	add[5].push_back(5);
	add[5].push_back(8);
	add[6].push_back(3);
	add[6].push_back(4);
	add[6].push_back(6);
	add[6].push_back(7);
	add[7].push_back(6);
	add[7].push_back(7);
	add[7].push_back(8);
	add[8].push_back(4);
	add[8].push_back(5);
	add[8].push_back(7);
	add[8].push_back(8);
	static T arr[MAX];
	for(i=0,j=MAX;i<j;i++)arr[i]=T(j+1,10),vis[i]=0;
	for(i=j=0;i<9;i++){
		cin>>inp[i];
		inp[i]=(inp[i]%12)/3;
		j=j*4+inp[i];
	}
	queue<int>q;
	arr[j]=T(0,-1);
	q.push(j);
	vis[j]=1;
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(i=8,k=j;i>=0;i--,k/=4)inp[i]=(k%4);
		for(i=0;i<9;i++){
			for(k=0;k<9;k++)curr[k]=inp[k];
			for(k=0;k<add[i].size();k++){
				curr[add[i][k]]++;
				curr[add[i][k]]%=4;
			}
			for(k=m=0;k<9;k++)m=m*4+curr[k];
			if(vis[m]==0){
				vis[m]=1;
				arr[m]=T(arr[j].x+1,i);
				q.push(m);
			}
		}
	}
	vector<int> ans;
	for(i=0;arr[i].y>=0;){
		ans.push_back(arr[i].y+1);
		for(j=8,k=i;j>=0;j--,k/=4)inp[j]=(k%4);
		for(j=0;j<add[arr[i].y].size();j++)
			inp[add[arr[i].y][j]]=(inp[add[arr[i].y][j]]+3)%4;
		for(j=i=0;j<9;j++)i=i*4+inp[j];
	}
	reverse(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
