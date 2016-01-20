#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
class TaroCoins{
	public:
	long long getNumber(long long n){
		long long i,j,k=2,x;
		vector<T>v[2];
		v[0].push_back(T(0,1));
		for(i=0;i<61;i++,k=k*2){
			for(j=0;j<=2;j++){
				for(x=0;x<v[0].size();x++)
					v[1].push_back(T(v[0][x].x+j*(k/2),v[0][x].y));
			}
			v[0].clear();
			sort(v[1].begin(),v[1].end());
			for(j=0;j<v[1].size();j++){
				if(v[1][j].x>n)continue;
				if((v[1][j].x%k)!=(n%k))continue;
				if(v[0].size()>0 && (v[1][j].x==v[0][v[0].size()-1].x)){
					v[0][v[0].size()-1].y+=v[1][j].y;
					continue;
				}
				v[0].push_back(v[1][j]);
			}
			v[1].clear();
		}
		for(i=0;i<v[0].size();i++)if(v[0][i].x==n)break;
		return v[0][i].y;
	}
};