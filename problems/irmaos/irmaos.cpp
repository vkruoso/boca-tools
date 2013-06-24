#include <cstdio>
#include <cstring>

using namespace std;

typedef int matriz[128][128];

int p, n, m, k;
matriz M,N;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main() {

    while(scanf("%d %d %d %d",&p,&n,&m,&k) and (p or n or m or k)) {
        matriz *M1 = &M, *M2 = &N;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&M[i][j]);

        while (k--) {
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++) {
                    bool alguem=false;
                    for (int k=0;k<4;k++) {
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if (0 <= ni and ni < n and 0 <= nj and nj < m and
                                (*M1)[ni][nj] == ((*M1)[i][j]-1+p)%p) {
                                (*M2)[i][j] = ((*M1)[i][j]-1+p)%p;
                            alguem=true;
                            break;
                        }
                    }
                    if (!alguem)
                        (*M2)[i][j] = (*M1)[i][j];
                }
            matriz *aux = M1;
            M1 = M2;
            M2 = aux;
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (j) printf(" ");
                printf("%d",(*M1)[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

