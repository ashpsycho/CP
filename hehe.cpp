#include <bits/stdc++.h>
using namespace std;
int main(){
	long long i,j,k,j1,n,arr[63];
	map<long long,int>m;
	map<long long,int>::iterator it;
	queue<long long>q;
	q.push(31);
	m[31]=0;
	while(!q.empty()){
		j1=j=q.front();
		q.pop();
		for(i=0;i<63;i++)arr[i]=0;
		for(i=0,k=1;i<63;i++,k*=2LL)if((k&j)>0)arr[i]=1;
		for(i=0;i<63;i++){
			for(j=0;j<63;j++){
				if(arr[i]==0 || arr[j]==1)continue;
				if(j!=0 && arr[j-1]==0)continue;
				if(i!=0 && arr[i-1]==0)continue;
				if(j==(i+1))continue;
				k=(j1) + (1LL<<j) - (1LL<<i);
				it=m.find(k);
				if(it==m.end()||(m[k]>(1+m[j1]))){
					if(k<100)cout<<k<<"\n";
					m[k]=1+m[j1];
					q.push(k);
				}
			}
		}
	}
	cout<<"hehe\n";
	while(1){
		cin>>n;
		cout<<m[n]<<"\n";
	}
	return 0;
}
