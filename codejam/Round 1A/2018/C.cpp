#include <bits/stdc++.h>
#define T pair<int,int>
#define TD pair<int, double>
#define x first
#define y second
#define MAX 100001
using namespace std;
int t,te,i,j,k,n,m,p,sum;
TD dp[MAX];
        
double calc(){
        double ans=0.0;
        for(i=m;i>=0;i--){
                if(dp[i].x==0)continue;
                if(p>=(dp[i].y+i+sum))ans=max(ans,dp[i].y+i+sum);
                if(p>=(i+sum) && p<=(dp[i].y+i+sum))ans=p;
        }
        return ans;
}

int main(){
        T inp[101];
        cin>>t;
        double d;
        for(te=0;te<t;te++){
                cin>>n>>p;
                for(i=sum=0;i<n;i++){
                        cin>>inp[i].x>>inp[i].y;
                        sum+=(2*(inp[i].x+inp[i].y));
                }
                for(i=0;i<MAX;i++)dp[i]=T(0,0);
                dp[0]=T(1,0);
                m=0;
                for(i=0;i<n;i++){
                        k=2*min(inp[i].x,inp[i].y);
                        d=(sqrt((inp[i].x*inp[i].x)+(inp[i].y*inp[i].y))*2.0)-k;
                        for(j=m;j>=0;j--){
                                if(dp[j].x==0)continue;
                                dp[j+k].x=1;
                                dp[j+k].y=max(dp[j+k].y, d+dp[j].y);
                                m=max(m,j+k);
                        }
                }
                cout<<std::fixed;
                cout<<"Case #"<<(te+1)<<": "<<setprecision(17)<<calc()<<"\n";
        }
        return 0;
}
