#include <cstdio>
#include <cstring>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int c[32], n, k;
char s[64];
bool visited[64];
vector<int> adj[64];

int dfs(int u) {
    visited[u] = true;
    int soma=1;
    c[ s[u]-'a' ]++;
    for (int i=0;i<(int)adj[u].size();i++) if (!visited[adj[u][i]])
        soma += dfs(adj[u][i]);
    return soma;
}

int main() {

     while(scanf("%d",&k) and k) {
         scanf("%s",s);
         n = strlen(s);
         for (int i=0;i<n;i++) adj[i].clear();
         for (int i=0;i<k;i++) {
             adj[i].push_back(n-k+i);
             adj[n-k+i].push_back(i);
        }
        memset(visited,false,sizeof(visited));
        int tot=0;
        for (int i=0;i<n;i++) if (!visited[i]) {
            memset(c,0,sizeof(c));
            int N = dfs(i);
            int maior = 0;
            for (int i=0;i<26;i++)
                maior = max(maior, c[i]);
            tot += (N-maior);
        }
        printf("%d\n",tot);
    }
    return 0;
}
