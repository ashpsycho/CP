#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
int main(){
	static T inp[100001];
    static long long i,j,k=0,n,a,b,m,A,tot,cF,cM,ans,arr[100001],val,ans1;
    cin>>n>>A>>cF>>cM>>m;
    for(i=0;i<n;i++){
        cin>>arr[i];
        inp[i]=T(arr[i],i);
    }
    sort(inp,inp+n);
    for(i=0;i<n;i++)arr[i]=inp[i].x;
    for(j=m,i=n-1;i>=0;i--){
        if(j<(A-arr[i]))break;
        j-=(A-arr[i]);
    }
    if(i<0){
        cout<<(cM*A + cF*n)<<"\n";
        for(i=0;i<n;i++)cout<<A<<" ";
        cout<<"\n";
        return 0;
    }
    val=arr[0];
    for(k=0,tot=1;i<n;i++){
        while((j/(k+1))>(arr[i]-val) && k<i){
            j-=((k+1)*(arr[i]-val));
            k++;
            val=arr[i];
        }
        val+=(j/(k+1));
        j=j%(k+1);
        ans=max(ans,cF*(n-(i+1))+cM*val);
        if(i!=(n-1))j+=(A-arr[i+1]);
    }
    cout<<ans<<"\n";
    ans1=ans;
    for(i=0;i<n;i++)arr[i]=inp[i].x;
    for(j=m,i=n-1;i>=0;i--){
        if(j<(A-arr[i]))break;
        j-=(A-arr[i]);
    }
    val=arr[0];
    for(k=0;i<n;i++){
        while((j/(k+1))>=(arr[k+1]-val) && k<i){
            j-=((k+1)*(arr[k+1]-val));
            k++;
            val=arr[k];
        }
        val+=(j/(k+1));
        j=j%(k+1);
        ans=max(ans,cF*(n-(i+1))+cM*val);
        if(ans==ans1)break;
        if(i!=(n-1))j+=(A-arr[i+1]);
    }
    while(k>=0){
    	arr[k]=val;
    	k--;
	}
	for(k=i+1;k<n;k++)arr[k]=A;
	long long fin[100001];
	for(i=0;i<n;i++){
		fin[inp[i].y]=arr[i];
	}
	for(i=0;i<n;i++)cout<<fin[i]<<" ";
	cout<<"\n";
    return 0;
}
