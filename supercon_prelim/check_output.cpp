#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;

int main(){

	//N = no of outputs
	//size = size of grid
	int n,size;	
	cin>>n>>size;
	srand(time(NULL));

	T timeTaken[n];
	ifstream fin("rijul_out.txt");
	int i,j,k,x;
	vector<int>v;
	
	for(i=0;i<n;i++){
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				fin>>x;
				v.push_back(x);
			}
		}
		fin>>timeTaken[i].x;
		timeTaken[i].y=i;
	}
	sort(timeTaken, timeTaken+n);

	for(i=0;i<100;i++){
		cout<<timeTaken[n-(i+1)].x<<" for Case #"<<timeTaken[n-(i+1)].y<<"\n";
	}

}