#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 1001
using namespace std;

int i,j,k,n,q, curr[MAX], ro, m[MAX][MAX];

void solveM(){
	curr[0]=0;
	for(i=1;i<n && m[0][i]==0;i++)curr[i]=0;
	if(i==n)return;
	curr[i]=-1*m[0][i];
	for(j=i+1;j<n;j++){
		curr[j] = ((m[0][i]+m[0][j])!=(m[i][j]))?-m[0][j]:m[0][j];
	}
}

void print(){
	for(int j=0;j<n;j++)printf("%d ",curr[j]);
	printf("\n");
}

int main(){
	ll t=1,te,ans;
	for(te=0;te<t;te++){
		cin>>n>>q;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)scanf("%d",&m[i][j]);
		}
		solveM();
		print();
		for(int i=0;i<q;i++){
			cin>>ro;
			ro--;
			for(j=0;j<n;j++){
				scanf("%d",&m[ro][j]);
				m[j][ro]=m[ro][j];
			}
			solveM();
			print();
		}
	}
	return 0;
}