/*
ID: a1lavan1
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h> 
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
#define MAX 10001
using namespace std;
int main(){
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int i,ans,j,k,n,m;
	T arr[MAX];
	vector<int> v;
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i].x>>arr[i].y;
	sort(arr,arr+n);
	v.push_back(arr[0].x);
	for(i=1,j=arr[0].y;i<n;i++){
		if(arr[i].x>j){
			v.push_back(j);
			v.push_back(arr[i].x);
		}
		j=max(j,arr[i].y);
	}
	v.push_back(j);
	for(j=k=i=0;i<(v.size()-1);i++){
		if((i&1))k=max(k,v[i+1]-v[i]);
		else j=max(j,v[i+1]-v[i]);
	}
	fout<<j<<" "<<k<<"\n";
	return 0;
}