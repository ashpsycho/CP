#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;

long long mod=1000000007;
class TaroFillingAStringDiv1{
	public:
	int getNumber(int N,vector<int> pos,string val ){
		long long i,j,n=pos.size(),ans=1;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(pos[i]>pos[j]){
					swap(pos[i],pos[j]);
					swap(val[i],val[j]);
				}
			}
		}
		for(i=1;i<n;i++){
			j=(pos[i]-pos[i-1]);
			if(j==0)continue;
			if((j&1)==0){
				if(val[i]==val[i-1])continue;
				else
					ans=(ans*(j))%mod;
			}
			else{
				if(val[i]==val[i-1]){
					ans=(ans*(j))%mod;	
				}
				else continue;
			}	
		}
		
		return (int)ans;
	}	
};