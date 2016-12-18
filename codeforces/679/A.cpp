#include <bits/stdc++.h> 
using namespace std;
int main(){
	int i,ans,j,k,n,m,arr[19]={2,3,4,5,9,25,7,49,11,13,17,19,23,29,31,37,41,43,47};
	string s;
	for(i=j=0;i<19;i++){
		cout<<arr[i]<<"\n";
		fflush(stdout);
		cin>>s;
		if(s=="yes")j++;
	}
	if(j>1)cout<<"composite\n";
	else cout<<"prime\n";
	fflush(stdout);
	return 0;
}