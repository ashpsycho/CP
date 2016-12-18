#include<stdio.h>
#include<stdlib.h>
#include "sc1.h"

typedef int bool;
#define true 1
#define false 0

#define NOT_POSSIBLE -1
#define POSSIBLE 0
#define CORRECT 1

int req_sum = 111;
bool check(int s[N][N]){
	
	// check all row sum
	int j, i; 
	for (j = 0; j < N; j++){
		int sum = 0;
		bool zeroFound = false;
		for (i = 0; i < N; i++){
			sum += s[i][j];
			if (s[i][j] == 0){
				zeroFound = true;
				break;
			}
		}
		if (zeroFound == true) return false;
		if (sum != req_sum) return false;
		sum = 0;
		for (i = 0; i < N; i++){
			sum += s[j][i];
		}
		if (sum != req_sum) return false;
	}

	int sum = 0;
	for (i = 0, j = 0; i < N && j < N; i++, j++){
		sum += s[i][j];
	}
	if (sum != req_sum) return false;

	sum = 0;
	for (i = 0, j = N-1; i < N; i++, j--){
		sum += s[i][j];
	}
	if (sum != req_sum) return false;
	return true;
}

bool can_put(int *r, int *c){	

	int r_sum = req_sum;
	// check the row 
	bool zero_found = false;
	int sum = 0, i, j ,k;
	for (i = 0; i < N; i++){		
		if (s[*r][i] == 0){
			zero_found = true;
			break;
		}
		sum += s[*r][i];
	}
	if (zero_found == false && sum != req_sum) return false;

	// check the column
	zero_found = false;
	sum = 0;
	for ( i = 0; i < N; i++){
		if (s[i][*c] == 0){
			zero_found = true;
			break;
		}
		sum += s[i][*c];
	}
	if (zero_found == false && sum != req_sum) return false;
	// diagonal
	if (*r == *c){
		sum = 0; 
		zero_found = false;
		for ( i = 0, j = 0; i < N; i++, j++){
			if (s[i][j] == 0){
				zero_found = true;
				break;
			}
			sum += s[i][j];
		}
		if (zero_found == false && sum != req_sum) return false;
	}
	// diagonal 
	if (*r == (N - *c - 1)){
		sum = 0;
		zero_found = false;
		for ( i = 0, j = N-1; i < N; i++, j--){
			if (s[i][j] == 0){
				zero_found = true;
				break;
			}
			sum += s[i][j];
		}
		if (zero_found == false && sum != req_sum) return false;
	}

	return true;

}

int getMinZero(int *r, int *c){

	int ret = N, cnt = 0, i, j;

	for (i = 0; i < N; i++){
		if (s[i][*c] == 0) cnt++;
	}
	if (ret>cnt) ret = cnt;

	cnt = 0;

	for ( i = 0; i < N; i++){
		if (s[*r][i] == 0) cnt++;
	}
	if (ret>cnt) ret = cnt;

	if (*r == *c){
		cnt = 0;
		for ( i = 0, j = 0; i < N; i++, j++){
			if (s[i][j] == 0) cnt++;
		}
		if (ret>cnt){
		 	ret = cnt;
		}
	}

	if (*r == (N - *c - 1)){
		cnt = 0;
		for ( i = 0, j = N-1; i < N; i++, j--){
			if (s[i][j] == 0) cnt++;
		}
		if (ret>cnt){
			ret = cnt;
		}
	}

	
	return ret;
}

bool back_track(int s[N][N], bool num[]){
	

	int i = 0, j = 0;
	int min_zero = N;
	int r = N, c = N;
	int zero;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (s[i][j] == 0){
				zero = getMinZero(&i, &j);
				if (min_zero>zero){
					min_zero = zero;
					r = i, c = j;
				}
			}
		}
	}

	if (r >= N){
		bool decision = check(s);
		return decision;
	}

	for (i = 1; i <= N*N; i++){
		if (num[i]) continue;
		s[r][c] = i;
		if (!can_put(&r, &c)) {
			s[r][c] = 0;
			 continue;
		}
		num[i] = true;
		if (back_track(s, num)) return true;
		s[r][c] = 0;
		num[i] = false;
	}	
	
	return false;
}

bool validate(){
	int i,j,k, Count[1+N*N],sum=((1+N*N)*N)/2;

	for(i=0;i<N;i++){
	//Check rows
		for(j=k=0;j<N;j++){
			k+=s[i][j];
		}
		if(k!=sum)return false;
	//Check columns
		for(j=k=0;j<N;j++){
			k+=s[j][i];
		}
		if(k!=sum)return false;
	}
	//Check diagonals
	for(i=j=k=0;i<N;i++){
		j+=s[i][i];
		k+=s[i][N-(i+1)];
	}
	if((j!=sum)||(k!=sum))return false;

	//Check count
	for(i=0;i<=(N*N);i++)Count[i]=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Count[s[i][j]]++;
		}
	}
	for(i=1;i<=(N*N);i++)if(Count[i]==0)return false;
	
	return true;
}

int main(){

	freopen("input.txt", "r", stdin);

	int cnt = 100000, i , j;

	while (cnt--){
		input(s);

		bool num[(N*N) + 1];

		int total_gap = 0;
		for ( i = 0; i <= N*N; i++){
			num[i] = 0;
		}

		for ( i = 0; i < N; i++){
			for ( j = 0; j < N; j++){
				num[s[i][j]] = 1;
			}
		}
		int result = back_track(s, num);

		printf("%d\n", result);

		output(s);

		if(!validate()){

			printf("Validation failed!\n");
			return 0;
		}
	
	}

	return 0;
}