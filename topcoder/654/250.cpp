#include <bits/stdc++.h>
using namespace std;
class SquareScores{
	public:
	double calcexpectation(vector<int>p,string s){	
		long double len[26],score[1001];
		int i,j,n=s.size();
		while(p.size()<26)p.push_back(0);
		for(i=0;i<26;i++)len[i]=0;
		score[0]=0.0;
		for(i=0;i<n;i++){
			if(s[i]!='?'){
				score[i+1]=score[i]+1+len[s[i]-'a'];
				for(j=0;j<26;j++){
					if(j==(s[i]-'a'))len[j]++;
					else len[j]=0;
				}
			}
			else{
				score[i+1]=score[i];
				for(j=0;j<26;j++){
					len[j]=(1+len[j])*(((double)p[j])/100.0);
					score[i+1]+=len[j];
				}
			}
		}
		return score[n];
	}
};