vector<pair<int, int> > edge[MX+5];
int dist[MX+5];

void dijkstra(int src, int d, int n)
{
	memset(dist, -1, sizeof dist);
	priority_queue<pair<int, int> > PQ;
	PQ.push({0, src});
	dist[src] = 0;
	
	while(!PQ.empty()){
		int cost = -1*PQ.top().first;
		int u = PQ.top().second;
		PQ.pop();
		
		for(auto e:edge[u]){
			if(dist[e.first] == -1 || dist[e.first] > max(cost, e.second)){
				dist[e.first] = max(cost, e.second);
				PQ.push({-1*dist[e.first], e.first});
			}
		}
	}
	
	return dist[d];
}
