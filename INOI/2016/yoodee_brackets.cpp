#include <bits/stdc++.h>
using namespace std;

int n,k;                    //global
vector<vector<int> > F_a;    //variables
vector<int> v,b;            //-_-

int F_f(int x,int y) //recursive function(memoized)
{
    if(x>=y) return 0;
    if(F_a[x][y]==-1){
        if(b[y]-b[x]==k){
            F_a[x][y]=max(v[x]+v[y],0) + F_f(x+1,y-1);
        }else{
            int mxm=0;
            for(int i=x;i<y;i++){
                mxm=max(mxm,F_f(x,i)+F_f(i+1,y));
            }
            F_a[x][y]=mxm;
        }
    }
    return F_a[x][y];
}

int main()
{
    cin>>n>>k;
    
    vector<int> tmp(n,-1);
    F_a=vector<vector<int> >(n,tmp);  //initialisaton of 2d vector
    
    v=vector<int>(n);  //some more
    b=vector<int>(n); //initialization
    int i;
    
    for(i=0;i<n;i++){
        cin>>v[i];  //input
    }
    
    for(i=0;i<n;i++){
        cin>>b[i];   //more input
    }
    
    cout<<F_f(0,n-1)<<"\n";  //apparently the main function is fine
    
    return 0;
}