#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int T, n, m, i;
map <string,string> ma;
string s1, s2;
bool primo;

int main() {

    for(scanf("%d",&T);T;T--) {
        ma.clear();
        scanf("%d %d",&n, &m);
        for (i=0;i<n;i++) {
            cin >> s1;
            scanf("\n");
            getline(cin,s2);
            ma[s1] = s2;
        }
        for(i=0;i<m;i++) {
            getline(cin,s1);
            istringstream ss(s1);
            primo=true;
            while (ss >> s2) {
                if (!primo) printf(" ");
                primo=false;
                if (ma.find(s2) == ma.end())
                    printf("%s",s2.data());
                else
                    printf("%s",ma[s2].data());
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

