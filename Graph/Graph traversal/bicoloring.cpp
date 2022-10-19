/// Bicoloring using BFS...


/// Note: If a graph contains cycle of odd length, then it isn't bicolorable.

vector<vector<int> > edge;
bool bicoloring(int n, int source)
{
    queue<int> q;
    int u, v;
    q.push(source);
    vector<int> color(n);  // 0 for white... 1 for red... 2 for blue..
    color[0] = 1;
    //bool flag = 0;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int K=0; K<edge[u].size(); K++){
            v = edge[u][K];
            if(color[v]==0){
                if(color[u]==1) color[v] = 2;  // color[u] is red than color[v] will be blue.
                else color[v] = 1;             // else color[v] will be red.
                q.push(v);
            }

            if(color[u]==color[v]) return false; // If the color of both source u ans source v ara seme, than graph isn.t bicolorable..
        }
    }

    return true;
}
