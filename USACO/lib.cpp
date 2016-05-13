#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;

//CONSTANTS
days[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 		//DEFINITELY USE WITH isLeapYear

// Time related functions
bool isLeapYear(int n){
	return ((n%400)==0)||((n%4)==0 && (n%100)!=0);
}

// MATRIX MANIPULATION

T rotateRight(T a,int n){	// rotate an NxN matrix clockwise by 90
	return T(a.y,n-(1+a.x));
}

//STRING MANIPULATION

bool isPalin(string s){
	for(int i=0,n=s.size();i<(n/2);i++)
		if(s[i]!=s[n-(i+1)])return false;
	return true;
}

int stringToInt(string s){
	stringstream fin;
	fin<<s;
	int n;
	fin>>n;
	return n;
}

string intToString(int s){
	stringstream fin;
	fin<<s;
	string n;
	fin>>n;
	return n;
}

void generatePalin(int len){
	string curr;
	int i,j,k,m=pow(10,(len+1)/2);
	for(i=pow(10,(len-1)/2);i<m;i++){
		curr=intToString(i);
		for(j=curr.size()-(1+(len%2));j>=0;j--)curr+=curr[j];
		//process curr here
	}
}

//BASE CONVERSION

string toBase(int base,int num){
	string ans="";
	char all[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	while(num>0){
		ans=all[num%base]+ans;
		num/=base;
	}
	return ans;
}

//NUMBER THEORY

//CHECK PRIME SIMPLE
bool isPrime(int n){
	int i;
	if(n<2)return false;
	for( i=2;(i*i)<=n;i++)if((n%i)==0)break;
	return ((i*i)>n);
}


//Vector Intersection


vector<int> intersect(vector<int> a,vector<int> b){
	//sort(a.begin(),a.end());
	//sort(b.begin(),b.end());
	vector<int> ans;
	for(int i=0,j=0;i<a.size() && j<b.size();){
		if(a[i]<b[j])i++;
		else {
			if(a[i]==b[j])ans.push_back(a[i]);
			j++;
		}
	}
	return ans;
}



int main(){
	return 0;
}