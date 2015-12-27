#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
T calc(int x1,int x2,int y1,int y2max){
	int i,j=y1;
	T ans=T(y1,-1);
	for(i=x1;i<=x2;i++){
		if(i==x2)ans.y=j;
		ans.x=max(ans.x,j);
		if(y2max>=(j+2-(x2-i)))j++;
		else if(y2max>=(j+1-(x2-i)))j=j;
		else j--;
	}
	return ans;
}
class BuildingTowersEasy{
	public:
	int maxHeight(int N,vector<int>x,vector<int> t){
		if(x.size()==0 || x[x.size()-1]!=N){
			x.push_back(N);
			t.push_back(N-1);
		}
		if(x.size()>0 && x[0]==1){
			x.erase(x.begin());
			t.erase(t.begin());
		}
		int i,j,k,n=x.size(),curr=0,currX=1,ans=0;
		for(i=0;i<n;i++){
			t[i]=min(t[i],x[i]-1);
			for(j=0;j<i;j++)
				t[i]=min(t[i],t[j]+x[i]-x[j]);		
			for(j=i+1;j<n;j++)
				t[i]=min(t[i],t[j]+x[j]-x[i]);
			for(j=i+1;j<n;j++)
				t[j]=min(t[j],t[i]+x[j]-x[i]);
		}
		T a;
		for(i=0;i<n;i++){
			a=calc(currX,x[i],curr,t[i]);
			ans=max(ans,a.x);
			curr=a.y;
			currX=x[i];
		}
		return ans;
	}
};