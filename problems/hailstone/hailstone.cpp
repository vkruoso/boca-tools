#include <cstdio>
#include <cstring>

using namespace std;

int n;

int main() {

    while(scanf("%d",&n) and n) {
        int h = n;
        int maior = h;
        while (h != 1) {
            if ((h%2)==0)
                h = h/2;
            else
                h = 3*h + 1;
            if (h > maior)
                maior = h;
        }
        printf("%d\n",maior);
    }

    return 0;
}
