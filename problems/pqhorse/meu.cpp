#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

int n, m, p ,q, x1, y1, x2, y2;

typedef pair<int,int> ii;
typedef pair<ii,int> i3;
bool enfilered[1024][1024];

int main() {

    while(scanf("%d %d %d %d %d %d %d %d",&n,&m,&p,&q,&x1,&y1,&x2,&y2)==8) {
        if (x1==x2 and y1==y2) { printf("0\n"); continue; }
        x1--; x2--; y1--; y2--;
        memset(enfilered,false,sizeof(enfilered));
        queue<i3> Q;
        int resp=-1;
        Q.push(i3(ii(x1,y1),0));
        enfilered[x1][y1] = true;
        while (!Q.empty()) {
            int x = Q.front().first.first, y = Q.front().first.second;
            int du = Q.front().second; Q.pop();
            for (int k=0;k<4;k++) for (int tt=0;tt<2;tt++) {
                int nx = x + (tt ? p: q)*dx[k];
                int ny = y + (tt ? q: p)*dy[k];
                if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) continue;
                if (enfilered[nx][ny]) continue;
                if (nx==x2 and ny==y2) { resp = du+1; goto fim; }
                Q.push(i3(ii(nx,ny),du+1));
                enfilered[nx][ny] = true;
            }
        }
        fim: printf("%d\n",resp);
    }

    return 0;
}
