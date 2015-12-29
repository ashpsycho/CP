#include <bits/stdc++.h>
using namespace std;
class FlipGame{
    public:
    int minOperations(vector<string> g){
        int i,j,n=g.size(),m=g[0].size(),arr[m];
        for(i=0;i<n;i++){
        	for(j=0;j<m;j++)if(g[i][j]=='1')break;
            if(j<m)break;
        }
        if(i==n) return 0;
        for(i=0;i<n;i++){
        	for(j=0;j<m;j++)if(g[i][j]=='0')break;
            if(j<m)break;
        }
        if(i==n)return 1;
        for(j=0;j<m;j++){
            for(i=n-1;i>=0 && g[i][j]==g[n-1][0];i--);
            arr[j]=i;
            if(j>0)arr[j]=max(arr[j],arr[j-1]);
        }
        for(j=0;j<m;j++)
            for(i=n-1;i>arr[j];i--)g[i][j]='1'+'0'-g[i][j];
        return 1+minOperations(g);
    }
};