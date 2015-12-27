#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class AB{
	public:
	string createString(int N,int K){
		int i,j,k=(N/2);
		string ans="";
		if(K>(k*(N-k)))return "";
		for(i=0;i<k;i++)ans+="A";
		for(;i<N;i++)ans+="B";
		for(j=k*(N-k);j>K;j--){
			for(i=0;i<(N-1);i++)if(ans[i]=='A' && ans[i+1]=='B')break;
			swap(ans[i],ans[i+1]);
		}
		return ans;
	}	
};