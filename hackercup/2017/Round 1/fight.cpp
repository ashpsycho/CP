#include <bits/stdc++.h>
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;

long long intersect(vector<int>a, vector<int> b){
	set<int> s;
	for(int i=0;i<a.size();i++)s.insert(a[i]);
	for(int i=0;i<b.size();i++)s.insert(b[i]);
	return s.size();
}

int main(){
	long long t,te,R,i,j,k,n,m,ans;
	T inp[51];
	vector<int> arr[201];
	ofstream fout("output.txt");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>R;
		for(i=0;i<201;i++)arr[i].clear();
		for(i=0;i<n;i++)cin>>inp[i].x>>inp[i].y;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(abs(inp[i].x-inp[j].x)>R ||abs(inp[i].y-inp[j].y)>R)continue;
				if(inp[i].x>=inp[j].x && inp[i].y>=inp[j].y)arr[i*4+0].push_back(j);
				if(inp[i].x<=inp[j].x && inp[i].y>=inp[j].y)arr[i*4+1].push_back(j);
				if(inp[i].x>=inp[j].x && inp[i].y<=inp[j].y)arr[i*4+2].push_back(j);
				if(inp[i].x<=inp[j].x && inp[i].y<=inp[j].y)arr[i*4+3].push_back(j);
			}
		}
		for(i=ans=0;i<(4*n);i++){
			for(j=0;j<(4*n);j++){
				ans=max(ans,intersect(arr[i],arr[j]));
			}
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";

	}
	return 0;
}