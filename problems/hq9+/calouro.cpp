#include <cstdio>
#include <cstring>

using namespace std;

int T;
char s[128];

int main() {

    scanf("%d",&T);
    for (int caso=0;caso<T;caso++) {
        scanf("%s",s);
        int n = strlen(s);
        bool tem = false;
        for (int i=0;i<n;i++)
            if (s[i]=='H' or s[i]=='Q' or s[i]=='9')
                tem = true;
        if (tem)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
