/*
ID: a1lavan1
LANG: C++
TASK: runround
*/
#include <bits/stdc++.h> 
using namespace std;

string toString(int n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans;
}
vector<int> v;
void incrementAt(int i1){
	int i=i1;
	v[i]++;
	for(;v[i]>9;i--){
		if(i==0){
			v.insert(v.begin(),0);
			i++;
			i1++;
		}
		v[i-1]+=1;
		v[i]%=10;
	}
	for(i=i1+1;i<v.size();i++)v[i]=0;
	return;
}

int nextRunRound(int n){
	int i,j,k,vis[10],x;
	for(i=n;i>0;i/=10)v.insert(v.begin(),i%10);
	while(1){
		for(i=0;i<10;i++)vis[i]=0;
		for(i=j=k=0;vis[i]==0;i=(i+v[i])%v.size(),j++){
			vis[i]=1;
			k=max(k,i);
		}
		if(i==0 && j==v.size()){
			x=0;
			while(1){
				for(i=1;i<v.size();i++){
					if(v[i]==0)break;
					for(j=0;j<i;j++)if(v[i]==v[j])break;
					if(j!=i)break;
				}
				if(i==v.size())break;
				else x=1;
				incrementAt(i);
			}
			if(x==0)break;
		}
		else incrementAt(k);
	}
	for(i=0,k=0;i<v.size();i++){
		k=k*10+v[i];
	}
	return k;
}

int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	long long i,ans,j,k,n;
	fin>>n;
	fout<<nextRunRound(n+1)<<"\n";
	return 0;
}