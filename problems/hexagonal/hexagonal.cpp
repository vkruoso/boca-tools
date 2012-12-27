#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dist[1200][1200];
int l, n, taml[128], id[128][128];
int nadj[1200], adj[1200][2400];
char c[4], grid[128][128];
int linha[1200], coluna[1200];

int dx[] = {-1,-1,0,0,1,1};
int dy1[] = {-1,0,-1,1,0,1};
int dy2[] = {-1,0,-1,1,-1,0};
int dy3[] = {0,1,-1,1,-1,0};

int tem[20][1200][2], TT;
int  PD[20][1200][2], TTdist;
int Q[1200], Qini, Qfim;
int enfilered[1200], temdist[1200][1200];


inline void dfs(int ini) {
    TT++;
    Qini = Qfim = 0;
    Q[Qini++] = ini;
    enfilered[ini] = TT;
    dist[ini][ini] = 1;
    while (Qini != Qfim) {
        int u = Q[Qfim++];
        for (int i=0;i<nadj[u];i++) if (enfilered[adj[u][i]] != TT) {
            Q[Qini++] = adj[u][i];
            enfilered[adj[u][i]] = TT;
            dist[ini][adj[u][i]] = dist[ini][u] + 1;
        }
    }
}

inline int lol(int l1, int c1, int c2) {
    if (c1 == c2) return 1;
    if (l1 < l-1) {
        if (c1 < c2) return c2-c1;
        return c1-c2+1;
    }
    if (c1 < c2) return c2-c1+1;
    return c1-c2;
}

int getdist(int v1, int v2) {
    if (v1 < 4) return dist[v1][v2];
    if (v2 < 4) return dist[v2][v1];
    if (temdist[v1][v2] == TTdist)
        return dist[v1][v2];
    int l1 = linha[v1];
    int l2 = linha[v2];
    if (l1 == l2) {
        temdist[v1][v2] = temdist[v2][v1] = TTdist;
        return dist[v1][v2] = dist[v2][v1] = abs(coluna[v1]-coluna[v2]) + 1;
    }
    int votro, c1;
    if (l1 < l2) {
        votro = v2;
        c1 = coluna[v1];
    } else {
        l1 ^= l2;
        l2 ^= l1;
        l1 ^= l2;
        votro = v1;
        c1 = coluna[v2];
    }
    //l1 eh menor
    int best = 0x3f3f3f3f;
    for (int i=0;i<taml[l1+1];i++) {
        int tt = lol(l1,c1,i) + getdist(id[ l1+1 ][ i ], votro);
        if (tt < best) best = tt;
    }
    temdist[v1][v2] = temdist[v2][v1] = TTdist;
    return dist[v1][v2] = dist[v2][v1] = best + 1;

}

int calc(int bm, int u, int pf) {
    if (bm == 0) return 1;
    if (__builtin_popcount(bm)==1) {
        int t = dist[__builtin_ctz(bm)][u];
        return t;
    }
    if (tem[bm][u][pf] == TT)
        return PD[bm][u][pf];

    //concat
    int r = 0x3f3f3f3f;
    int x = (bm-1)&bm;
    while (x) {
        int t1 = calc(x,u,1);
        int t2 = calc(bm^x,u,1);
        int opc = t1+t2-1;
        if (opc < r) r = opc;
        x = (x-1)&bm;
    }
    //folha
    if (pf) {
        //p/ term
        for (int i=0;i<4;i++) if (bm&(1<<i)) {
            int opc = dist[i][u] + calc(bm^(1<<i),i,1) - 1;
            if (opc < r) r = opc;
        }
        //p/ n-terminal concatenador
        for (int i=4;i<n;i++) if (i != u and grid[linha[i]][coluna[i]] == '.') {
            int opc = getdist(u,i) + calc(bm,i,0) - 1;
            if (opc < r) r = opc;
        }
    }
    tem[bm][u][pf] = TT;
    return PD[bm][u][pf] = r;
}

int main() {

    memset(tem,0,sizeof(tem));
    memset(enfilered,0,sizeof(enfilered));
    TT=0;
    memset(temdist,0,sizeof(temdist));
    TTdist=0;
    while (scanf("%d",&l) and l) {
        TTdist++;
        n = 4;
        for (int i=0;i<2*l-1;i++) {
            taml[i] = (i < l ? l+i : l+(2*l-1-1-i));
            for (int j=0;j<taml[i];j++) {
                scanf("%s",c);
                grid[i][j] = c[0];
                id[i][j] = n++;
                linha[id[i][j]] = i;
                coluna[id[i][j]] = j;
            }
        }
        //monta grafo
        memset(nadj,0,n*sizeof(int));
        for (int i=0;i<2*l-1;i++)
            for (int j=0;j<taml[i];j++)
                for (int k=0;k<6;k++) {
                    int *dy;
                    if (i < l-1) {dy = dy1; }
                    else if (i == l-1) {dy = dy2; }
                    else {dy = dy3; }
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if (!(0 <= ni and ni < 2*l-1 and 0 <= nj and nj < taml[ni]))
                        continue;
                    if (grid[i][j] != '.' and grid[i][j] == grid[ni][nj])
                        continue;
                    int v1 = grid[i][j]!='.' ? grid[i][j]-'A' : id[i][j];
                    int v2 = grid[ni][nj]!='.' ? grid[ni][nj]-'A' : id[ni][nj];
                    adj[v1][nadj[v1]++] = v2;
                    adj[v2][nadj[v2]++] = v1;
                }

        for (int i=0;i<n;i++) {
            sort(adj[i],adj[i]+nadj[i]);
            nadj[i] = unique(adj[i],adj[i]+nadj[i])-adj[i];
        }

        for (int i=0;i<4;i++)
            dfs(i);

        //go
        TT++;
        printf("You have to buy %d parcels.\n",calc((1<<4)-2,0,1) - 4);
    }

    return 0;
}
