#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string to_str(long long n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans+".mp3";
}
class FoxAndMp3{
	public:
	vector<string> playList(int n){
		long long i;
		vector<string> ans;
		for(i=1;ans.size()<min(n,50);){
			ans.push_back(to_str(i));
			if(ans.size()==min(n,50))break;
			i=(i*10);
			while(i>(1LL*n)){
				i/=10;
				while((i%10)==9)i=i/10;
				i++;
			}
		}
		return ans;
	}
};