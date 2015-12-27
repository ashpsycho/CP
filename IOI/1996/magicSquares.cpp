#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int ans[8];

int getNum(int a[]){
	int n=8,fact[8]={1,1,2,6,24,120,720,5040},i,j,ans=0;
	for(i=0;i<n;i++){
		ans+=(a[i]*fact[n-(i+1)]);
		for(j=i+1;j<n;j++)if(a[j]>a[i])a[j]--;
	}
	return ans;
}

int fnA(int a[]){
	int i,j,change[8]={7,6,5,4,3,2,1,0};
	for(i=0;i<8;i++)ans[i]=a[change[i]];
	return getNum(ans);
}

int fnB(int a[]){
	int i,j,change[8]={3,0,1,2,5,6,7,4};
	for(i=0;i<8;i++)ans[i]=a[change[i]];
	return getNum(ans);
}

int fnC(int a[]){
	int i,j,change[8]={0,6,1,3,4,2,5,7};
	for(i=0;i<8;i++)ans[i]=a[change[i]];
	return getNum(ans);
}

static int brr[40320][8];
void getFact(int num){
	int i;
	for(i=0;i<8;i++)ans[i]=brr[num][i];
	return;
}

int main(){
	int t,te=0,i,j,k,n,m,arr[8];
	for(i=0;i<8;i++)arr[i]=i;
	do{
		for(j=0;j<8;j++)brr[te][j]=arr[j];
		te++;
	}while(next_permutation(arr,arr+8));
	for(i=0;i<8;i++)cin>>arr[i],arr[i]--;
	queue<int>q;
	int vis[40320],par[40320],inp;
	for(i=0;i<40320;i++)vis[i]=0,par[i]=-1;
	inp=getNum(arr);
	q.push(0);
	vis[q.front()]=1;
	while(!q.empty()){
		j=q.front();
		q.pop();
		getFact(j);
		for(k=0;k<8;k++)arr[k]=ans[k];
		k=fnA(arr);
		if(vis[k]==0){
			vis[k]=1;
			par[k]=j;
			q.push(k);
		}
		k=fnB(arr);
		if(vis[k]==0){
			vis[k]=1;
			par[k]=j;
			q.push(k);
		}
		k=fnC(arr);
		if(vis[k]==0){
			vis[k]=1;
			par[k]=j;
			q.push(k);
		}
	}
	vector<char>fin;
	for(i=inp;par[i]!=-1;i=par[i]){
		getFact(par[i]);
		for(j=0;j<8;j++)arr[j]=ans[j];
		if(fnA(arr)==i)fin.push_back('A');
		else if(fnB(arr)==i)fin.push_back('B');
		else if(fnC(arr)==i)fin.push_back('C');
	}
	cout<<fin.size()<<"\n";
	reverse(fin.begin(),fin.end());
	for(i=0;i<fin.size();i++)cout<<fin[i]<<"\n";
	return 0;
}