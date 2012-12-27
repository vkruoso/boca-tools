#include <cstdio>
#include <cstring>

using namespace std;

int n, m,C=1;
int x1[128], x2[128], y1[128], y2[128];

int main() {

    while(scanf("%d",&n) and n) {
        for (int i=0;i<n;i++) {
            int r, c, w, h;
            scanf("%d %d %d %d",&r,&c,&w,&h);
            x1[i] = r; y1[i] = c;
            x2[i] = r+h-1; y2[i] = c+w-1;
        }
        scanf("%d",&m);
        printf("Desktop %d:\n",C++);
        for (int i=0;i<m;i++) {
            int r, c;
            scanf("%d %d",&r,&c);
            bool ok = false;
            for (int j=n-1;j>=0;j--)
                if (x1[j] <= r and r <= x2[j] and y1[j] <= c and c <= y2[j]) {
                    ok = true;
                    printf("window %d\n",j+1);
                    break;
                }
            if (!ok) printf("background\n");
        }
    }

    return 0;
}
