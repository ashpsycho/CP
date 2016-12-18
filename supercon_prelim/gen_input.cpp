#include <bits/stdc++.h>
using namespace std;

string toStr(int n){
	
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans;
}
int main(){

	int Count,size;
	cin>>Count>>size;
	srand(time(NULL));

	string file = ""+toStr(size)+"by"+toStr(size)+".dat";
	ifstream fin(file.c_str());
	ofstream fout("input.txt");
	
	int i,j,k,n=10,x,rem, curr;
	vector<int> inp[n],v;
	
	for(i=0;i<n;i++){
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				fin>>x;
				inp[i].push_back(x);
			}
		}
	}

	fout<<Count<<"\n";
	for(i=0;i<Count;i++){
	
		k=size*(size-1);
		rem= (size == 6)?15:(size + rand()%k);
		
		curr = rand()%n;
		v=inp[curr];
		
		for(j=0;j<rem;j++){
			k=rand()%(size*size);
			for(x=0;x<k;x++){
				if(v[x%(size*size)]==0)k++;
			}
			while(v[x%(size*size)]==0)x++;
			v[x%(size*size)]=0;
		}
		
		for(j=0;j<v.size();j++){
			fout<<v[j]<<" ";
		}
		fout<<"\n";
	}
}