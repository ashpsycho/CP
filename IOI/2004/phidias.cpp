#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	static int t,te,i,j,k,n,m,W,H,ans[601][601];
	cin>>W>>H;
	cin>>n;
	vector<T> types;
	for(i=0;i<n;i++){
		cin>>j>>k;
		types.push_back(T(j,k));
	}
	for(i=1;i<=W;i++){
		for(j=1;j<=H;j++){
			ans[i][j]=i*j;
			for(k=0;k<n;k++){
				if(types[k].x>i || types[k].y>j)continue;
				if(types[k].x == i && types[k].y == j){
					ans[i][j]=0;
				}
				else if(types[k].x == i){
					ans[i][j]=min(ans[i][j],ans[i][j-types[k].y]);
				}
				else if(types[k].y == j){
					ans[i][j]=min(ans[i][j],ans[i-types[k].x][j]);
				}
				else{
					ans[i][j]=min(ans[i][j],ans[types[k].x][j-types[k].y]+ans[i-types[k].x][j]);
					ans[i][j]=min(ans[i][j],ans[i][j-types[k].y]+ans[i-types[k].x][types[k].y]);
				}
			}
		}
	}

	cout<<ans[W][H];
	return 0;
}
