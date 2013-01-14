#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int count[10];

int main() {

    while(scanf("%d %d",&n,&m)==2) {
        int tot = 0;
        for (int i=n;i<=m;i++) {
            memset(count,0,sizeof(count));
            int t = i;
            while (t) {
                count[t%10]++;
                t /= 10;
            }
            bool ok = true;
            for (int j=0;j<=9;j++)
                if (count[j]>=2) {
                    ok = false;
                    break;
                }
            if (ok)
                tot++;
        }
        printf("%d\n",tot);
    }

    return 0;
}
