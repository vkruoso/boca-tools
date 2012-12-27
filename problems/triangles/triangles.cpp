#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long int

using namespace std;

int n, x[1024], y[1024];
ll v[1024];

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}


int main() {

    while(scanf("%d",&n) and n) {
        for (int i=0;i<n;i++)
            scanf("%d %d",x+i,y+i);
        int tot = 0;
        for (int i=0;i<n;i++) {

            // monta e ordena vetor
            for (int j=0;j<n;j++)
                v[j] = dist2(x[i],y[i],x[j],y[j]);
            sort(v,v+n);

            // sweep
            int k = 1;
            for (int j=1;j<n;j++) {
                if (v[j] == v[j-1]) k++;
                else {
                    tot = tot + (k*(k-1))/2;
                    k = 1;
                }
            }
            tot = tot + (k*(k-1))/2;
        }
        printf("%d\n",tot);
    }

    return 0;
}
