const int N= 1e5+5,LOG= 20;
int depth[N],up[N][LOG];
vector<int> v[N];
void dfs(int pos,int pre)
{
   for(auto it:v[pos])
   {
      if(it==pre) continue;
      depth[it]=depth[pos]+1;
      up[it][0] = pos; 
      for(int j = 1; j < LOG; j++) 
      {
        up[it][j] = up[up[it][j-1]][j-1];
      }
      dfs(it,pos);
   }
   return ;
}
int kthancestor(int pos,int k)
{
    for(int i=LOG-1;i>=0;i--)
    {
        if(k&(1<<i))
        pos=up[pos][i];
    }
    return pos;
}
int get_lca(int a, int b) 
{ 
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    a=kthancestor(a,k);
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

