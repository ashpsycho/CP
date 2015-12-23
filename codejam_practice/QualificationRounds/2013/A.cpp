#include <bits/stdc++.h>
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,ora;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string inp[4],s;
	T check[10][4]={
		{T(0,0),T(0,1),T(0,2),T(0,3)},
		{T(1,0),T(1,1),T(1,2),T(1,3)},
		{T(2,0),T(2,1),T(2,2),T(2,3)},
		{T(3,0),T(3,1),T(3,2),T(3,3)},
		{T(0,0),T(1,0),T(2,0),T(3,0)},
		{T(0,1),T(1,1),T(2,1),T(3,1)},
		{T(0,2),T(1,2),T(2,2),T(3,2)},
		{T(0,3),T(1,3),T(2,3),T(3,3)},
		{T(0,0),T(1,1),T(2,2),T(3,3)},
		{T(0,3),T(1,2),T(2,1),T(3,0)},
	};
	for(te=0;te<t;te++){
		m=0;
		for(i=0;i<4;i++)fin>>inp[i];
		for(i=0;i<10;i++){
			ora =0;
			for(j=0;j<4;j++){
				if(inp[check[i][j].x][check[i][j].y]=='X')ora |= 1;
				else if(inp[check[i][j].x][check[i][j].y]=='T');
				else if(inp[check[i][j].x][check[i][j].y]=='O')ora |= 2;
				else ora|=4;
			}
			if(ora ==1 || ora == 2)break;
			else if(ora&4)m=1;
		}
		if(ora ==1)s="X won";
		else if(ora == 2)s="O won";
		else if(m==1)s="Game has not completed";
		else s="Draw";

		fout<<"Case #"<<(te+1)<<": "<<s<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<s<<"\n";
	}
	return 0;
}
