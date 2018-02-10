#include <bits/stdc++.h>
using namespace std;
int arr[10001];
string solve (int n,int k){
    if(n<0)return "NO";
    int i,j,fo=n,tw=(2*n),on=0;
    for(i=0;i<k;i++){
        if(arr[i]<4)continue;
        if(fo>0)fo--;
        else if(tw>1)tw-=2;
        else return "NO";
        arr[i]-=4;
    }
    for(i=0;i<k;i++){
        if(arr[i]<2)continue;
        if(tw>0)tw--;
        else if(fo>0){
            fo--;
            on++;
        }
        else return "NO";
        arr[i]-=2;
    }
    on+=(fo*2);
    on+=tw;
    for(i=j=0;i<k;i++){
        j+=arr[i];
    }
    return (j>on)?"NO":"YES";
}
int main(){
    int n,k,i;
    cin>>n>>k;  //number of rows & types
    for(i=0;i<k;i++)cin>>arr[i];
    for(i=0;i<k;i++){
        n-=(arr[i]/8);
        arr[i]=arr[i]%8;
    }
    cout<<solve(n,k);
    return 0;
}
