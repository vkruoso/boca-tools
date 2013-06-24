#include <cstdio>

int main() {
    int a, b, c, x, y, z;
    while (scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z) == 6) {
        printf("%d\n",(y/b)*(x/a)*(z/c));
    }
    return 0;
}

