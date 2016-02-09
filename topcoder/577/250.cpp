#include <bits/stdc++.h>
#include <sstream>
using namespace std;
class EllysRoomAssignmentsDiv1{
	public:
	double getAverage(vector<string> inp){
		string s;
		int i,j,k,n,m,x;
		double ans=0.0,curr,y;
		vector<int> v;
		stringstream fin;
		for(i=0;i<inp.size();i++)fin<<inp[i];
		while(fin>>j)
			v.push_back(j);
		x=v[0];
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		n=v.size();
		m=(n+19)/20;
		for(i=y=0;i<n;i+=min(m,n-i),y+=1.0){
			k=min(m,n-i);
			for(j=0,curr=0;j<k;j++){
				curr+=v[i+j];
				if(x==v[i+j])break;
			}
			curr=curr/(double)k;
			if(k<m)curr=((curr*k)+((ans/y)*(m-k)))/m;
			if(j<k)curr=x;
			ans=ans+curr;
		}
		return (ans/((n+m-1)/m));
	}
};