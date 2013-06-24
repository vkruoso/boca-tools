#include <cstdio>
#include <cstring>

using namespace std;
int h1, m1, h2, m2;

int main() {

    while(scanf("%d %d %d %d",&h1, &m1, &h2, &m2) and (h1 != 0 or m1 != 0 or h2 != 0 or m2 != 0)) {
        int t1 = h1*60 + m1;
        int t2 = h2*60 + m2;
        if (t2 < t1) t2 += 24*60;
        printf("%d\n",t2-t1);
    }

    return 0;
}

