#include <bits/stdc++.h>
using namespace std;
bool fn(int a,int b){
	if((a%10)<(b%10))return true;
	if((a%10)>(b%10))return false;
	return(a<b);
}
class Cut{
	public:
	int getMaximum(vector<int>v,int m){
		int i,j,k=0,n=v.size();
		sort(v.begin(),v.end(),fn);
		for(i=0;i<n && m>0;i++){
			if((v[i]%10)==0)j=(v[i]/10)-1;
			else j=v[i]/10;
			if(m>=j){
				k+=(v[i]/10);
				m-=j;
			}
			else{
				k+=m;
				m=0;
			}
		}
		return k;
	}
};