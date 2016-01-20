#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long fn(vector<int>a,vector<int>b,int ma){
	long long ans=1,i,j,n=a.size();
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(i=0;i<n;i++){
		for(j=0;j<n && (a[i]*b[j])<ma;j++);
		ans=(ans*(j-i))%mod;
	}
	return ans;
}
class BearCavalry{
	public:
	int countAssignments(vector<int> w, vector<int> h){
		int i,j,n=w.size();
		long long ans=0;
		vector<int>a,b;
		a=w;
		a.erase(a.begin());
		for(i=0;i<n;i++){
			b.clear();
			for(j=0;j<n;j++){
				if(j==i)continue;
				b.push_back(h[j]);
			}
			ans=(ans+fn(a,b,w[0]*h[i]))%mod;
		}
		return (int)ans;
	}
};