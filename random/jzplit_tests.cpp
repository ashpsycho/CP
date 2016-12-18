#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i,po,te=0,j,k,x;
	for(n=2;n<5;n++){
		for(m=2;m<=n;m++){
			string arr[n];
			arr[0]="";
			for(i=0;i<m;i++)arr[0]+="a";
			for(i=1;i<n;i++)arr[i]=arr[0];
			for(i=1,po=(1<<(n*m));i<po;i++){
				for(j=0,x=i;j<n;j++){
					for(k=0;k<m;k++,x/=2){
						arr[j][k]=(((x&1)==1)?'0':'1');
					}
				}
				te++;
				cout<<n<<" "<<m<<"\n";
				for(j=0;j<n;j++)cout<<arr[j]<<"\n";
				cout<<"\n";
			}
		}
	}
	cout<<te<<"\n";
	return 0;
}