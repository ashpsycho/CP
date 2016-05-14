/*
ID: a1lavan1
LANG: C++
TASK: zerosum
*/
#include <bits/stdc++.h> 
using namespace std;
int main(){
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	long long i,j,k,n,m,po,curr[10],tot;
	char out[3]={' ','+','-'};
	fin>>n;
	for(i=0,po=(int)round(pow(3,n-1));i<po;i++){
		for(j=n-2,k=i;j>=0;j--,k/=3)curr[j]=(k%3);
		for(j=1,tot=0,k=0;k<(n-1);k++){
			if(curr[k]==0){
				if(j<0)j=j*10-(k+2);
				else j=j*10+(k+2);
			}
			else if(curr[k]==1){
				tot+=j;
				j=(k+2);
			}
			else{
				tot+=j;
	 			j=-(k+2);
	 		}
		}
		tot+=j;
		if(tot==0){
			fout<<1;
			for(j=0;j<(n-1);j++){
				fout<<out[curr[j]]<<(j+2);
			}
			fout<<"\n";
		}
	}
	return 0;
}