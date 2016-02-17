#include <bits/stdc++.h>
#include <sstream>
using namespace std;
class TreeUnion{
	public:
	double expectedCycles(vector<string> t1,vector<string> t2,int K){
		vector<int>adj1[400],adj2[400];
		int i,j,k,n,d1[400][400],d2[400][400];
		stringstream f1,f2;
		double fin=0.0,tot=0.0,arr[400];
		for(i=k=0;i<t1.size();i++)f1<<t1[i];
		while(f1>>j){
			k++;
			adj1[k].push_back(j);
			adj1[j].push_back(k);
		}
		for(i=k=0;i<t2.size();i++)f2<<t2[i];
		while(f2>>j){
			k++;
			adj2[k].push_back(j);
			adj2[j].push_back(k);
		}
		n=1+k;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)d1[i][j]=d2[i][j]=1000000000;
		}
		queue<int>q;
		for(i=0;i<n;i++){
			q.push(i);
			d1[i][i]=0;
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj1[j].size();k++)if(d1[i][adj1[j][k]]>(1+d1[i][j])){
					d1[i][adj1[j][k]]=(1+d1[i][j]);
					q.push(adj1[j][k]);
				}
			}
		}
		for(i=0;i<n;i++){
			q.push(i);
			d2[i][i]=0;
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj2[j].size();k++)if(d2[i][adj2[j][k]]>(1+d2[i][j])){
					d2[i][adj2[j][k]]=(1+d2[i][j]);
					q.push(adj2[j][k]);
				}
			}
		}
		for(i=0;i<400;i++)arr[i]=0;
		for(i=0;i<n;i++){	
			for(j=i+1;j<n;j++){
				tot+=1.0;
				arr[d2[i][j]]+=1.0;
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				k=K-(d1[i][j]+2);
				if(k<0)continue;
				fin+=(arr[k]/tot);
			}
		}
		return fin;
	}
};