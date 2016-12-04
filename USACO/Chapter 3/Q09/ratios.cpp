/*
ID: a1lavan1
LANG: C++
TASK: ratios
*/
#include <bits/stdc++.h> 
using namespace std;
class T{
public:
	int x,y,z;
	T(){}
	T(int a,int b,int c){
		x=a;
		y=b;
		z=c;
	}
};
T add(T a, T b){
	return T(a.x+b.x,a.y+b.y,a.z+b.z);
}

T mult(T b,int a){
	return T(b.x*a,b.y*a,b.z*a);
}

int div(T a, T b){
	if((b.x!=0 && (a.x%b.x)>0)||(b.y!=0 && (a.y%b.y)>0)||(b.z!=0 && (a.z%b.z)>0))return 0;
	int x=-1,y=-1,z=-1;
	if(b.x!=0)x=(a.x/b.x);
	else if(a.x!=0)return 0;
	if(b.y!=0)y=(a.y/b.y);
	else if(a.y!=0)return 0;
	if(b.z!=0)z=(a.z/b.z);
	else if(a.z!=0)return 0;
	if((x!=y && x!=-1 && y!=-1) || (y!=z && z!=-1 && y!=-1) || (x!=z && x!=-1 && z!=-1))return 0;
	return max(x,max(y,z));
}

int main(){
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	long long i,ans[4]={101,101,101,101},j,k,n,m;
	T arr[4],a,b;
	for(i=0;i<4;i++){
		fin>>j>>k>>m;
		arr[i]=T(j,k,m);
	}
	for(i=0;i<101;i++){
		for(j=0;j<101;j++){
			for(k=0;k<101;k++){
				a=add(mult(arr[1],i),mult(arr[2],j));
				a=add(a,mult(arr[3],k));
				m=div(a,arr[0]);
				if(m==0)continue;
				if(m<ans[0]){
					ans[0]=m;
					ans[1]=i;
					ans[2]=j;
					ans[3]=k;
				}
			}
		}
	}
	if(ans[0]<101)fout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[0]<<"\n";
	else fout<<"NONE\n";
	return 0;
}