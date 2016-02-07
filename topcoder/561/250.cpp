#include <bits/stdc++.h>
using namespace std;
class ICPCBalloons{
	public:
	int minRepaintings(vector<int> bC,string bS,vector<int>mA){
		int i,j,k,n=bC.size(),m=mA.size(),po=1<<m,ans=1000000,arr[m],curr;
		vector<int> v1,v2,a1,a2;
		for(i=0;i<n;i++){
			if(bS[i]=='M')v1.push_back(bC[i]);
			else v2.push_back(bC[i]);
		}
		priority_queue<int> q;
		for(i=0;i<po;i++){
			a1.clear();
			a2.clear();
			for(j=0,k=i;j<m;j++,k/=2){
				if(k&1)a1.push_back(mA[j]);
				else a2.push_back(mA[j]);
			}
			sort(a1.begin(),a1.end());
			sort(a2.begin(),a2.end());
			reverse(a1.begin(),a1.end());
			reverse(a2.begin(),a2.end());
			for(j=k=0;j<a1.size();j++)k+=a1[j];
			for(j=0;j<v1.size();j++)k-=v1[j];
			if(k>0)continue;
			for(j=k=0;j<a2.size();j++)k+=a2[j];
			for(j=0;j<v2.size();j++)k-=v2[j];
			if(k>0)continue;
			for(j=curr=0;j<v1.size();j++)q.push(v1[j]);
			for(j=0;j<a1.size();j++){
				k=q.top();
				q.pop();
				if(k<a1[j])curr+=(a1[j]-k);
				q.push(0);
			}	
			while(!q.empty())q.pop();
			for(j=0;j<v2.size();j++)q.push(v2[j]);
			for(j=0;j<a2.size();j++){
				k=q.top();
				q.pop();
				if(k<a2[j])curr+=(a2[j]-k);
				q.push(0);
			}	
			while(!q.empty())q.pop();
			ans=min(ans,curr);
		}
		if(ans>100000)return -1;
		return ans;
	}
};