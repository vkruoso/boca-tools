#include <cstdio>
#include <cstring>

using namespace std;
int da[128];
int T;
char s[128];

int main(){
    char *c;
    int r;
    memset(da, 0, sizeof(da));
    da['H'] = 1;
    da['Q'] = 1;
    da['9'] = 1;

    for(scanf("%d", &T); T--;){
        scanf("%s", s);
        r = 0;
        for(c = s; *c; c++)
            r |= da[(int) *c];
        printf(r? "YES\n" : "NO\n");
    }
}
