#include <bits/stdc++.h>
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;

string to_str(long long a){
	stringstream inp;
	inp<<a;
	string ans;
	inp>>ans;
	return ans;
}

string square_str(string s){
	int i,j,n=s.size(),arr[2*n],brr[2*n];
	for(i=0;i<(2*n);i++){
		arr[i]=brr[i]=0;
	}
	reverse(s.begin(),s.end());
	for(i=0;i<n;i++){
		arr[i]=s[i]-'0';
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			brr[i+j]+=(arr[i]*arr[j]);
		}
	}
	for(i=0;i<(2*n);i++){
		brr[i+1]+=(brr[i]/10);
		brr[i]=brr[i]%10;
	}
	string ans="";
	for(i=(2*n)-1;i>=0 && brr[i]==0;i--);
	for(;i>=0;i--)ans=ans+(char)('0'+brr[i]);
	return ans;
}

long long to_int(string s){
	stringstream inp;
	inp<<s;
	long long ans;
	inp>>ans;
	return ans;
}

bool ispalin(string s){
	int i,n=s.size();
	for(i=0;i<(n/2);i++)if(s[i]!=s[n-(i+1)])return 0;
	return 1;
}

queue<string>q,q1;

void check(){
	while(!q1.empty())q1.pop();
	int i,n=q.size();
	string a,b;
	for(i=0;i<n;i++){
		a=q.front();
		q.pop();
		b=square_str(a);
		if(ispalin(b))q1.push(a);
	}
	while(!q1.empty()){
		q.push(q1.front());
		q1.pop();
	}
}

int str_cmp(string a,string b)  // -1 if a<b numerically , 0 & 1 for others
{
	if(a.size()<b.size()){
		return -1;
	}
	else if(a.size()>b.size()){
		return 1;
	}
	int i;
	for(i=0;i<a.size() && a[i]==b[i];i++);
	if(i==a.size())return 0;
	if(a[i]<b[i])return -1;
	return 1;
}


int main(){
	long long t,te,i,j,k,n,m,a,b;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string x,y,z;
	
	q.push("1");
	q.push("2");
	q.push("3");
	vector<string> ans;
	for(i=1;i<52;i++){
		check();
		while(!q1.empty())q1.pop();
		while(!q.empty()){
			x=q.front();
			ans.push_back(square_str(x));
			q.pop();
			if(i&1){
				j=(x.size()/2);
				q1.push(x.substr(0,(x.size()/2))+x[j]+x[j]+x.substr(j+1,(x.size()/2)));
			}
			else{
				j=(x.size()/2);
				q1.push(x.substr(0,x.size()/2)+"0"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"1"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"2"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"3"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"4"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"5"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"6"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"7"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"8"+x.substr(j,x.size()/2));
				q1.push(x.substr(0,x.size()/2)+"9"+x.substr(j,x.size()/2));
			}
		}
		while(!q1.empty()){
			q.push(q1.front());
			q1.pop();
		}
	}
	cout<<ans.size();
	fin>>t;
	for(te=0;te<t;te++){
		fin>>x>>y;
		for(i=j=0;i<ans.size();i++){
			if(str_cmp(y,ans[i])<0)continue;
			if(str_cmp(x,ans[i])>0)continue;
			j++;
		}

		fout<<"Case #"<<(te+1)<<": "<<j<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<j<<"\n";
	}
	return 0;
}
