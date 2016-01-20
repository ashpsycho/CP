#include <bits/stdc++.h>
using namespace std;
vector<long long> lol;
class BitwiseAnd{
	public:
	vector<long long>lexSmallest(vector<long long> v, int N){
		sort(v.begin(),v.end());
		long long forbid=0,i,j,k,curr=0,n=v.size(),left=0,all=(1LL<<60)-1;
		if(N==v.size()){
			for(i=0;i<N;i++){
				for(j=i+1;j<N;j++){
					if((v[i]&v[j])==0)return lol;
					for(k=j+1;k<N;k++)
						if((v[i]&v[j]&v[k])>0)return lol;
				}	
			}
			return v;
		}
		for(i=0;i<n;i++){
			left=left|v[i];
			for(j=i+1;j<n;j++)forbid=forbid|(v[i]&v[j]);
		}
		for(i=0;i<n;i++){
			k=v[i]-(v[i]&forbid);
			if(k==0)return lol;
			for(j=1;(j&k)==0;j=j*2);
			curr=curr+j;
		}
		k=(N-n)-1;
		left=all-left;
		if(__builtin_popcountl(left)<k)return lol;
		for(i=0,j=1;i<60 && k>0;i++,j*=2){
			if((j&left)>0){
				k--;
				curr+=j;
			}
		}
		v.push_back(curr);
		return lexSmallest(v,N);
	}
};