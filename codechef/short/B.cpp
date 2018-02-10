#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll n, p1, p2, ss,x1, y11, x2, y22;
string ans[3]={"Miron", "Slava","Draw"};

int basic(){
	p1=-abs(n+1  - y11*2);
	p2=-abs(n+1  - y22*2);
	ss=0;
	if((n + 1 - y11*2) <0 && (n + 1 - y22*2) <0 )ss=1;
	if((n + 1 - y11*2) >0 && (n + 1 - y22*2) >0 )ss=1;
	if(p1 > (p2 +2 ))return 0;
	if(p2 == (p1 + 4 )) return (ss==0 || (n&1))?1:2;
	if(p2 > (p1 +4 )) return 1;
	if (ss==1){
		if(p1>p2)return 0;
		if(p2>p1 && x1==x2)return 1;
		return 2; 	
	}
	return 3;
}

int odd(){
	if(basic()!=3)return basic();
	if ( p1 == p2 && x1!=x2)return 2;
	if(p2>p1) return (x1 == x2)?1:2;
	return 0;
}

int even(){
	if(basic()!=3)return basic();
	if(p1>p2 && x1==x2)return 0;
	return 2;
}

int main(){
	ll t,te;
	cin>>t;
	for(te=0;te<t;te++){
		cin >> n >> x1 >> y11 >> x2 >> y22;
		if(n<=2)cout<<"Draw\n";
		else if(n&1)cout<<ans[odd()]<<"\n";
		else cout<<ans[even()]<<"\n";
	}
	return 0;
}