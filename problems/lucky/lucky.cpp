#include <cstdio>
#include <cstring>

using namespace std;

char s[64];

int main() {

    while(scanf("%s",s) and strcmp(s,"0")) {
        int c4, c7;
        c4=c7=0;
        for (int i=0;s[i];i++)
            if (s[i]=='4') c4++;
            else if (s[i]=='7') c7++;
        if (c4==0 and c7==0)
            printf("-1\n");
        else if (c4 >= c7)
            printf("4\n");
        else
            printf("7\n");
    }

    return 0;
}
