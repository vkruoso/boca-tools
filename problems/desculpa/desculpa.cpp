#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int , int> ii;

int C, n, tot, cap, i;
ii v[55];
int PD[55][1001];

int resp(int j,int capacidade) {

    memset(PD,0,sizeof(PD));
    for (int i=1;i<=j;i++)
        for (int cap=0;cap<=capacidade;cap++)
            if (v[i].first > cap)
                PD[i][cap] = PD[i-1][cap];
            else
                PD[i][cap] = max(PD[i-1][cap],v[i].second + PD[i-1][cap-v[i].first]);
    return PD[j][capacidade];
}

int main() {
    int T = 1;
    while (scanf("%d %d",&C,&n) and (C != 0 or n != 0)) {
        for (i=1;i<=n;i++) {
            int custol, valor;
            scanf("%d %d", &custol, &valor);
            v[i] = ii(custol,valor);
        }
        printf("Teste %d\n%d\n\n",T++,resp(n,C));
    }
    return 0;
}

