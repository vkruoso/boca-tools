#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tem[26];
int orde[26];
char s[1024];
int T;
int TS = 0;

bool cmp(int a, int b){
    return (tem[a] < tem[b]);
}

int main(){
    int i, R;

    for(scanf("%d\n", &T); T--;){
        fgets(s, 1024, stdin);
        memset(tem, 0, sizeof(tem));
        R = 0;
        for(i = 0; i < 26; i++) orde[i] = i;
        for(i = 0; s[i]; i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                tem[s[i] - 'a']++;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                tem[s[i] - 'A']++;
        }
        sort(orde, orde + 26, cmp);
        for(i = 0; i < 26; i++)
            R += tem[orde[i]] * (i + 1);
        printf("Case #%d: %d\n", ++TS, R);
    }

    return 0;
}
