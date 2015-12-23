#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 1001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,arr[MAX],coun[3]={0,0,0};
	cin>>n;
	vector<int> one2,one3,two1,two3,three1,three2;
	for(i=0;i<n;i++){
		cin>>arr[i];
		coun[arr[i]-1]++;
	}
	for(i=0;i<coun[0];i++){
		if(arr[i]==2)one2.push_back(i);
		if(arr[i]==3)one3.push_back(i);
	}
	for(;i<(coun[0]+coun[1]);i++){
		if(arr[i]==1)two1.push_back(i);
		if(arr[i]==3)two3.push_back(i);
	}
	for(;i<n;i++){
		if(arr[i]==2)three2.push_back(i);
		if(arr[i]==1)three1.push_back(i);
	}
	vector<T> ans;
	while(one2.size()>0 && two1.size()>0){
		ans.push_back(T(one2[0],two1[0]));
		one2.erase(one2.begin());		
		two1.erase(two1.begin());		
	}
	while(one3.size()>0 && three1.size()>0){
		ans.push_back(T(one3[0],three1[0]));
		one3.erase(one3.begin());		
		three1.erase(three1.begin());		
	}
	while(one2.size()>0){
		ans.push_back(T(one2[0],three1[0]));
		three2.push_back(three1[0]);
		one2.erase(one2.begin());		
		three1.erase(three1.begin());		
	}
	while(one3.size()>0){
		ans.push_back(T(one3[0],two1[0]));
		two3.push_back(two1[0]);
		one3.erase(one3.begin());		
		two1.erase(two1.begin());	
	}
	while(two3.size()>0 && three2.size()>0){
		ans.push_back(T(two3[0],three2[0]));
		two3.erase(two3.begin());
		three2.erase(three2.begin());
	}
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();i++){
		cout<<1+ans[i].x<<" "<<1+ans[i].y<<"\n";
	}
	return 0;
}
