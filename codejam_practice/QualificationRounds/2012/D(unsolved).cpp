//Only small solved :/
//time up :/ :/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int find(int xi,int xj, int d){
	double a = 2*xi +1, b= 2*xj + 1,c,e;
	int i,j,ans=0;
	for(i=1,j=0;;i+=2,j++){
		c=b/(double)i;
		e= ((double)i)*(sqrt(c*c + a*a));
		if(e>d)break;
	}
	ans+=j;
	for(i=1,j=0;;i+=2,j++){
		c=a/(double)i;
		e= ((double)i)*(sqrt(c*c + b*b));
		if(e>d)break;
	}
	ans+=j;
	return ans;
}

int main(){
	long long t,te,i,j,k,n,m,ans,w,h,d,xi,xj;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string map[50];
	for(te=0;te<t;te++){
		ans=0;
		fin>>w>>h>>d;
		for(i=0;i<h;i++)
			fin>>map[i];
		for(i=0;i<h;i++)
			for(j=0;j<w;j++){
				if(map[i][j]=='X'){
					xi = i;
					xj = j;
				}
			}

		if(xi<d)ans++;
		if(xj<d)ans++;
		if((h-(xi+1))<d)ans++;
		if((w-(xj+1))<d)ans++;
		ans+=find(xi,xj,d);
		ans+=find(xi,w-(xj+1),d);
		ans+=find(h-(xi+1),xj,d);
		ans+=find(h-(xi+1),w-(xj+1),d);
		if((h%2)==1 && (xi)==(h/2)){
			for(i=1;;i++,ans++){
				double c=((double)(xj)/((double)i);
				double e = 2.0*((double)i)*sqrt(c*c + h*h);
				if(e>d)break;
			}
			for(i=1;;i++,ans++){
				w-(xj+1);
			}
		}
		if((w%2)==1 && (xj)==(w/2)){
			for(i=1;;i++,ans++){
				xi;
			}
			for(i=1;;i++,ans++){
				h-(xi+1);
			}
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}