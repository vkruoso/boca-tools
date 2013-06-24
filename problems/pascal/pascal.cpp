#include <cstdio>
#include <cstring>
using namespace std;

int v[128];
int N,D,x;

int main(){

  while(scanf("%d %d",&N,&D)==2 and N and D){
    memset(v,0,(N+1)*sizeof(int));
    for(int i=0;i<D;i++)
      for(int j=0;j<N;j++){
        scanf("%d",&x);
        v[j]+=x;
      }
    bool deu=false;
    for(int i=0;i<N;i++)
      if(v[i]==D)
        deu=true;
    printf("%s\n",deu?"yes":"no");
  }

  return 0;
}
