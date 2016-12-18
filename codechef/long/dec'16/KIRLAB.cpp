#include <bits/stdc++.h> 
#define MAX 10000001
using namespace std;

int fact[MAX],ans[MAX],i,j,k;

void init(){
	for(int i=0;i<MAX;i++)fact[i]=ans[i]=0;
}

void factor(){
	for(i=2;i<MAX;i++){
		if(fact[i]!=0)continue;
		fact[i]=i;
		if(i>10000)continue;
		for(j=(i*i);j<MAX;j+=i)fact[j]=i;
	}
}

void update(int n, int val){
	for(;n>1;){
		ans[fact[n]]=val;
		k=fact[n];
		while((n%k)==0)n/=k;
	}
}

int getMax(int n){
	int val=0;
	for(;n>1;){
		val=max(val,ans[fact[n]]);
		k=fact[n];
		while((n%k)==0)n/=k;
	}
	return val;
}

int main(){

	init();
	factor();
	int t,te,i,fin=0,j,k,n,m,arr[100001];
	cin>>t;
	for(te=0;te<t;te++){
		for(i=0;i<MAX;i++)ans[i]=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>arr[i];
			update(arr[i],getMax(arr[i])+1);
		}
		for(i=fin=0;i<MAX;i++){
			fin=max(fin,ans[i]);
		}
		cout<<max(1,fin)<<'\n';
	}
	return 0;
}