#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;

string inp[101],ans;
int rows[101],cols[101],i,j,k,n,m,sum,r,c,h,v;

bool calc(){
        if(sum==0)return true;
        if((sum%((h+1)*(v+1)))!=0)return false;
        vector<int> vr, vc;
        vr.push_back(-1);
        vc.push_back(-1);
        for(i=j=0;i<r;i++){
                j+=rows[i];
                if(j>(sum/(h+1)))return false;
                if(j==(sum/(h+1))){
                        vr.push_back(i);
                        j=0;
                }
        }
        if(vr.size()!=(h+2))return false;
        for(i=j=0;i<c;i++){
                j+=cols[i];
                if(j>(sum/(v+1)))return false;
                if(j==(sum/(v+1))){
                        vc.push_back(i);
                        j=0;
                }
        }
        if(vc.size()!=(v+2))return false;
        for(i=1;i<vr.size();i++){
                for(j=1;j<vc.size();j++){
                        n=(sum/((h+1)*(v+1)));
                        for(k=vr[i-1]+1;k<=vr[i];k++){
                                for(m=vc[j-1]+1;m<=vc[j];m++){
                                        if(inp[k][m]=='@')n--;
                                }
                        }
                        if(n!=0)return false;                
                }
        }
        return true;
}

int main(){
        long long t,te;
        cin>>t;
        for(te=0;te<t;te++){
                cin>>r>>c>>h>>v;
                for(i=0;i<r;i++)cin>>inp[i];
                ans="POSSIBLE";
                for(i=0;i<101;i++)rows[i]=cols[i]=0;
                for(i=sum=0;i<r;i++){
                        for(j=0;j<c;j++){
                                if(inp[i][j]!='@')continue;
                                rows[i]++;
                                cols[j]++;
                                sum++;
                        }
                }
                if(!calc())ans="IMPOSSIBLE";
                cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
        }
        return 0;
}
