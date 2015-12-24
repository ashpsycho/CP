#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,arr[MAX],mi=0,ma=3000000000LL,pre,curr;
	vector<int>v;
	cin>>n;
	v.push_back(0);
	v.push_back(0);
	cin>>pre;
	for(i=0;i<n;i++){
		cin>>curr;
		if(curr<pre)break;
		v.push_back(v[0]+2*(curr-pre));
		if(i&1){
			mi=max(mi,v[1]-v[2]);
		}
		else{
			if(v[1]>v[2])break;
			ma=min(ma,v[2]-v[1]);
		}

		v.erase(0);
		pre=curr;
	}
	if(i<n){
		cout<<"0\n";
		return 0;
	}

	ans=(ma/2)+1-(mi/2);
	if(ans<0)ans=0;
	cout<<ans<<"\n";
	return 0;
}