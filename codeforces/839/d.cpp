#include <bits/stdc++.h>
using namespace std;
long long divi[1000001],mod=1e9+7;
long long po(long long b, long long e){
    long long ans=1,mult=b;
    while(e>1){
        if(e&1)ans=(ans*mult)%mod;
        mult = (mult*mult)%mod;
        e/=2;
    }
    return ans;
}
int main(){
    long long i,j,k,n,x;
    for(i=0;i<1000001;i++)divi[i]=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",&k);
        for(j=2,x=sqrtl(k+1);j<=x;j++){
            if((k%j)!=0)continue;
            divi[j]++;
            divi[k/j]++;
        }
    }
    long long ans=0;
    for(int i=2;i<1000001;i++){
        if(divi[i]==0)continue;
        
        ans=(ans+(divi[i]*po(2,(i-1))))%mod;
    }
    cout<<ans<<"\n";
}
