#include <bits/stdc++.h>
using namespace std;
class T{
public:
	int a,b,k;
	T(){}
	T(int k1,int a1,int b1){
		k=k1;
		a=a1;
		b=b1;
	}
};

vector<T>v;
int arr[100001];
bool fn(T a,T b){
	return (a.b<b.b);
}

bool isp (int m,int ma){
	int i,j,k,x,n=v.size();
	for(i=1;i<=m;i++)arr[i]=ma;
	for(i=0;i<n;i++){
		for(j=v[i].a,x=v[i].k;j<=v[i].b&& x>0;j++){
			if(arr[j]>0){
				k=min(arr[j],x);
				arr[j]-=k;
				x-=k;
			}
		}
	}
	for(i=1;i<=m;i++)if(arr[i]!=0)return false;
	return true;
}

class FleetFunding{
public:	
	int maxShips(int m, vector<int> K, vector<int> a, vector<int> b){
		int beg=0,end=60000000,mid,eps=1;
		for(int i=0;i<K.size();i++)v.push_back(T(K[i],a[i],b[i]));
		sort(v.begin(),v.end(),fn);
		while((end-beg)>0){
			mid=(beg+end)/2;
			if(isp(m, mid))beg=mid+eps;
			else end=mid;
		}
		if(!isp(m,mid))mid--;
		return mid;
	}
};