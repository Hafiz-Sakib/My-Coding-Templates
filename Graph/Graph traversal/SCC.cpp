# Not Tested

/// Finding SCC

// For directed edges
// Need a reverse edge graph

const int MX = 1e5;
vector<int> edge[MX+5], reverse_edge[MX+5], component[MX+5];
bool vis[MX+5], color[MX+5];
stack<int> stk;

void dfs(int u)
{
	color[u] = 1;
	
	for(int K = 0; K < (int)edge[K].size(); K++){
		if(color[edge[u][K]] == 0) dfs(edge[u][K]);
	}
	stk.push(u);
}

void dfs2(int u, int mark)
{
	component[mark].push_back(u);
	vis[u] = 1;
	
	for(int K = 0; K < (int)reverse_edge[u].size(); K++){
		if(!vis[reverse_edge[u][K]]) dfs2(reverse_edge[u][K], mark);
	}
}

int find_scc(int n)
{
	int mark = 0;
	
	for(int K = 1; K <= n; K++){
		if(color[K] == 0) dfs(K);
	}
	
	while(!stk.empty()){
		int u = stk.top();
		stk.pop();
		
		if(vis[u] == 0){
			mark++;
			dfs2(u, mark);
		}
	}
	
	// We get components as result
	return mark; // Number for SCC subgraph.
}
