#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define T pair<int,int>
#define x first
#define y second
class compare{
public:
	bool operator()(T &a,T &b){
		return (a.y>b.y);
	}
};
int main(){
	int t,te,i,j,k,n,m,fin=0,arr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	string s1,s2;
	cin>>t>>s1>>s2;
	t--;
	if(s2=="week"){
		for(i=4,j=0;j<366;j++,i=(i+1)%7){
			if(i==t)fin++;
		}
	}
	else{
		for(i=0;i<12;i++)if(arr[i]>t)fin++;
	}
	cout<<fin<<"\n";
	return 0;
}