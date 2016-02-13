#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,m,ans=0,x,y;
	cin>>n>>m;
	for(i=1,j=k=x=0;;i++){
		if((i%6)==0)x++;
		else if((i%3)==0)k++;
		else if((i%2)==0)j++;
		y=(n-j)+(m-k);
		if(x>=y)break;
	}
	cout<<i<<"\n";
	return 0;
}