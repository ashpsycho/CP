#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
class compare{
public:
	bool operator()(T &a, T &b){
		return (a.x>b.x);
	}
};
int main(){
	static long long t,te,i,j,k,n,m,ans,all,d,arr[100001],curr[1000001];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	T a,b;
	for(te=0;te<t;te++){
		fin>>all>>n>>m>>d;
		priority_queue<T,vector<T>,compare>q;
		for(i=0;i<n;i++)fin>>arr[i];
		for(i=0;i<n;i++){
			q.push(T(arr[i],i));
		}

		for(i=0;i<all;i++){
			a=q.top();
			q.pop();
			q.push(T(a.x+arr[a.y],a.y));
			if(i<m)curr[i]=a.x+d;
			else curr[i]=max(curr[i-m],a.x)+d;
		}
		ans=curr[all-1];
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}