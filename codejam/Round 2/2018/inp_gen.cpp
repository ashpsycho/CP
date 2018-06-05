#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<"2600\n";
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			if((i+j)==0)continue;
			cout<<i<<" "<<j<<"\n";
		}
	}
	return 0;
}