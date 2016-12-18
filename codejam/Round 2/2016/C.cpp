#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
bool isp(int arr[], int n){
	vector<int> v;
	int i,j,x,y;
	for(i=0;i<n;i++)v.push_back(arr[i]);
	for(i=0;n>0;i++,n-=2){
		for(j=0;j<n;j+=2){
			if(abs(v[i]-v[i+1])==1 || abs(v[i]-v[i+1])==(n-1))break;
		}
		if(j==n)break;
		x=v[i];
		y=v[i+1];
		v.erase(v.begin()+i);
		v.erase(v.begin()+i);
		for(j=0;j<(n-2);j++){
			if(v[j]>x)v[j]--;
			if(v[j]>y)v[j]--;
		}
	}
	return (v.size()==0);
}
int main(){
	long long t,te,i,j,k,n,m,arr[100];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>r>>c;
		n=2*(r+c);
		int arr[n];
		for(i=0;i<n;i++)fin>>arr[i];
		if(r==1 || c==1){
			for(i=0;i<n;i+=2){
				if(abs(arr[i]-arr[i+1])!=1 && abs(arr[i]-arr[i+1])!=(n-1))break;
			}
			if(i<n){
				fout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";
				cout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";
				continue;
			}
			fout<<"Case #"<<(te+1)<<":\n";
		}
		else{
			if(isp(arr,n)){
				fout<<"Case #"<<(te+1)<<":\n";
				//Too tough for 5 minutes
			}
			else{
				fout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";
				cout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";
			}
		}
	}
	return 0;
}