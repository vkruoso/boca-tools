#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double area[10024];
int N, F, T;

int main(){
    double lb, ub, m;
    int i, n;

    for(scanf("%d", &T); T--;){
        scanf("%d %d", &N, &F);
        F++;
        ub = 0.0;

        for(i = 0; i < N; i++){
            scanf("%lf", &m);
            area[i] = M_PI * m * m;
            ub = max(ub, area[i]);
        }

        lb = 0.0;
        for(int it = 0; it < 100; it++){
            m = (lb + ub) / 2.0;

            n = 0;
            for(i = 0; i < N; i++)
                n += (int) (area[i] / m);

            if(n >= F)
                lb = m;
            else
                ub = m;
        }

        printf("%.6lf\n", (lb + ub) / 2.0);
    }

    return 0;
}
