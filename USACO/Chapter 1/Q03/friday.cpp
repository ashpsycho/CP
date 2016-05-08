/*
ID: a1lavan1
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h> 
#include <fstream>
#define MAX 7
using namespace std;
bool isLeapYear(int n){
	return ((n%400)==0)||((n%4)==0 && (n%100)!=0);
}
int main(){
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	long long i,ans,j,k,n,m=5,arr[MAX], days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	fin>>n;
	for(i=0;i<MAX;i++)arr[i]=0;
	for(i=0;i<n;i++){
		for(k=0;k<12;k++){
			arr[m]++;
			if(k==1 && isLeapYear(i+1900))m=(m+1)%7;
			m=(m+days[k])%7;
		}
	}	
	for(i=0;i<MAX;i++){
		fout<<arr[(i+5)%MAX];
		fout<<(i!=(MAX-1)?' ':'\n');
	}
	return 0;
}