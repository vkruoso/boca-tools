#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char M[64][64];

int main() {

    while(scanf("%d %d",&n,&m) and (n or m)) {
        for (int i=0;i<n;i++)
            scanf("%s",M[i]);
        bool ok=true;
        for (int i=0;i<m;i++) {
            int u,z; u=z=0;
            for (int j=0;j<n;j++)
                if (M[j][i] == '0')
                    z++;
                else
                    u++;
            if (u<2 or z<1) {
                ok=false;
                break;
            }
        }
        printf("%s\n",ok?"YES":"NO");
    }

    return 0;
}
