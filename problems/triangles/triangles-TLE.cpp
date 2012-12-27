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
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                for (int k=j+1;k<n;k++) {
                    ll d1 = dist2(x[i],y[i],x[j],y[j]);
                    ll d2 = dist2(x[i],y[i],x[k],y[k]);
                    ll d3 = dist2(x[j],y[j],x[k],y[k]);
                    if (d1 == d2 or d1 == d3 or d2 == d3) tot++;
        }
        printf("%d\n",tot);
    }

    return 0;
}
