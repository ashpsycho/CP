#include <bits/stdc++.h> 
#define T pair<int, int>
#define x first
#define y second
#define MAX 200001
using namespace std;

bool range_check(int rate, int div){
	if(div==1 &&rate<1900)return false;
	if(div==2 &&rate>=1900)return false;
	return true;
}
static T arr[MAX];
int i,n,val;
int check(int st){
	for(i=0,val=st;i<n;i++){
		if(!range_check(val, arr[i].y))return arr[i].y;
		val+=arr[i].x;
	}
	return -1;
}

int main(){
	static int t,te,ans,j,k,m;
	cin>>n;
	for(i=0;i<n;i++)scanf("%d%d",&arr[i].x, &arr[i].y);
	int beg=(arr[0].y==1)?1900:-40000000, end=(arr[0].y==1)?40000000:1899,mid=(beg+end)/2;
	if(check(40000000)==-1){
		cout<<"Infinity\n";
		return 0;
	}
	while(beg<end){
		k=check(mid);
		if(k==-1)break;
		else if(k==1)beg=mid+1;
		else end=mid-1;
		mid=(beg+end)/2;
	}
	if(check(mid)!=-1){
		cout<<"Impossible\n";
		return 0;
	}
	for(k=mid;check(k+1)==-1;k++);
	check(k);
	cout<<val<<"\n";
	return 0;
}