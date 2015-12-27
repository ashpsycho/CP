#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,a,b,fir[4][4],sec[4][4];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>a;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)fin>>fir[i][j];
		fin>>b;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)fin>>sec[i][j];
		vector<int> s1,s2;
		a--,b--;
		for(i=0;i<4;i++){
			s1.push_back(fir[a][i]);
			s2.push_back(sec[b][i]);
		}
		for(i=k=0;i<4;i++){
			for(j=0;j<4;j++){
				if(s1[i]==s2[j])break;
			}
			if(j<4){
				k++;
				ans=s1[i];
			}
		}
		if(k==1){
			fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
			cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		}
		else if(k==0){
			fout<<"Case #"<<(te+1)<<": "<<"Volunteer cheated!"<<"\n";
			cout<<"Case #"<<(te+1)<<": "<<"Volunteer cheated!"<<"\n";
		}
		else{
			fout<<"Case #"<<(te+1)<<": "<<"Bad magician!"<<"\n";
			cout<<"Case #"<<(te+1)<<": "<<"Bad magician!"<<"\n";
		}
	}
	return 0;
}