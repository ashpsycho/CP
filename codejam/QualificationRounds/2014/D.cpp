#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
double add=0.0000001;
int solve1(vector<double>a,vector<double>b,int curr){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a.size()==1){
		if(a[0]>b[0])return curr+1;
		return curr;
	}
	if(a[0]>b[0]){
		a.erase(a.begin());
		b.erase(b.begin());
		return solve1(a,b,curr+1);
	}
	else{
		a.erase(a.begin());
		b.erase(b.begin()+b.size()-1);
		return solve1(a,b,curr);
	}
}
int solve2(vector<double>a,vector<double>b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i,j,ans=0;
	for(i=a.size()-1;i>=0;i--){
		for(j=0;j<b.size() && b[j]<a[i];j++);
		j=j%b.size();
		if(a[i]>b[j])ans++;
		a.erase(a.begin()+i);
		b.erase(b.begin()+j);
	}
	return ans;
}
int main(){
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	vector<double> a,b;
	double x,y,z;
	for(te=0;te<t;te++){
		fin>>n;
		a.clear();
		b.clear();
		for(i=0;i<n;i++){
			fin>>x;
			a.push_back(x);
		}
		for(i=0;i<n;i++){
			fin>>x;
			b.push_back(x);
		}
		fout<<"Case #"<<(te+1)<<": "<<solve1(a,b,0)<<" "<<solve2(a,b)<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<solve1(a,b,0)<<" "<<solve2(a,b)<<"\n";

	}
	return 0;
}
