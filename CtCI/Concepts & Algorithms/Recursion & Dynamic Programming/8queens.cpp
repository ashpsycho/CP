#include <bits/stdc++.h>
using namespace std;

int ans=0;
void print(vector<int> v){
	int i,n=v.size();
	ans++;
	string board[n];
	board[0]="";
	for(i=0;i<n;i++)board[0]+=".";
	for(i=1;i<n;i++)board[i]=board[0];
	for(i=0;i<n;i++)board[i][v[i]]='Q';
	cout<<"\n";
	for(i=0;i<n;i++)cout<<board[i]<<"\n";
	cout<<"\n";
	return;
}

void rec(vector<int> v,int n){
	if(v.size()==n){
		print(v);
		return;
	}
	int i,j,isp[n];
	for(i=0;i<n;i++)isp[i]=1;
	for(i=0;i<v.size();i++){
		isp[v[i]]=0;
		if((v[i]+(v.size()-i))<n)isp[v[i]+(v.size()-i)]=0;
		if((v[i]-(v.size()-i))>=0)isp[v[i]-(v.size()-i)]=0;
	}
	v.push_back(0);
	for(i=0;i<n;i++){
		if(isp[i]==0)continue;
		v[v.size()-1]=i;
		rec(v,n);
	}
	return;
}

int main(){
	int i,j,k,n;
	cout<<"Enter size of board\n";
	cin>>n;
	vector<int> v;
	rec(v,n);
	cout<<ans<<"\n";
	return 0;
}