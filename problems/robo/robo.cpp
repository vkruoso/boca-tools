#include <cstdio>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

int n,m,s;
char grid[128][128];
int x, y, k;
char c[50010];

int main() {

    while(scanf("%d %d %d",&n,&m,&s) and (n or m or s)) {
        for (int i=0;i<n;i++) {
            scanf("%s",grid[i]);
            for (int j=0;j<m;j++)
                if (grid[i][j]!='.' and grid[i][j]!='#' and grid[i][j]!='*') {
                    x = i; y = j;
                    if (grid[i][j] == 'N') k=0;
                    if (grid[i][j] == 'O') k=1;
                    if (grid[i][j] == 'S') k=2;
                    if (grid[i][j] == 'L') k=3;
                }
        }
        scanf("%s",c);
        int resp = 0;
        for (int i=0;i<s;i++) {
            if (c[i] == 'E') k=(k+1)%4;
            if (c[i] == 'D') k=(k-1+4)%4;
            if (c[i] == 'F') {
                int nx = x+dx[k], ny = y+dy[k];
                if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '#') {
                    x = nx;
                    y = ny;
                    if (grid[x][y] == '*') {
                        resp++;
                        grid[x][y] = '.';
                    }
                }
            }
        }
        printf("%d\n",resp);
    }

    return 0;
}
