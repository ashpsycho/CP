#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;

//CONSTANTS
days[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 		//DEFINITELY USE WITH isLeapYear




// Time related functions
bool isLeapYear(int n){
	return ((n%400)==0)||((n%4)==0 && (n%100)!=0);
}

int main(){
	return 0;
}