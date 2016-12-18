#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > rec(vector<int> v){
	vector< vector<int> > ans;
	if(v.size()==0){
		vector<int> v;
		ans.push_back(v);
		return ans;
	}
	int curr=v[v.size()-1];
	v.erase(v.begin()+v.size()-1);
	vector< vector<int> > prev = rec(v);
	for(int i=0;i<prev.size();i++){
		ans.push_back(prev[i]);
		prev[i].push_back(curr);
		ans.push_back(prev[i]);
	}
	return ans;
}
int main(){
	cout<<"Enter no of elements in set\n";
	vector<int> v;
	int n,i,j;
	cin>>n;
	cout<<"Enter the elements\n";
	for( i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	vector< vector<int> >ans=rec(v);
	for(i=0;i<ans.size();i++){
		cout<<"{ ";
		for(j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
			if(j!=(ans[i].size()-1))cout<<", ";
			else cout<<"}";
		}
		cout<<"\n";
	}
	return 0;
}