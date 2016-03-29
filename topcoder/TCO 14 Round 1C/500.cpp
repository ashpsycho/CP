#include <bits/stdc++.h>
using namespace std;
class FizzBuzzTurbo{
	public:
	vector<long long>counts(long long A,long long B){
		A--;
		long long a,b,c;
		vector<long long> ans;
		a=(B/3)-(A/3);
		b=(B/5)-(A/5);
		c=(B/15)-(A/15);
		ans.push_back(a-c);
		ans.push_back(b-c);
		ans.push_back(c);
		return ans;
	}
};