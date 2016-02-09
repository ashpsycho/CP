#include <bits/stdc++.h>
using namespace std;
class UndoHistory{
	public:
	int minPresses(vector<string>inp){
		int i,j,k,n=inp.size(),ans=n,m,m1;
		string curr="";
		for(i=0;i<n;i++){	
			for(j=0;j<curr.size() && j<inp[i].size() && inp[i][j]==curr[j];j++);
			if(j==curr.size()){
				m1=(inp[i].size()-curr.size());
			}
			else m1=1000000000;
			for(j=m=0;j<i;j++){
				for(k=0;k<inp[i].size() && k<inp[j].size() && inp[i][k]==inp[j][k];k++);
				m=max(m,k);
			}
			ans+=min(m1,(int)inp[i].size()+2-m);
			curr=inp[i];
		}
		return ans;
	}
};