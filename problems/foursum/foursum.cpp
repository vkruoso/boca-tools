#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,res,nx0,nx1;
int v[4][4096];
int x[2][4096*4096];

int main(){

  while(scanf("%d",&n) and n!=0){
    for(int i=0;i<n;i++)
      for(int j=0;j<4;j++){
        scanf("%d",&a);
        v[j][i] = a;
      }

    nx0=nx1=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      x[0][nx0++] = v[0][i]+v[1][j];
      x[1][nx1++] = v[2][i]+v[3][j];
    }

    sort(x[1],x[1]+nx1);

    res=0;
    for(int i=0;i<nx0;i++){
      int pos = lower_bound(x[1],x[1]+nx1,-x[0][i]) - x[1];
      if(x[1][pos]==-x[0][i]){
        int pos2 = upper_bound(x[1],x[1]+nx1,-x[0][i]) - x[1];
        res+=(pos2-pos);
      }
    }
    printf("%d\n",res);
  }

  return 0;
}
