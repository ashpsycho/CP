#include <bits/stdc++.h>
using namespace std;
class FixedDiceGameDiv1{
	public:
	double getExpectation(int a,int b,int c,int d){
		int i,j,k;
		long double arr[2501][2],brr[2501][2],num=0.0,den=0.0;
		for(i=0;i<2501;i++)arr[i][0]=arr[i][1]=brr[i][0]=brr[i][1]=0.0;
		arr[0][0]=brr[0][0]=1.0;
		for(i=0;i<a;i++){
			for(j=0;j<=(i*b);j++){
				for(k=1;k<=b;k++){
					arr[j+k][1]+=(arr[j][0]/((long double)b));
				}
			}
			for(j=0;j<2501;j++){
				arr[j][0]=arr[j][1];
				arr[j][1]=0.0;
			}
		}
		for(i=0;i<c;i++){
			for(j=0;j<=(i*d);j++){
				for(k=1;k<=d;k++){
					brr[j+k][1]+=(brr[j][0]/((long double)d));
				}
			}
			for(j=0;j<2501;j++){
				brr[j][0]=brr[j][1];
				brr[j][1]=0.0;
			}
		}
		
		for(i=1;i<=(a*b);i++){
			for(j=0;j<i && j<=(c*d);j++){
				num+=(arr[i][0]*brr[j][0]*i);
				den+=(arr[i][0]*brr[j][0]);
			}
		}
		if(den==0)return -1.0;
		return (num/den);
	}
};