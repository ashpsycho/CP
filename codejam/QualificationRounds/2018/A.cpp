#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,te,i,j,k,n,ans;
    string s;
    cin>>t;
    for(te=0;te<t;te++){
        cin>>n>>s;
        priority_queue<int> q;
        for(i=k=0,j=1;i<s.size();i++){
            if(s[i]=='S'){
                k+=j;
                q.push(j);
            }
            else j=j*2;
        }
        ans=0;
        while(k>n && q.top() > 1){
            ans++;
            j=q.top();
            q.pop();
            k-=(j/2);
            q.push(j/2);
        }
        cout<<"Case #"<<(te+1)<<": ";
        if(k>n)cout<<"IMPOSSIBLE";
        else cout<<ans;
        cout<<"\n";
    }
    return 0;
}
