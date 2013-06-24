#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

queue<ii> q;
int foi[1024][1024];
int dists[1024][1024];
int TS = 0;
int M, N, X, XX, Y, YY, P, Q;
int dx[8], dy[8];

int main(){
    int i, x, y, xx, yy;
    ii t;
    memset(foi, 0, sizeof(foi));

    while(scanf("%d %d %d %d %d %d %d %d",
            &M, &N, &P, &Q, &X, &Y, &XX, &YY) == 8){

        XX--; X--; YY--; Y--;

        foi[Y][X] = ++TS;
        dists[YY][XX] = -1;
        dists[Y][X] = 0;
        q.push(ii(Y, X));

        dx[0] = P, dy[0] = Q;
        dx[1] = -P, dy[1] = Q;
        dx[2] = P, dy[2] = -Q;
        dx[3] = -P, dy[3] = -Q;
        dx[4] = Q, dy[4] = P;
        dx[5] = -Q, dy[5] = P;
        dx[6] = Q, dy[6] = -P;
        dx[7] = -Q, dy[7] = -P;

        while(q.size()){
            t = q.front();
            q.pop();
            y = t.first, x = t.second;

            for(i = 0; i < 8; i++){
                yy = y + dy[i];
                xx = x + dx[i];

                if(yy < 0 || yy >= N || xx < 0 || xx >= M || foi[yy][xx] == TS)
                    continue;

                foi[yy][xx] = TS;
                dists[yy][xx] = dists[y][x] + 1;
                q.push(ii(yy, xx));
            }
        }

        printf("%d\n", dists[YY][XX]);
    }

    return 0;
}
