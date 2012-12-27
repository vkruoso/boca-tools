#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using namespace std;

char s1[100003];
char s2[100003];
int n, saldo[32], qts[32];

int main() {

    while (scanf("%s %s",s1,s2) and s1[0]!='#') {
    n = strlen(s1);
    memset(saldo,0,sizeof(saldo));
    memset(qts,0,sizeof(qts));
    for (int i=0;i<n;i++) {
        saldo[s1[i]-'A']++;
        saldo[s2[i]-'A']--;
        qts[s1[i]-'A']++;
    }
    int k=0;
    for (int i=0;i<n;i++) {
        // sobrando?
        char old = s1[i];
        if (saldo[s1[i]-'A']>0) {
            // tem alguem antes neg?
            bool antes = false;
            for (int j=0;j<s1[i]-'A';j++)
                if (saldo[j] < 0) {
                    k++;
                    saldo[s1[i]-'A']--;
                    saldo[j]++;
                    s1[i] = j+'A';
                    antes=true;
                    break;
                }
            if (!antes and qts[s1[i]-'A'] == saldo[s1[i]-'A']) { // so obrigado?
               for (int j=s1[i]-'A'+1;j<26;j++)
                if (saldo[j] < 0) {
                    k++;
                    saldo[s1[i]-'A']--;
                    saldo[j]++;
                    s1[i] = j+'A';
                    break;
                }
            }
        }
        qts[old-'A']--;
    }

    printf("%d\n%s\n",k,s1);
    }

    return 0;
}
