#include <stdio.h>
#include "sc1.h"

#define M 2*N+2
#define true 1
#define false 0

typedef int LL;
typedef int bool;

bool updateArr(LL i,LL j, int val, LL arr[M]){
	
	LL sum = (N*(1+N*N))/2 - val;
	if((arr[i]>sum)||(arr[N+j]>sum))return false;
	
	arr[i]+=val;
	arr[N+j]+=val;
	if(i == j)arr[N*2]+=val;
	if(i == (N-(j+1)))arr[1+ 2*N]+=val;
	
	return true;
}

void swap(LL *a, LL *b){

	LL c=*a;
	*a=*b;
	*b=c;
}

//Improve this further by implementing & using Queue
bool solveSimple(LL arr[N][N], LL remain[M], LL sum[M], LL *countRemain,LL unused[M+1],LL present[1+N*N]){
    
    if(*countRemain ==0)return true;
	LL i,j,k, y,tot = (N*(1+N*N))/2, reqVal;
	for(i=0;i<M;i++){
		if(remain[i]!=1)continue;
		break;
	}
	k=i;
	if(k<N){
		for(j=0;j<N;j++)if(arr[i][j] == 0)break;
	}
	else if(k<(2*N)){
		j=i-N;
		for(i=0;i<N;i++)if(arr[i][j] == 0)break;
	}
	else if(k == (2*N)){
		for(i=0;i<N;i++)if(arr[i][i]==0)break;
		j=i;
	}
	else if(k == (1 + 2*N)){
		for(i=0;i<N;i++)if(arr[i][N-(i+1)]==0)break;
		j=N-(i+1);
	}
	else return true;
	
	reqVal = tot-sum[k];
	if(sum[k] > tot || reqVal >(N*N) || present[reqVal]==1){
		return false;
	}
	
	updateArr(i,j,reqVal,sum);

	arr[i][j] = reqVal;
	present[reqVal]=1;
	updateArr(i,j,-1,remain);
	
	for(k=0;k<*countRemain;k++)if(unused[k] == reqVal)break;
	swap(&unused[k],&unused[(*countRemain)-1]);
	(*countRemain)--;
	
	return solveSimple(arr,remain,sum,countRemain,unused,present);
}

//Bruteforce with minor optimizations
bool solve1(LL inp[N][N], LL inpRemain[M], LL inpSum[M], LL countRemain,LL inpUnused[M+1],LL inpPresent[1+N*N]){

	// output(inp);				
	LL arr[N][N],i,j,k,l,curr=20, currRemain[3],countCurrRemain=0, total = (N*(1+N*N))/2,x;
	LL remain[M], sum[M], unused[M+1], present[1+N*N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			arr[i][j]=inp[i][j];

	for(i=0;i<M;i++){
		remain[i]=inpRemain[i];
		sum[i]=inpSum[i];
	}
	for(i=0;i<=M;i++)unused[i]=inpUnused[i];
	for(i=0;i<=(N*N);i++)present[i]=inpPresent[i];
	
	if(solveSimple(arr, remain, sum, &countRemain, unused, present) == false)return false;
	if(countRemain == 0){			// Terminate recursion
		for(i=0;i<M;i++)if(sum[i]!=total)break;
		if(i<M)return false;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				s[i][j]=arr[i][j]; 
			}
		}
		return true;
	}
	
	for(i=M-1;i>=0;i--){
		if(remain[i]!=0 && (remain[i]<remain[curr]||curr==20)){
			curr=i;
		}
	}	
	
	//Find row/column/diagonal elements which need to filled
	if(curr <N){ 			// it's a row
		for(i=0;i<N;i++){
			if(arr[curr][i]==0)
				currRemain[countCurrRemain++]=N*curr+i;
		}
	}
	else if(curr<(2*N)){ 	// it's a column
		for(i=0;i<N;i++){
			if(arr[i][curr-N]==0)
				currRemain[countCurrRemain++]=N*(i-1)+curr;
		}
	}
	else if(curr == (2*N)){	// it's the first diagonal
		for(i=0;i<N;i++){
			if(arr[i][i]==0)
				currRemain[countCurrRemain++]=i*(N+1);
		}
	}
	else{					// it's the second diagonal
		for(i=0;i<N;i++){
			if(arr[i][N-(i+1)]==0)
				currRemain[countCurrRemain++]=(N-1)*(i+1);
		}
	}
	
	// If simple solve failed, backtrack
	if(remain[curr] == 2){		//fill 1st element & recurse
		j=currRemain[0]/N;		//current row to fill in
		k=currRemain[0]%N;		//current column to fill in
		
		updateArr(j,k,-1,remain);

		for(i=0;i<countRemain;i++){

			x= total - (sum[curr]+unused[i]); 
			if((sum[curr]+unused[i])>total || x>(N*N) || (x == unused[i]) || present[x]==1 )continue;
			if(updateArr(j,k,unused[i],sum) == false)continue;
			
			arr[j][k]=unused[i];
			present[unused[i]]=1;
			swap(&unused[i],&unused[countRemain-1]);
			
			if(solve1(arr,remain,sum,countRemain-1,unused,present))return true;
			
			swap(&unused[i],&unused[countRemain-1]);
			updateArr(j,k,-1*(unused[i]),sum);	
			present[unused[i]]=0;
			
		}
		arr[j][k]=0;
		updateArr(j,k,1,remain);
	}
	else if(remain[curr] == 3){	//fill first & second element & recurse

		LL j1=currRemain[0]/N;		//current row to fill in
		LL k1=currRemain[0]%N;		//current column to fill in
		updateArr(j1,k1,-1,remain);
		
		j=currRemain[1]/N;		//current row to fill in
		k=currRemain[1]%N;		//current column to fill in
			
		updateArr(j,k,-1,remain);	

		for(i=0;i<countRemain;i++){

			arr[j1][k1]=unused[i];
			present[unused[i]]=1;
			if(!updateArr(j1,k1,unused[i],sum)){
				present[unused[i]]=0;
				continue;
			}
			for(l=0;l<countRemain;l++){	
				if(l==i)continue;
				
				x= total - (sum[curr] + unused[l]); 
				if((sum[curr] + unused[l])>total || 
					x>(N*N) || (x == unused[i]) || (x == unused[l]) 
					|| present[x]==1 )continue;
				if(updateArr(j,k,unused[l],sum) == false)continue;
				arr[j][k]=unused[l];
				present[unused[l]]=1;
				
				if(i>l){
					swap(&unused[i],&unused[countRemain-2]);
					swap(&unused[l],&unused[countRemain-1]);	
				}	
				else{
					swap(&unused[l],&unused[countRemain-2]);
					swap(&unused[i],&unused[countRemain-1]);	
				}
				if(solve1(arr,remain,sum,countRemain-2,unused,present))return true;
				
				LL y;
								
				if(i>l){
					swap(&unused[l],&unused[countRemain-1]);
					swap(&unused[i],&unused[countRemain-2]);
				}
				else{
					swap(&unused[i],&unused[countRemain-1]);
					swap(&unused[l],&unused[countRemain-2]);
					
				}		
				
				updateArr(j,k,-1*unused[l],sum);	
				present[unused[l]]=0;
				
			}
			arr[j][k]=0;

			updateArr(j1,k1,-1*unused[i],sum);	
			present[unused[i]]=0;
			
		}
		arr[j1][k1]=0;
		updateArr(j,k,1,remain);
		updateArr(j1,k1,1,remain);	
	}

	return false;
}

void calc(){
	
	// everything is unsigned char for better complexity since max sum of a row/column is <210
	LL arr[N][N],i,j,k,reqSum = (N*(N*N+1))/2 ,remain[M], 
	sum[M], countRemain=0, unused[M+1], present[N*N+1];	//max size of unused is M+1 = 15
	
	for(i=0;i<M;i++)remain[i] = sum[i] = 0;
	for(i=0;i<=(N*N);i++)present[i]=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			updateArr(i,j,s[i][j],sum);
			present[s[i][j]]=1;

			if(s[i][j]==0){
				updateArr(i,j,1,remain);
			}
		}
	}

	for(i=0;i<(N*N+1);i++){
		if(present[i]==0){
			unused[countRemain++]=i;
		}
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			arr[i][j]=(LL)s[i][j];
	}

	solve1(arr, remain, sum, countRemain, unused, present);
}

int main(){

	int te=0,t,i,j;
	scanf("%d", &t);
	
	while(t--){
		input(s);
		calc();
		output(s);
	}
	
	return 0;
}