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

//ROMAN NUMBERS
string getRomanNumber(int n){
	int i,j,k,po;
	string roman[7]={"I","V","X","L","C","D","M"};
	vector<int> calc[10];
	calc[1].push_back(0);
	calc[2].push_back(0);
	calc[2].push_back(0);
	calc[3].push_back(0);
	calc[3].push_back(0);
	calc[3].push_back(0);
	calc[4].push_back(0);
	calc[4].push_back(1);
	calc[5].push_back(1);
	calc[6].push_back(1);
	calc[7].push_back(1);
	calc[8].push_back(1);
	calc[6].push_back(0);
	calc[7].push_back(0);
	calc[7].push_back(0);
	calc[8].push_back(0);
	calc[8].push_back(0);
	calc[8].push_back(0);
	calc[9].push_back(0);
	calc[9].push_back(2);
	string ans="", temp="";
	for(po=0;n>0;po++, n/=10){
		k=(n%10);
		temp="";
		for(i=0;i<calc[k].size();i++){
			temp+=roman[po*2+calc[k][i]];
		}
		ans=temp+ans;
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

//GRAPH THEORY

// Floyd Warshall O(n^3) All Pair Shortest Paths
for(k=0;k<n;k++){
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(dist[i][j]>(dist[i][k]+dist[k][j]))
				dist[i][j]=dist[i][k]+dist[k][j];
		}
}
	

int main(){
	return 0;
}