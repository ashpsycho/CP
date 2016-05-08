#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	string input, numbers[10] = {"ZERO","ONE","TWO", "THREE", "FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	int order [10]= {0,6,8,7,5,4,2,3,1,9}, answerCount[10], charCount[26] ;
	char identifier [10] = {'Z','X','G','S','V','F','W','R','O','I'};
	cin>>t;
	for(te=0;te<t;te++){
		cin>>input;
		//Initialization
		for(i=0;i<26;i++)charCount[i]=0;
		for(i=0;i<10;i++)answerCount[i]=0;
		
		for(i=0;i<input.size();i++){
			charCount[input[i]-'A']++;
		}
		for(i=0;i<10;i++){
			//update answerCount array by the count of the unique character(identifier) for the current number defined by order
			answerCount[order[i]]=charCount[identifier[i]-'A'];
			//Decrease count of characters for the current number defined by order
			for(j=0;j<numbers[order[i]].size();j++){
				charCount[numbers[order[i]][j]-'A']-=answerCount[order[i]];
			}
		}
		cout<<"Case #"<<(te+1)<<": ";
		for(i=0;i<10;i++){
			for(j=0;j<answerCount[i];j++)cout<<i;
		}
		cout<<"\n";
	}
	return 0;
}