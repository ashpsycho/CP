#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream fout("input.txt");
	fout<<"1\n16\n";
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			if(i<j)fout<<"1 ";
			else fout<<"0 ";
		}
		fout<<"\n";
	}
	return 0;
}
