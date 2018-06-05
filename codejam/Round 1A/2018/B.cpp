#include <bits/stdc++.h>
using namespace std;
class T{
public:
        long long m,s,p;
        T(){}
        T(long long m1,long long s1,long long p1){
                m=m1;
                s=s1;
                p=p1;
        }
};

T inp[1001] ;
long long r,b,c,i,j,k;

long long maxB(long long tim){
        vector<long long> v;
        for(i=k=0;i<c;i++){
                if(tim<(inp[i].p))continue;
                j=min((tim-inp[i].p)/inp[i].s,inp[i].m);
                v.push_back(j);
        }
        sort(v.begin(),v.end());
        for(i=v.size()-1,j=k=0;j<r && i>=0;j++,i--){
                k+=v[i];
        }
        return k;
}

long long calc(){
        long long beg=0,end=2000000LL*1000000LL*1000000LL,mid=(beg+end)/2;
        while(beg<end){
                if(maxB(mid)>=b){
                        end=mid;
                }
                else{
                        beg=mid+1;
                }
                mid=(beg+end)/2;
        }
        return mid;
}

int main(){
        long long t,te,n,m,ans,s,p;
        cin>>t;
        for(te=0;te<t;te++){
                cin>>r>>b>>c;
                for(i=0;i<c;i++){
                        cin>>m>>s>>p;
                        inp[i]=T(m,s,p);
                }
                ans= calc();
                cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
        }
        return 0;
}
