#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char tob[10][3][3] = {
    {".*","**",".."},
    {"*.","..",".."},
    {"*.","*.",".."},
    {"**","..",".."},
    {"**",".*",".."},
    {"*.",".*",".."},
    {"**","*.",".."},
    {"**","**",".."},
    {"*.","**",".."},
    {".*","*.",".."}
};

int n;
char s[128];
map<string, int> M;

int main() {

    M[".***.."]=0;
    M["*....."]=1;
    M["*.*..."]=2;
    M["**...."]=3;
    M["**.*.."]=4;
    M["*..*.."]=5;
    M["***..."]=6;
    M["****.."]=7;
    M["*.**.."]=8;
    M[".**..."]=9;

    while(scanf("%d",&n) and n) {
        scanf("%s",s);
        if (s[0]=='S') {
            scanf("%s",s);
            for (int k=0;k<3;k++) {
                for (int i=0;i<n;i++) {
                    if (i) printf(" ");
                    printf("%s",tob[ s[i]-'0' ][k]);
                }
                printf("\n");
            }
        } else {
            string S[128];
            for (int k=0;k<3;k++) {
                for (int i=0;i<n;i++) {
                    scanf("%s",s);
                    string tt = s;
                    S[i] = S[i] + tt;
                }
            }
            for (int i=0;i<n;i++)
                printf("%d",M[S[i]]);
            printf("\n");
        }
    }

    return 0;
}
