#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class DoubleOrOneEasy{
	public:
	int minimalSteps(int a, int b, int newA, int newB){
		int i,j,ans=0,req,amax,bmax;
		if(a>b){
			swap(a,b);
			swap(newA,newB);
		}
		if(a>newA || b>newB)return -1;
		if(a==newA || b==newB){
			if(a==newA && b==newB)return 0;
			else return -1;
		}
		if(a==b && newA==newB){
			for(i=newA,j=0;i!=a;){	
				if(i&1){
					i--;
					j++;
				}
				else if(i>=(2*a)){
					i/=2;
					j++;
				}
				else{
					j+=(i-a);
					return j;
				}
			}
			return j;
		}
		if(newA>newB)return -1;
		for(i=(newB-newA),req=0;i>0&&((i%2)==0);i/=2,req++)if(i==(b-a))break;
		if(i!=(b-a)){
			return -1;
		}
	
		for(amax=0,i=a;(i*2)<=newA;i=i*2,amax++);
		for(bmax=0,i=b;(i*2)<=newB;i=i*2,bmax++);
		if(amax<req || bmax<req)return -1;
		for(i=newA,ans=0;i!=a;){
			if(req==0){
				ans+=(i-a);
				i=a;
				break;
			}
			else if(i&1){
				ans++;
				i--;
			}
			else if(i<a){
				return -1;
			}
			else{
				i=i/2;
				ans++;
				req--;
			}
		}
		return ans;
	}	
};