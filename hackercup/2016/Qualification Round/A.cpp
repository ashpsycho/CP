#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	vector<long long>v;
	T arr[2001];
	for(te=0;te<t;te++){
		fin>>n;
		ans=0;
		for(i=0;i<n;i++)fin>>arr[i].x>>arr[i].y;
		for(i=0;i<n;i++){	
			v.clear();
			for(j=0;j<n;j++){
				v.push_back((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x) + (arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
			}
			sort(v.begin(),v.end());
			for(j=0;j<n;){
				for(k=j+1;k<n && v[k]==v[j];k++);
				j=(k-j);
				ans+=((j*(j-1))/2);
				j=k;
			}
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}