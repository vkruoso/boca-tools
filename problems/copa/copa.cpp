#include <cstdio>

using namespace std;

int times,partidas,sum,pts;
char name[15];

int main(){

    while (true){
        scanf("%d %d",&times,&partidas);
        if (times==0 && partidas==0) break;

        sum = 0;
        for (int i=0; i<times; i++){
            scanf("%s %d",name,&pts);
            sum += pts;
        }

        printf("%d\n",partidas*3-sum);
    }

    return 0;
}
