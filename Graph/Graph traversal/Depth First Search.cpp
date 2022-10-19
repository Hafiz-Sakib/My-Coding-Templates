

vector<vi> edge(n+1);
vi color(n+1, 1);
int time = 0;
vi Enter(n+1, -1), Exit(n+1, -1);

bool dfs(int u, int destination)
{
	int v;
	
	time++;
	Enter[u] = time;   // Enter time.
	
	if(u==destination) return 1;
	
	color[u] = 0;     							// 0 - grey
	
	for(int K=0; K<(int)edge[u].size(); K++){
		v = edge[u][K];
		
		if(color[v] == 1) dfs(v, destination);  // 1 - white
	}
	
	color[u] = -1;				 				// -1 - black...
	
	time++;
	Exit[u] = time;    // exit time. 
	
	return 0;
}
