#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,te,n,m,i,j,k,x;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>m;
		string inp[n];
		int arr[n][m],arr1[n][m],row[n],col[m];
		for(i=0;i<n;i++)cin>>inp[i];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				arr1[i][j]=inp[i][j]-'0';
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)arr[i][j]=1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(arr1[i][j]==0){
					for(k=0;k<n;k++)arr[k][j]^=1;
					for(k=0;k<m;k++)arr[i][k]^=1;
					arr[i][j]^=1;
				}
			}
		}
		cout<<"Case #"<<(te+1)<<": \n";
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)cout<<arr[i][j];
			cout<<"\n";
		}
		cout<<"\n";
		k=0;
		while(true){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(arr[i][j]==0)break;
				}
				if(j<m)break;
			}
			if(i==n)break;

			k++;
			for(i=0;i<n;i++)row[i]=0;
			for(i=0;i<m;i++)col[i]=0;

			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(arr[i][j]==0){
						row[i]^=1;
						col[j]^=1;
					}
				}
			}

			for(i=0;i<n;i++)
				for(j=0;j<m;j++)arr[i][j]=1;

			for(i=0;i<n;i++){
				if(row[i]==1){
					cout<<"ROW "<<i<<"\n";
					for(j=0;j<m;j++)arr[i][j]^=1;
				}
			}
			for(i=0;i<m;i++){
				if(col[i]==1){
					cout<<"COL "<<i<<"\n";
					for(j=0;j<n;j++)arr[j][i]^=1;
				}
			}
			if((k>50)){
				i=n-1;
				break;
			}
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					cout<<arr[i][j];
				}
				cout<<"\n";
			}
			cout<<"\n";


			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(arr[i][j]!=(inp[i][j]-'0'))break;
				}
				if(j<m)break;
			}
			if(i==n){
				i=n-1;
				break;
			}
		}
		if(i==n)cout<<"Ans: "<<k<<"\n";
		else{
			cout<<"Came back to input!";
			break;
		}
	}
	return 0;
}