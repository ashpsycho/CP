#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int main(){
    int left[MAX], right[MAX], arr[MAX], i,j,k,n,t,te;
    scanf("%d",&t);
    for(te=0;te<t;te++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        for(i=j=k=0;i<n;i++){
            if((i%2)==0){
                left[j++]=arr[i];
            }
            else{
                right[k++]=arr[i];
            }
        }
        sort(left, left+j);
        sort(right, right+k);
        for(i=0;i<n;i++){
            if((i%2)==0){
                arr[i]=left[i/2];
            }
            else{
                arr[i]=right[i/2];
            }
        }
        for(i=0;i<(n-1);i++){
            if(arr[i]>arr[i+1])break;
        }
        cout<<"Case #"<<(te+1)<<": ";
        if(i==(n-1))cout<<"OK\n";
        else cout<<i<<"\n";
    }
    return 0;
}
