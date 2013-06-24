#include <cstdio>

#define abs(n) (n >= 0 ? n : -(n))

using namespace std;

int main() {

    int T;
    for(scanf("%d",&T);T--;) {
        int x, y;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++) {
                int t;
                scanf("%d",&t);
                if (t) { x= i; y = j; }
            }
        printf("%d\n", abs(x-2) + abs(y-2) );
    }

    return 0;
}
