
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,k,min=100000;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	int c=0;
	int speed[n],remove[k];
	speed[0]=max(a[0],0);
	for(i=1;i<n;i++)
	{
		if(a[i]>=0)
		{
			speed[i]=max(speed[i-1]+a[i],a[i]);
	    }
	    else
	    {
	    	if(k>0)
	    	{
	    		remove[c]=a[i];
	    		c++;
	    		speed[i]=speed[i-1];
	    		k--;
	    	}
	    	else
	    	{
	    		sort(remove,remove+k);
	    		speed[i]=speed[i-1]+max(remove[0],a[i]);
	    		if(a[i]<remove[0])
	    		remove[0]=a[i];
			}
		}
	}
	sort(speed,speed+n);
	cout<<speed[n-1];
	return 0;
}