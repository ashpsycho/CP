#include <bits/stdc++.h>
using namespace std;
class ColorfulChocolates{
	public:
	int maximumSpread(string s,int K){
		int i,j,k,x,y,curr_i,curr_j,n=s.size(),ans=1;
		for(i=0;i<n;i++){
			for(j=1;j<=(n-i);j++){
				for(k=0;k<j;k++)if(s[i]!=s[i+k])break;
				if(k<j)break;
				for(k=K,curr_i=i,curr_j=i+j-1;k>0;){
					for(x=1;x<=curr_i && s[curr_i-x]!=s[i];x++);
					for(y=1;(y+curr_j)<n && s[curr_j+y]!=s[i];y++);
					if(x>curr_i && (y+curr_j)==n)break;
					else if(x>curr_i){
						if(k<(y-1))break;
						k-=(y-1);
						s[curr_j+y]='a';
						curr_j++;
					}
					else if ((y+curr_j)==n){
						if(k<(x-1))break;
						k-=(x-1);
						s[curr_i-x]='a';
						curr_i--;
					}
					else{
						if(x<y){
							if(k<(x-1))break;
							k-=(x-1);
							s[curr_i-x]='a';
							curr_i--;							
						}
						else{
							if(k<(y-1))break;
							k-=(y-1);
							s[curr_j+y]='a';
							curr_j++;
						}
					}
				}
				ans=max(ans,curr_j+1-curr_i);
				for(k=0;k<n;k++)if(s[k]=='a')s[k]=s[i];
			}
		}
		return ans;
	}
};