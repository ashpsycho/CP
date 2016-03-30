#include <bits/stdc++.h>
using namespace std;
class TheArray{
	public:
	int find(int n,int d,int f,int l){
		static int arr[1000001],brr[1000001],i,k;
		arr[0]=f;
		for(i=1;i<n;i++)arr[i]=arr[i-1]+d;
		brr[n-1]=l;
		for(i=n-2;i>=0;i--)brr[i]=brr[i+1]+d;
		for(i=0,k=f;i<n;i++)k=max(k,min(arr[i],brr[i]));
		return k;
	}
};