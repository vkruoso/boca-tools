#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000003

char s[128];
int val[128];
int T;

int main(){
    int R;
    char *c;

    val['>'] = 8;
    val['<'] = 9;
    val['+'] = 10;
    val['-'] = 11;
    val['.'] = 12;
    val[','] = 13;
    val['['] = 14;
    val[']'] = 15;

    for(scanf("%d", &T); T--;){
        R = 0;
        scanf("%s", s);
        for(c = s; *c; c++)
            R = ((R << 4) | val[(int) *c]) % MOD;
        printf("%d\n", R);
    }

    return 0;
}
