#include <bits/stdc++.h>
#include "sc1.h"
using namespace std;

struct variable {
    int x,y;
    variable (int px, int py) :
        x(px), y(py) {}
} ;

int m = 0;
int sum = 0;
vector<variable> ans;

int a[N][N];
int num[44] = {};
int fr[44] = {};

int rowblk[N] = {};
int colblk[N] = {};
int rowsum[N] = {};
int colsum[N] = {};
int dia1sum = 0;
int dia2sum = 0;
int dia1blk = 0, dia2blk = 0;
int f3[3][N*N];
int f37[37][N*N];
int found = 0;
int minof[N*N];
int maxof[N*N];

map<int,int> e;

int dia1(int x, int y) {
    return x == y;
}

int dia2(int x, int y) {
    return x == (N-y-1);
}

int checkDia(int s[][N]) {
    long d1 = 0 , d2 = 0;
    for (int i = 0; i < N; i ++ ) {
        d1 += s[i][i];
        d2 += s[i][N-i-1];
    }
    if (dia1sum != sum) return 0;
    if (dia2sum != sum) return 0;
    return 1;
}
int checkAnswer(int s[][N]) {
    long d1 = 0 , d2 = 0;
    for (int i = 0; i < N; i ++ ) {
        if (rowsum[i] != sum) return 0;
        if (colsum[i] != sum) return 0;
    }
    if (dia1sum != sum) return 0;
    if (dia2sum != sum) return 0;
    return 1;
}

int outofrange(int s, int e) {
    int smin = s + minof[e];
    int smax = s + maxof[e];
    if (smin > sum || smax < sum) return 1;
    return 0;
}

int modCheck(int s, int m) {
    if (f3[3-s%3][m] == 0) return 1;
    if (f37[37-s%37][m] == 0) return 1;
}

int prepare() {
    int a[N*N];
    int l = 0;
    for (int i = 0; i < m; i ++ )
    if (fr[i] == 0) {
        a[l++] = num[i];
    }

    memset(minof,0, N * N );
    memset(maxof,0, N * N );
    memset(f3,0, 3 * N * N);
    memset(f37,0, 37 * N * N);
    for (int i = 0; i < l; i ++) minof[i + 1] = minof[i] + a[i];
    for (int i = 0; i < l; i ++) maxof[i + 1] = maxof[i] + a[l-i-1];
}

int singleCheck(int s, int m) {
    if (outofrange(s, m)) return 1;
    if (modCheck(s,m)) return 1;
    return 0;
}

int impossible(int s[][N]) {
    prepare();
    if (outofrange(dia1sum, dia1blk)) return 1;
    if (outofrange(dia2sum, dia2blk)) return 1;
    for (int i = 0; i < N; i ++) {
        if (outofrange(rowsum[i], rowblk[i])) return 1;
        if (outofrange(colsum[i], colblk[i])) return 1;
    }
    return 0;
}

int tryout(int pos) {
    if (pos == m) {
        if (checkAnswer(s))
            found = 1;
        return 1;
    }
    if (impossible(s)) {
        return 0;
    }

    for (int i = 0; i < m; i ++ )
        if (fr[i] == 0) {

            fr[i] = 1;
            s[ans[pos].x][ans[pos].y] = num[i];
            rowsum[ans[pos].x] += num[i];
            colsum[ans[pos].y] += num[i];
            rowblk[ans[pos].x] --;
            colblk[ans[pos].y] --;
            if (dia1(ans[pos].x,ans[pos].y)) {
                dia1sum += num[i];
                dia1blk -- ;
            }
            if (dia2(ans[pos].x,ans[pos].y)) {
                dia2sum +=num[i];
                dia2blk -- ;
            }

            tryout(pos+1);

            if (found)
                return 1;

            fr[i] = 0;
            rowsum[ans[pos].x] -= num[i];
            colsum[ans[pos].y] -= num[i];
            rowblk[ans[pos].x] ++;
            colblk[ans[pos].y] ++;
            s[ans[pos].x][ans[pos].y] = 0;
            if (dia1(ans[pos].x,ans[pos].y)) {
                dia1sum -= num[i];
                dia1blk ++ ;
            }
            if (dia2(ans[pos].x,ans[pos].y)) {
                dia2sum -= num[i];
                dia2blk ++ ;
            }
        }
}

int init() {
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cnt = 1000;
    while (cnt -- ) {
        input(s);
        ans.clear();
        e.clear();
        dia2sum = 0;
        dia1sum = 0;
        dia2blk = 0;
        found = 0;
        dia1blk = 0;
        m = 0;
        for (int i = 0; i < N; i ++) {
            rowsum[i] = 0; rowblk[i] = 0;
            colsum[i] = 0; colblk[i] = 0;
        }

        sum = N * (N * N + 1)/2;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++ ) {
                rowsum[i] += s[i][j];
                colsum[j] += s[i][j];
                if (dia1(i,j)) dia1sum += s[i][j];
                if (dia2(i,j)) dia2sum += s[i][j];

                if (s[i][j] == 0) {
                    ans.push_back(variable(i,j));
                    a[i][j] = ans.size();
                    rowblk[i] ++;
                    colblk[j] ++;
                    if (dia1(i,j)) dia1blk ++;
                    if (dia2(i,j)) dia2blk ++;
                }
                else e[s[i][j]] = 1;
            }
        }
        

        for (int i = 1; i <= N * N; i ++)
            if (!e[i]) num[m++] = i;

        tryout(0);

        output(s);
    }
}
