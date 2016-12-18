// #define __DEBUG
#define USEMMIN
// #define USEBTMLIM
#ifndef USEBTMLIM
	#define USEBTMLIM2
#endif

/**
 * This program will cause a compile error
 * when N is not one of {4, 5, 6}
 */

//---------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sc1.h"

#define REP(a,b,c) for(a=b; a<c; ++a)
#define RESET(c,v) memset(c,v,sizeof(c))
#define LEN(X) sizeof(X)/sizeof(X[0])
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

#ifdef __DEBUG
  #define DEBUG printf
  #define DEBUGBIT(c,x,i) REP(i,0,x) printf("%d", ((c&(1LL<<i))?1:0) ); printf("\n")
  #define DEBUGARR(c,x,i) REP(i,0,x) printf(" %d", c[i]); printf("\n")
  #define DEBUGFUNC
  #define DEBREP REP
#else
  #define DEBUG if(0) printf
  #define DEBUGBIT(c,x,i) if(0) REP(i,0,x) printf("%d", ((c&(1LL<<i))?1:0) );
  #define DEBUGARR(c,x,i) if(0) REP(i,0,x) printf(" %d", c[i]);
  #define DEBUGFUNC return;
  #define DEBREP if (0) REP
#endif
//---------------------------------------//
// lintaor1's
//=======================================//

#define INTERNALERROR printf("Program internal error. I wish I knew your test case..\n")
#define ERRORDOSTH printf("Program error. I wish I knew your test case..\n")
#define DISAPPOINTEDMESEEJI printf("Are you sure you are putting the correct test case? Plese help recheck :)\n")

// const
#define NA 3393
#if N == 4
	#define M 4
	#define NN 16
	#define SUM 34
#elif N == 5
	#define M 9
	#define NN 25
	#define SUM 65
#elif N == 6
	#define M 15
	#define NN 36
	#define SUM 111
#endif

bool rec(int);			// recursive to find ans

// the numbers
int X[128];				// list of unused numbers
int XX[128];			// index of unused numbers; -1 means used.
int Xflg;				// unused list flag
long long XXflg;		// used number flag

// the sum
int SR[N+3];			// Sum Row
int SC[N+3];			// Sum Column
int SD1, SD2;			// Sum Diagonal 1:NW-SE 2:NE-SW

// # of black cells on a line
int LR[N+3];			// Lack Row
int LC[N+3];			// Lack Column
int LD1, LD2;			// Lack Diagonal 1:NW-SE 2:NE-SW

// Black cells
int BR[M+3], BC[M+3];	// position on 魔方陣
int BB[N+3][N+3];		// index of black number
int Bflg;				// still black anot?

// Bruting Combination Path
int path[M+3];			// path array
int dir[M+3];			// get lastone from which direction?

// Use Bottom Limit
#if defined(USEMMIN) && defined(USEBTMLIM)
	int btmdir[M+3];
	int lackmin[M+3];
#endif
#ifdef USEBTMLIM2
	int lackmin[M+3];
#endif


//------//
int deb;
void debugoutput(int s[][N]){
	DEBUGFUNC;
	int i,j;
	for(i=0;i<N;++i){for(j=0;j<N;++j){printf(" %3d",s[i][j]);}printf("\n");}
}
//------//


int main()
{
	input(s);
	
	Xflg = 0;
	XXflg = 0LL;
	Bflg = (1<<M)-1;
	RESET(XX,-1);

	//====== Start ======================//
	int i,j,p,q;

	//----- Precompute -----//
	// summing
	REP(i,0,N) REP(j,0,N) SR[i]+=s[i][j];		// Row
	REP(i,0,N) REP(j,0,N) SC[i]+=s[j][i];		// Col
	REP(j,0,N) SD1+=s[j][j];					// Dia1
	REP(j,0,N) SD2+=s[j][N-j-1];				// Dia2

	// counting the lack
	REP(i,0,N) REP(j,0,N) {
		if (!s[i][j]) {
			++LC[j];
			++LR[i];
			if (i==j) ++LD1;
			if (i==N-j-1) ++LD2;
		}
	}

	// flagging used number
	REP(i,0,N) REP(j,0,N) {
		// DEBUG("%d %d %2d ", i, j, s[i][j]);
		// DEBUGBIT(XXflg,NN+1,q);
		if (s[i][j]) {
			XXflg |= (1LL<<s[i][j]);
			// DEBUG("%4d : ", s[i][j]);
			// DEBUGBIT(XXflg,NN+1,q); DEBUG("\n");
		}
	}
	// listing unused number. Sorted asc.
	j=-1;
	REP(i,1,NN+1) {
		if ((XXflg & (1LL<<i)) == 0LL) X[++j]=i;
	}
	// indexing unused number
	REP(i,0,M) XX[X[i]]=i;

	// DEBUG("Xflg: "); DEBUGBIT(Xflg,M,deb);
	// DEBUG("XXflg: "); DEBUGBIT(XXflg,NN+1,deb);
	// DEBUG("X :"); DEBUGARR(X,M,i);
	// DEBUG("XX:"); DEBUGARR(XX,NN+1,i);

	// listing position of black
	q=-1;
	REP(i,0,N) REP(j,0,N) {
		if (!s[i][j]) {
			++q; BR[q]=i; BC[q]=j;
		}
	}
	// indexing black
	REP(q,0,M) {
		BB[BR[q]][BC[q]] = q;
	}

	//----- Main Part -----//
	// generating path. heuristic.
	REP(p,0,M)
	{
		int vmin=100, qmin=-1, d=0;
		#ifdef USEMMIN
			int mmin=100;
			#ifdef USEBTMLIM
				int mdir=0;
			#endif
		#endif
		REP(q,0,M) if (Bflg & (1<<q))
		{
			int r = LR[BR[q]], c = LC[BC[q]]; 
			int v = r + c,
				oneSide = MIN(r,c);
			#ifdef USEMMIN
				int m = oneSide;
			#endif

			// lastone
			if (r==1) {vmin=1; qmin=q; d|=1;}
			if (c==1) {vmin=1; qmin=q; d|=2;}
			if (BR[q]==BC[q] && LD1==1) {vmin=1; qmin=q; d|=4;}
			if (BR[q]==N-BC[q]-1 && LD2==1) {vmin=1; qmin=q; d|=8;}
			if (d!=0) break;

			// diag1
			if (BR[q]==BC[q]) {
				if (r==2 && c==2 && LD1==2) {v=3;}	// special case
				v = MIN( v, oneSide+LD1 );

				#ifdef USEMMIN
					m = MIN( m, LD1 );
				#endif
			}
			// diag2
			if (BR[q]==N-BC[q]-1) {
				if (r==2 && c==2 && LD2==2) {v=3;}	// special case
				v = MIN( v, oneSide+LD2 );

				#ifdef USEMMIN
					m = MIN( m, LD2 );
				#endif
			}

			#ifdef USEMMIN
			if (m<mmin || (m==mmin && v<vmin)) {
				vmin=v; qmin=q; mmin=m;
				#ifdef USEBTMLIM
					if (r==m) {mdir|=1;}
					if (c==m) {mdir|=2;}
					if (BR[q]==BC[q] && LD1==m) {mdir|=4;}
					if (BR[q]==N-BC[q]-1 && LD2==m) {mdir|=8;}
				#endif
			}
			#else
			if (v<vmin) {
				vmin=v; qmin=q;
			}
			#endif
		}

		if (qmin<0) {ERRORDOSTH; return -1;}
		path[p] = qmin;
		dir[p]  = d;
		Bflg &= ~(1<<qmin);
		#if defined(USEMMIN) && defined(USEBTMLIM)
			btmdir[p] = mdir;
			lackmin[p] = mmin;
		#endif
		#if defined(USEMMIN) && defined(USEBTMLIM2)
			lackmin[p] = mmin;
		#endif

		// DEBUG(">> %d %d %d %d %d %d\n", vmin, qmin, d, mmin, BR[qmin], BC[qmin]);
		// DEBUGBIT(~(1<<11), M, deb);
		// DEBUGBIT(Bflg, M, deb);

		// unblack qmin
		--LR[BR[qmin]];
		--LC[BC[qmin]];
		if (BR[qmin]==BC[qmin]) --LD1;
		if (BR[qmin]==N-BC[qmin]-1) --LD2;

	}
	// DEBUGARR(path,M,deb);
	// DEBUGARR(dir,M,deb);

	// getting ans
	if (!rec(0)) {
		DISAPPOINTEDMESEEJI;
		return -2;
	}

	//======= End =======================//
	output(s);
	return 0;
}

bool rec(int p)
{
	// all-filled already
	if (p>=M) {
		// DEBUG("%2d: done\n", p);
		return true;
	}
	//-------------------
	int q=path[p],
		r=BR[q],
		c=BC[q];
	int i;
	// DEBUG("%2d %2d %2d %2d %2d: \n", p, dir[p], q, r, c);
	// DEBUG("  "); DEBUGBIT(Xflg,M,deb);
	// debugoutput(s);

	// last-one case
	if (dir[p]) {
		int v = NA;
		REP(i,0,4)
		{
			if (dir[p]&(1<<i))
			{
				int tv;
				switch (i) {
					case 0: tv = SUM - SR[r]; break;
					case 1: tv = SUM - SC[c]; break;
					case 2: tv = SUM - SD1; break;
					case 3: tv = SUM - SD2; break;
				}
				if (v==NA) {
					v=tv;
				}
				else if (v!=tv) {
					return false;
				}
			}
		}
		// DEBREP(deb,0,p+1) printf(">");
		// DEBUG(" [%d]: %d %d\n", q, v, dir[p]);

		if ( v>NN || v<1  ||  XX[v]==-1  ||  (Xflg&(1<<XX[v])) ) {
			// DEBUG("<<<<< unava\n");
			return false;
		}
		if (SR[r]+v>SUM || SC[c]+v>SUM) return false;
		if (r==c && SD1+v>SUM) return false;
		if (r==N-c-1 && SD2+v>SUM) return false;
		
		//<----
		// set vars
		Xflg |= (1<<XX[v]);
		s[r][c] = v;
		SR[r] += v;
		SC[c] += v;
		if (r==c) SD1 += v;
		if (r==N-c-1) SD2 += v;

		// the rec
		if (rec(p+1)) return true;
		
		// unset vars
		Xflg &= ~(1<<XX[v]);
		s[r][c] = 0;
		SR[r] -= v;
		SC[c] -= v;
		if (r==c) SD1 -= v;
		if (r==N-c-1) SD2 -= v;
		//---->

		return false;
	}

	// normal case
	#if defined(USEMMIN) && defined(USEBTMLIM)
		int maxsum=0;
		REP(i,0,4)
		{
			if (btmdir[p]&(1<<i))
			{
				switch (i) {
					case 0: maxsum = MAX(maxsum, SR[r]); break;
					case 1: maxsum = MAX(maxsum, SC[c]); break;
					case 2: maxsum = MAX(maxsum, SD1); break;
					case 3: maxsum = MAX(maxsum, SD2); break;
				}
			}
		}

		// if (lackmin[p]>10) DEBUG("WHATTT?!?!? %d %d %d\n", p, lackmin[p], btmdir[p]);
		int lack=lackmin[p]-1;
		i=M;
		while (lack-->0) {
			--i;
			if (i<0) break;
			while (Xflg&(1<<i)) --i;
			maxsum += X[i];
		}

		int minallowed = SUM - maxsum;
		if (lack>0) minallowed=1;
	#endif

	#if defined(USEMMIN) && defined(USEBTMLIM2)
		int maxsum = MAX(SR[r], SC[c]);
		if (r==c) maxsum = MAX( maxsum, SD1 );
		if (r==N-c-1) maxsum = MAX( maxsum, SD2 );

		int lack=lackmin[p]-1;
		i=M;
		while (lack-->0) {
			--i;
			if (i<0) break;
			while (Xflg&(1<<i)) --i;
			maxsum += X[i];
		}

		int minallowed = SUM - maxsum;
		if (lack>0) minallowed=1;
	#endif

	REP(i,0,M) if ((Xflg&(1<<i))==0)
	#if defined(USEMMIN) && (defined(USEBTMLIM) || defined(USEBTMLIM2))
		if (X[i]>=minallowed)
	#endif
	{
		int v = X[i];
		// DEBREP(deb,0,p+1) DEBUG(">");
		// DEBUG(" [%d]: %d %d\n", q, v, dir[p]);

		// !!! Assuming the X[] is sorted!
		if (SR[r]+v>SUM || SC[c]+v>SUM) return false;
		if (r==c && SD1+v>SUM) return false;
		if (r==N-c-1 && SD2+v>SUM) return false;
		
		//<----
		// set vars
		Xflg |= (1<<XX[v]);
		s[r][c] = v;
		SR[r] += v;
		SC[c] += v;
		if (r==c) SD1 += v;
		if (r==N-c-1) SD2 += v;

		// the rec
		if (rec(p+1)) return true;
		
		// unset vars
		Xflg &= ~(1<<XX[v]);
		s[r][c] = 0;
		SR[r] -= v;
		SC[c] -= v;
		if (r==c) SD1 -= v;
		if (r==N-c-1) SD2 -= v;
		//---->
	}

	return false;
}

