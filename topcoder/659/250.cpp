#include <bits/stdc++.h>
using namespace std;
class ApplesAndOrangesEasy{
	public:
	int maximumApples(int n,int K,vector<int> v){
		int arr[n],i,j,k;
		for(i=0;i<n;i++)arr[i]=0;
		for(i=0;i<v.size();i++)arr[v[i]-1]=1;
		if(n<=K)return (K/2);
		for(i=0;i<n;i++){
			if(arr[i]==1)continue;
			for(j=0,k=max(i-(K-1),0);k<min(n,i+K);k++){
				j+=arr[k];
				if(k>i && k>=K)j-=arr[k-K];
				if(j==(K/2))break;
			}
			if(k<min(n,i+K))continue;
			arr[i]=1;
		}
		for(i=k=0;i<n;i++)k+=arr[i];
		return k;
	}
};