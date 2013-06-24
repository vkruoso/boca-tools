#include <cstdio>

using namespace std;

int T, N;

int main(){
    for(scanf("%d", &T); T--;){
        scanf("%d", &N);
        printf("%d\n", (N+1)>>1);
    }
}
