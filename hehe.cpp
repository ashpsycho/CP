#include <bits/stdc++.h>
using namespace std;
int main(){
	long long ma;
	cin>>ma;
	long long i,j,k,n,t,te,p,po[ma];
	po[0]=1;
	for(i=1;i<ma;i++)po[i]=po[i-1]*2;
	map<long long, int>m;
	queue<long long>q;
	q.push(ma);
	m[ma]=0;
	while(!q.empty()){
		k=q.front();
		q.pop();
		for(i=0;i<ma;i++){
			for(j=0;j<ma;j++){
				if(j==(i+1)||(i==j) || (k&po[i])==0 || (k&po[j])!=0)continue;
				if(i!=0 && (k&po[i-1])==0)continue;
				if(j!=0 && (k&po[j-1])==0)continue;
				t=k+po[j]-po[i];
				if(m.find(t)==m.end()){
					m[t]=1+m[k];
					q.push(t);
				}
			}
		}
	}
	for(i=ma;;i*=2){
		if(m.find(i)==m.end())break;
		cout<<i<<" "<<m[i]<<"\n";
	}
	while(cin>>i){
		cout<<m[i]<<"\n";
	}
	return 0;
}
