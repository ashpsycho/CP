/*
ID: a1lavan1
LANG: C++
TASK: msquare
*/
#include <bits/stdc++.h>
#define MAX 40320
using namespace std;
int i,j,fact[8]={1,1,2,6,24,120,720,5040};

int getRank(string v){
	int ans=0;
	for(i=0;i<v.size();i++){
		ans+=(fact[7-i]*(v[i]-'1'));
		for(j=i+1;j<v.size();j++)if(v[j]>v[i])v[j]--;
	}
	return ans;
}

string A(string s){
	reverse(s.begin(),s.end());
	return s;
}

string B(string s){
	char c=s[3];
	s[3]=s[2];
	s[2]=s[1];
	s[1]=s[0];
	s[0]=c;
	c=s[4];
	s[4]=s[5];
	s[5]=s[6];
	s[6]=s[7];
	s[7]=c;
	return s;
}

string C(string s){
	char c=s[2];
	s[2]=s[1];
	s[1]=s[6];
	s[6]=s[5];
	s[5]=c;
	return s;
}

int main(){
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");
	long long i,ans,j,k=0,n,m,arr[MAX];
	string par[MAX];
	for(i=0;i<40320;i++)arr[i]=0;
	queue<string>q;
	q.push("12345678");
	arr[0]=1,par[0]="";
	string inp="",a,b;
	while(!q.empty()){
		a=q.front();
		q.pop();
		i=getRank(a);
		b=A(a);
		j=getRank(b);
		if(arr[j]==0){
			arr[j]=1+i;
			par[j]=a+"A";
			q.push(b);
		}
		b=B(a);
		j=getRank(b);
		if(arr[j]==0){
			arr[j]=1+i;
			par[j]=a+"B";
			q.push(b);
		}
		b=C(a);
		j=getRank(b);
		if(arr[j]==0){
			arr[j]=1+i;
			par[j]=a+"C";
			q.push(b);
		}
	}
	for(i=0;i<8;i++){
		fin>>j;
		inp=inp+(char)('0'+j);
	}
	a=inp, b="",k=0;
	while(a!="12345678"){
		i=getRank(a);
		a=par[i];
		b=b+a[8];
		a=a.substr(0,8);
		k++;
	}
	b=A(b);
	fout<<(k)<<"\n"<<b<<"\n";
	return 0;
}