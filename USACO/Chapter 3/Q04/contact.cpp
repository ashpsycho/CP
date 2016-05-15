/*
ID: a1lavan1
LANG: C++
TASK: contact
*/
#include <bits/stdc++.h> 
#define T pair<int,string>
#define x first
#define y second
#define MAX 200001
using namespace std;
class compare{
public:
	bool operator()(T &a, T &b){
		if(a.x<b.x)return true;
		if(a.x>b.x)return false;
		if(a.y.size()>b.y.size())return true;
		if(a.y.size()<b.y.size())return false;
		return (a.y.compare(b.y)>=0);
	}
};
string binaryToString(int num,int n){
	string ans="";
	for(int i=0;i<n;i++,num/=2){
		ans=((num&1)?"1":"0")+ans;
	}
	return ans;
}
int main(){
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	long long i,ans,j,k,n,m,a,b,len=0,po,calc[4096];
	static char s[MAX];
	string inp;
	fin>>a>>b>>m;
	while(fin>>inp){
		for(i=0;i<inp.size();i++)
			s[len++]=inp[i];
	}
	s[len]='\0';
	priority_queue<T,vector<T>,compare> q;
	//Compute answers
	for(i=a,po=(1<<(a-1));i<=b;i++,po*=2){
		if(len<i)continue;
		for(j=0;j<4096;j++)calc[j]=0;
		for(j=k=0;j<(i-1);j++)k=k*2+(s[j]-'0');
		for(;j<len;j++){
			k=k&(po-1);
			k=k*2+(s[j]-'0');
			calc[k]++;
		}
		for(j=0;j<(2*po);j++)
			q.push(T(calc[j],binaryToString(j,i)));
	}
	for(i=0;i<m && !q.empty() && q.top().x>0;i++){
		T a=q.top();
		fout<<a.x<<"\n";
		for(j=0;!q.empty() && a.x==q.top().x;j++){
			fout<<q.top().y;
			q.pop();
			if((j%6)==5)fout<<"\n";
			else if(!q.empty() && a.x==q.top().x)fout<<" ";
		}
		if((j%6)>0)fout<<"\n";
	}
	return 0;
}