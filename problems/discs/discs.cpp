#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n1,n2,d,a,b,res1,res2;
vector<int> adj[100010];
int inc[100010];
int incb[100010];
bool removed[100010];
queue<int> q1,q2;

void explore(int u,int t){
  if(removed[u]) return;
  inc[u]--;
  if(inc[u]==0){
    if(u<n1) t==0 ? q1.push(u) : q2.push(u);
    else t==0 ? q2.push(u) : q1.push(u);
  }
}

int simulate(int t){
  int res=2,p;
  int totrem=0;
  bool removedA=false,removedB=false;

  memset(removed,false,(n1+n2)*sizeof(bool));
  for(int i=0;i<n1;i++)     if(inc[i]==0) t==0 ? q1.push(i) : q2.push(i);
  for(int i=n1;i<n1+n2;i++) if(inc[i]==0) t==0 ? q2.push(i) : q1.push(i);

  while(totrem<n1+n2){
    removedA=false;
    while(!q1.empty()){
      if(removedB){ res++; removedB=false; }
      p = q1.front(); q1.pop();
      for(int i=0;i<(int)adj[p].size();i++) explore(adj[p][i],t);
      removed[p]=true;
      totrem++;
      removedA=true;
    }

    removedB=false;
    while(!q2.empty()){
      if(removedA){ res++; removedA=false; }
      int p = q2.front(); q2.pop();
      for(int i=0;i<(int)adj[p].size();i++) explore(adj[p][i],t);
      removed[p]=true;
      totrem++;
      removedB=true;
    }
  }
  while(!q1.empty()) q1.pop();
  while(!q2.empty()) q2.pop();
  return res;
}

int main(){

  while(scanf("%d %d %d",&n1,&n2,&d)==3){
    if(n1==0 and n2==0 and d==0) break;

    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    memset(inc,0,(n1+n2)*sizeof(int));
    for(int i=0;i<n1+n2;i++) adj[i].clear();
    for(int i=0;i<d;i++){
      scanf("%d %d",&a,&b); a--,b--;
      adj[b].push_back(a);
      inc[a]++;
    }
    memcpy(incb,inc,(n1+n2)*sizeof(int));

    res1 = simulate(0);
    memcpy(inc,incb,(n1+n2)*sizeof(int));
    res2 = simulate(1);
    printf("%d\n",min(res1,res2));
  }

  return 0;
}
