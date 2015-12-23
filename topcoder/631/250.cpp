// took too much time to decipher what is asked in the problem
// Henceforth, deciphering the problem statement is most important
#include <bits/stdc++.h>
using namespace std;
bool isp(vector<string> g){
	int i,j,n=g.size(),k=0;
	for(i=0;i<n;i++){
		char curr='A';
		for(j=0;j<n;j++){
			if(g[j][i]!=curr){
				curr=g[j][i];
				k=1;
			}
			else k++;
			if(k>(n/2))return 0;
		}
	}
	return 1;
}
class TaroJiroGrid{
	public:
	int getNumber(vector<string> g){
		int i,j,n=g.size();
		vector<string> v;
		if(isp(g))return 0;
		for(i=0;i<n;i++){
			v=g;
			for(j=0;j<n;j++)v[i][j]='W';
			if(isp(v))return 1;
			for(j=0;j<n;j++)v[i][j]='B';
			if(isp(v))return 1;
		}
		return 2;
	}
};