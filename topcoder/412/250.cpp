#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class ForbiddenStrings{
    public:
    long long countNotForbidden(int n){
        long long i,j,k,dp[31][3][3];
        T dir[9];
        for(i=k=0;i<3;i++)
            for(j=0;j<3;j++,k++)dir[k]=T(i,j);
        if(n==1)return 3;
        if(n==2)return 9;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            	for(k=0;k<31;k++)dp[k][i][j]=0;
       for(i=0;i<3;i++)
            for(j=0;j<3;j++)dp[2][i][j]=1;
       int valid[3][9];
       for(i=0;i<3;i++)
            for(j=0;j<9;j++)valid[i][j]=1;
       valid[0][5]=valid[0][7]=0;
       valid[1][2]=valid[1][6]=0;
       valid[2][1]=valid[2][3]=0;
       for(i=2;i<30;i++){
            for(j=0;j<3;j++){
                for(k=0;k<9;k++){
                    if(!valid[j][k])continue;
                    dp[i+1][dir[k].y][j]+=dp[i][dir[k].x][dir[k].y];
                }
            }
        }
        long long ans=0;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)ans+=dp[n][i][j];
        return ans;
    }
};