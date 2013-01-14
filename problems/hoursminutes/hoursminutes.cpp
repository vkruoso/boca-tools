#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int n;
    while(scanf("%d",&n) == 1) {
        printf("%c\n",((n%6)==0 and n<=180)?'Y':'N');
    }

    return 0;
}
