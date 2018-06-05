#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,c,k,d;
	int flag=0,good=0,mod=20011;
	cin>>r>>c>>d;
	int a[c];
	int grid[301][301];
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(i=0;i<c;i++)
	a[i]=0;
	int ans[301][301],fin[301][301];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			ans[i][j]=0;
		}
	}
	int visited1=0,visited2[c];
	for(i=0;i<c;i++)
	visited2[i]=0;
	if(grid[0][0]==0)flag=1;
	for(i=1;i<c;i++)
	{
		if(grid[0][i]==0)
		{
			flag=1;
			a[i]=0;
		}
		if(flag==1||i>d)
		ans[0][i]=0;
		else
		ans[0][i]=1;
	}
	flag=0;
	if(grid[0][0]==0)flag=1;
	for(i=1;i<r;i++)
	{
		if(grid[i][0]==0)
			flag=1;
		if(flag==1||i>d)
		ans[i][0]=0;
		else
		ans[i][0]=1;
	}
	
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(grid[i][j]==1)
			{
				ans[i][j]=ans[i-1][j]+ans[i][j-1];
				if(j-good>d)
				{
					ans[i][j]=(ans[i][j]+mod-ans[i][j-d-1])%mod;
					if(visited1>0)
					ans[i][j]=(ans[i][j]+ans[i][j-d-2]+mod)%mod;
					visited1=1;
				}
				if(i-a[j]>d)
				{
					ans[i][j]=(ans[i][j]+mod-ans[i-d-1][j])%mod;
					visited2[i]=1;
					if(visited2[j]>0)
					ans[i][j]=(ans[i][j]+ans[i-d-2][j]+mod)%mod;
					visited2[j]=1;
				}
				
			}
			if(grid[i][j]==0)
			{
				ans[i][j]=0;
				visited1=0;
				good=j+1;
				a[j]=i+1;
				visited2[j]=0;
		   }
		}
		   good=0;
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<(ans[r-1][c-1]+mod)%mod;
	return 0;
}
