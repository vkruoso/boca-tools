#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int m, n, g, k;
ii magia[1005];
int adj[1005][1005];
int nadj[1005];

int monstro[1005][1005];
int nmonstro[1005];

int peso[1005];

int PD[1005];

bool visited[1005];
int dist[1005];

int resp() {
    memset(visited,false,n*sizeof(bool));
    memset(dist,0x3f,n*sizeof(int));
    dist[0] = peso[0];
    int u = 0;
    while (u != -1) {
        int du = dist[u];
        if (u == n-1) return dist[n-1];
        visited[u] = true;
        for (int i=0;i<nadj[u];i++) {
            int viz = adj[u][i];
            int w = peso[viz];
            if (!visited[viz] and dist[viz] > du + w)
                dist[viz] = du + w;
        }

        u = -1;
        int menor = 0x3f3f3f3f;
        for (int i=0;i<n;i++)
            if (!visited[i] and dist[i] < menor) {
                menor = dist[i];
                u = i;
            }
    }
    return -1;
}


//--------------
int matamonstro(int vida) {
    if (vida <= 0) return 0;
    if (PD[vida] != 0) return PD[vida];
    int best = 0x3f3f3f3f;
    for (int i=0;i<m;i++) {
        int tt = magia[i].first + matamonstro(vida-magia[i].second);
        best = min(best,tt);
    }
    return PD[vida] = best;
}
//---------------


bool cmp(ii a, ii b) {
    return a.second/a.first > b.second/b.first;
}

int main() {

    while (scanf("%d %d %d %d",&m,&n,&g,&k), m!=0 or n != 0 or g != 0 or k != 0) {
        for (int i=0;i<m;i++) {
            int mana, dano;
            scanf("%d %d",&mana, &dano);
            magia[i] = ii(mana,dano);
        }
        memset(nadj,0,n*sizeof(int));
        memset(nmonstro,0,n*sizeof(int));
        while (g--) {
            int a, b;
            scanf("%d %d",&a,&b);
            a--; b--;
            adj[a][nadj[a]++] = b;
            adj[b][nadj[b]++] = a;
        }
        while (k--) {
            int sala, vida;
            scanf("%d %d",&sala,&vida);
            sala--;
            monstro[sala][nmonstro[sala]++] = vida;
        }
        memset(PD,0,1003*sizeof(int));
        for (int i=0;i<n;i++) {
            int soma = 0;
            for (int j=0;j<nmonstro[i];j++)
                soma += matamonstro(monstro[i][j]);
            peso[i] = soma;
        }

        printf("%d\n",resp());
    }

    return 0;
}
