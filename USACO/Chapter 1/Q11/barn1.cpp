/*
ID: a1lavan1
LANG: C++
TASK: barn1
*/
#include <bits/stdc++.h> 
#define MAX 201
using namespace std;
int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	long long i,ans,j,k,n,m,arr[MAX],tot;
	fin>>n>>tot>>m;
	for(i=0;i<m;i++)fin>>arr[i];
	sort(arr,arr+m);
	priority_queue<long long>q;
	for(i=0;i<(m-1);i++)
		q.push(arr[i+1]-(arr[i]+1));
	for(ans=(arr[m-1]+1-arr[0]),i=1;i<n && !q.empty();i++){
		ans-=q.top();
		q.pop();
	}
	fout<<ans<<"\n";
	return 0;
}