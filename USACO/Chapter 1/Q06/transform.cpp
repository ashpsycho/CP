/*
ID: a1lavan1
LANG: C++
TASK: transform
*/
#include <bits/stdc++.h> 
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int n,i,j,k,ans=7;
string init[10],fin[10];
bool check(int rotate,int reflect){
	T a,b;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a=T(i,j);
			for(k=0;k<rotate;k++)a=T(a.y,n-(1+a.x));
			if(reflect)a=T(a.x,n-(1+a.y));
			if(init[i][j] != fin[a.x][a.y])return false;
		}
	}
	return true;
}
int fn(){
	if(check(1,0))return 1;
	if(check(2,0))return 2;
	if(check(3,0))return 3;
	if(check(0,1))return 4;
	if(check(1,1)||check(2,1)||check(3,1))return 5;
	if(check(0,0))return 6;
	return 7;
}
int main(){
	ifstream fin1("transform.in");
	ofstream fout("transform.out");
	fin1>>n;
	for(i=0;i<n;i++)fin1>>init[i];
	for(i=0;i<n;i++)fin1>>fin[i];
	ans=fn();
	fout<<ans<<"\n";
	return 0;
}