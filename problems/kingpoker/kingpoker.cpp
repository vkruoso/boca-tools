#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> i3;

int N;
i3 v[13*13*13*2];
int a[4];

bool ehset(i3 a) {
    return a.first.first == a.first.second and a.first.second == a.second;
}

bool ehpar(i3 a) {
    return a.first.first == a.first.second or a.first.first == a.second or
        a.first.second == a.second;
}

int getpar(i3 a) {
    if (a.first.first == a.first.second or a.first.first == a.second)
        return a.first.first;
    return a.second;
}

int otro(i3 a) {
    if (a.first.first == a.first.second) return a.second;
    if (a.first.first == a.second) return a.first.second;
    return a.first.first;
}


bool cmp(i3 a, i3 b) {
    if (ehset(a) != ehset(b))
        return !ehset(a);
    if (ehset(a)) return a.second < b.second;
    if (ehpar(a) != ehpar(b))
        return !ehpar(a);
    if (ehpar(a)) {
        int pa = getpar(a), pb = getpar(b);
        if (pa != pb) return pa < pb;
        return otro(a) < otro(b);
    }
    return false;
}

bool empata(i3 a, i3 b) {
    return !cmp(a,b) and !cmp(b,a);
}

int main() {

    N=0;
    for (int i=1;i<=13;i++)
        for (int j=i;j<=13;j++)
            for (int k=j;k<=13;k++)
                v[N++] = i3(ii(i,j),k);
    sort(v,v+N,cmp);
    while (scanf("%d %d %d",a+0,a+1,a+2) and (a[0] or a[1] or a[2])) {
        sort(a,a+3);
        i3 t = i3(ii(a[0],a[1]),a[2]);
        int tt = lower_bound(v,v+N,t,cmp) - v;
        while (tt+1 < N and empata(v[tt],v[tt+1])) tt++;
        if (tt+1 == N)
            printf("*\n");
        else
            printf("%d %d %d\n",v[tt+1].first.first,v[tt+1].first.second,v[tt+1].second);
    }

    return 0;
}
