#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
class T{
	public:
	int x,y,z;
	T(){};
	T(int x1,int y1,int z1){
		x=x1;
		y=y1;
		z=z1;
	}
};
bool fn(T a, T b){
	if(a.z>b.z)return true;
	if(a.z<b.z)return false;
	if(a.x<b.x)return false;
	if(a.x>b.x)return true;
	return (a.y>b.y);
}
void printBits(int n,int len){
	string s="";
	while(len--){
		s+=(char)('0'+(n%2));
		n=n/2;
	}
	reverse(s.begin(),s.end());
	cout<<s<<" ";
}
int main(){
	static int t,te,i,j,k,n,m,anslen,a,b,arr[MAX];
	cin>>a>>b>>anslen;
	string s="";
	char c;
	while(cin>>c && c!='2' )s+=c;
	int freq[13][4096];
	for(i=0;i<13;i++)
		for(j=0;j<4096;j++)freq[i][j]=0;
	for(i=a;i<=b;i++){
		te=(1<<i);
		for(j=k=0;j<i;j++)k=k*2 + (s[j]-'0');
		freq[i][k]++;
		for(j=i;j<s.size();j++){
			k=k*2;
			k+=(s[j]-'0');
			k=k%te;
			freq[i][k]++;
		}
	}
	vector<T> v;
	for(i=a;i<=b;i++)
		for(j=0;j<4096;j++)v.push_back(T(i,j,freq[i][j]));
	sort(v.begin(),v.end(),fn);
	for(i=j=0;i<anslen && j<v.size();i++){
		if(v[j].z==0)break;
		cout<<v[j].z<<" ";
		for(k=j;k<v.size()&&v[k].z==v[j].z;k++)printBits(v[k].y,v[k].x);
		cout<<"\n";
		j=k;
	}
	return 0;
}