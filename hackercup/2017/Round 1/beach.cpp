#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long mod=1e9+7;
long long extended_euclid(long long a, long long b, long long &x, long long &y) {  
	long long xx = y = 0;
	long long yy = x = 1;
	while (b) {
		long long q = a/b;
		long long t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}

long long mod_inverse(long long a) {
	long long x, y;
	long long d = extended_euclid(a, mod, x, y);
	return ((x%mod)+mod)%mod;
}

long long ncr(long long n, long long r){
	long long ans=1,den=1;
	for(int i=1,j=n;i<=r;i++,j--){
		ans=(ans*j)%mod;
		den=(den*i)%mod;
	}
	ans=(ans*mod_inverse(den))%mod;
	return ans;
}

vector<long long> v;
long long M;
long long fact[2002];
long long fn(){
	long long ans=0,inv[10000];
	if(v.size()==1)return M;
	sort(v.begin(), v.end());
	long long i,j,k,n=v.size(),sum,x,c1=n,c2=n;	
	for(i=j=0;i<n;i++){
		j+=v[i];
	}
	sum=2*j+1;
	for(i=0;i<10000;i++)if((M+i)>sum)inv[i]=mod_inverse(M+i-sum);
	for(i=1;i<=v[n-1];i++){
		while(v[n-c1]<i)c1--;
		for(j=1,k=-1,c2=n;j<=v[n-1];j++){
			while(v[n-c2]<j)c2--;
			if(sum>(i+j+M))continue;
			if(k==-1){
				x=M-(sum-i-j);
				k=ncr(x+n-2,n-2);
			}
			else{
				k=(k*inv[x+1-(M-sum)])%mod;
				x++;
				k=(k*(x+n-2))%mod;
			}
			ans=(ans+(((k*fact[n-2])%mod)*min(c1,c2)*(max(c1,c2)-1)))%mod;
		}
		if(M>=(sum-i))ans=(ans+(((fact[n-1]*ncr(M+(n-1)-(sum-i),n-1))%mod)*2*c1))%mod;
	}

	if(M>=sum)ans=(ans+(fact[n]*ncr(M+n-sum,n)))%mod;
	return ans;
}

int main(){
	long long t,te,i,j,k,n,m,ans;
	ofstream fout("output.txt");
	fact[0]=1;
	for(i=1;i<2002;i++)fact[i]=(fact[i-1]*i)%mod;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>M;
		v.clear();
		for(i=0;i<n;i++){
			cin>>j;
			v.push_back(j);
		}
		ans=fn();
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}