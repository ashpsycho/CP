#include <bits/stdc++.h>
using namespace std;

int calc(int r,int b, int maxb){
	int ans=0,i,j,k;
	for(i=1;r>=i;i++){
		for(j=0;j<=maxb && r>=i && b>=j;j++){
			ans++;
			r-=i;
			b-=j;
		}
	}
	for(i=i+1;r>=i;i++){
		ans++;
		r-=i;	
	}
	for(i=1;b>=i;i++){
		ans++;
		b-=i;
	}
	return ans;
}

int calc1(int r,int b, int maxb){
	int ans=0,i,j,k;
	for(i=0;r>=i;i++){
		for(j=0;j<=maxb && r>=i && b>=j;j++){
			if((i+j)==0)continue;
			ans++;
			r-=i;
			b-=j;
		}
	}
	for(i=i+1;r>=i;i++){
		ans++;
		r-=i;	
	}
	return ans;
}

int main(){
	int t,te,r,b,i,j,k,ans;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>r>>b;
		ans=0;
		for(i=j=0;j<=b;i++,j+=i){
			ans=max(ans,calc(r,b,i));
			ans=max(ans,calc1(r,b,i));
		}
		swap(r,b);
		for(i=j=0;j<=b;i++,j+=i){
			ans=max(ans,calc(r,b,i));
			ans=max(ans,calc1(r,b,i));
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}