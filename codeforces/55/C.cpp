#include <bits/stdc++.h> 
using namespace std;

bool isp(int x,int n){
	return ((x-1)<3)||((n-x)<3);
}

int main(){
	int i,j,k,n,m,x[100],y[100];
	cin>>n>>m>>k;
	for(i=0;i<k;i++){
		cin>>x[i]>>y[i];
	}
	for(i=0;i<k;i++){
		if(isp(x[i],n) || isp(y[i],m))break;
	}
	if(i==k)cout<<"NO";
	else cout<<"YES";
	return 0;
}