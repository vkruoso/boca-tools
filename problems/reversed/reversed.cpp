#include <cstdio>

using namespace std;

inline int inv(int n) {
    if (n==0) return 0;
    int r = 0;
    while (n) {
        r = 10*r + (n%10);
        n/=10;
    }
    return r;
}

int main() {
    int T, n1, n2;
    for(scanf("%d",&T);T--;) {
        scanf("%d %d",&n1,&n2);
        printf("%d\n",inv( inv(n1) + inv(n2)));
    }

    return 0;
}
