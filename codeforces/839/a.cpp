#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n,k,arr[10001],x;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>arr[i];
    for(i=j=0; i<n;i++){
        j+=arr[i];
        x=min(j, 8);
        k-=x;
        j-=x;
        if (k <=0) break;
    }
    if(i==n)cout<<"-1";
    else cout<<(i+1);
    return 0;
}
