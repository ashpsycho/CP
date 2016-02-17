#include <bits/stdc++.h>
using namespace std;
class EllysScrabble{
	public:
	string getMin(string s,int maxD){
		int i,j,k,n=s.size(),arr[n];
		for(i=0;i<n;i++)arr[i]=i;
		for(i=0;i<n;i++){
			if(arr[i]==(i-maxD))continue;
			for(j=k=i;j<n;j++)if(abs(arr[j]-i)<=maxD && s[k]>s[j])k=j;
			for(j=k;j>i;j--){
				swap(s[j],s[j-1]);
				swap(arr[j],arr[j-1]);
			}
			if(k!=i)i--;
		}
		return s;
	}
};