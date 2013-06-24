#include <cstdio>

using namespace std;

int n;

int main() {

    while(scanf("%d",&n) and n) {
        int a, b; a=b=0;
        for (int i=0;i<n;i++) {
            int A, B;
            scanf("%d %d",&A,&B);
            if (A > B) a++;
            else if (B > A) b++;
        }
        printf("%d %d\n",a,b);
    }

    return 0;
}
