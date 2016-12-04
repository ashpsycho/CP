/*
ID: a1lavan1
LANG: C++
TASK: shopping
*/
#include <bits/stdc++.h> 
using namespace std;
struct T{
	int p;
	vector<int>id;
	vector<int> amount;
};
int cost[6][6][6][6][6],curr[5],mid[5];
int i,j,b,offers,amount[5],id[5],price[5];					// b= number of items
T offer[100];
bool isp(int ind){
	for(i=0;i<5;i++)mid[i]=curr[i];
	for(i=0;i<offer[ind].id.size();i++){
		for(j=0;j<b;j++){
			if(id[j]==offer[ind].id[i])break;
		}
		if(j==b||(offer[ind].amount[i]>mid[j]))return false;
		mid[j]-=offer[ind].amount[i];
	}
	return true;
}

void calc(){
	for(int i=0;i<offers;i++){
		if(!isp(i))continue;
		cost[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]]=min(
		cost[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]],
		offer[i].p+cost[mid[0]][mid[1]][mid[2]][mid[3]][mid[4]]);
	}
}

void rec(int index){
	if(index==b){
		cost[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]]=0;
		for(int i=0;i<5;i++)
			cost[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]]+=(price[i]*curr[i]);
		calc();
		return;
	}
	for(int i=0;i<6;i++){
		curr[index]=i;
		rec(index+1);
	}
}

int main(){
	ifstream fin("shopping.in");
	ofstream fout("shopping.out");
	long long i,ans,j,k,n,m;
	fin>>offers;
	for(i=0;i<offers;i++){
		fin>>j;
		while(j--){
			fin>>k>>m;
			offer[i].id.push_back(k);
			offer[i].amount.push_back(m);
		}
		fin>>offer[i].p;
	}
	fin>>b;
	for(i=0;i<5;i++)curr[i]=price[i]=0;
	for(i=0;i<b;i++)fin>>id[i]>>amount[i]>>price[i];
	rec(0);
	for(i=0;i<b;i++)curr[i]=amount[i];
	for(;i<5;i++)curr[i]=0;
	fout<<cost[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]]<<"\n";
	return 0;
}