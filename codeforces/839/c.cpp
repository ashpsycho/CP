#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
double p[100001];
int chil[100001],vis[100001],dis[100001],pa[100001];
int main(){
    int i,j,k,n,m;
    cin>>n;
    for(i=0;i<=n;i++){
        p[i]=vis[i]=dis[i]=0;
        chil[i]=0;
    }
    for(i=1;i<n;i++){
        cin>>j>>k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    p[1]=vis[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        for(j=0,k=q.size();j<k;j++){
            i=q.front();
	    q.pop();
            if(i!=1){
                dis[i]=dis[pa[i]]+1;
                p[i]=p[pa[i]]/(double)chil[pa[i]];
            }
            for(m=0;m<adj[i].size();m++){
                if(vis[adj[i][m]]==1)continue;
                q.push(adj[i][m]);
                vis[adj[i][m]]=1;
                pa[adj[i][m]]=i;
                chil[i]++;
            }
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        cerr<<i<<" "<<chil[i]<<" "<<p[i]<<" "<<dis[i]<<"\n";
        if(chil[i]==0)ans+=(p[i]*dis[i]);
    }
    cout<<setprecision(12)<<ans<<"\n";
    return 0;
}
