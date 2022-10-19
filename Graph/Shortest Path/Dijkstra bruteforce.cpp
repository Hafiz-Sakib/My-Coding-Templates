const int N = 2e5;
vector<int> d(N+5, -1), p(N+5, -1);
vector<pair<int, int>> edge[N+5];

void dijkstra(int s)
{
	d[s] = 0;
	set< pair< int, int > > q;
	q.insert({0, s});
	
	while(!q.empty()){
		int u = q.begin()->second;
		q.erase(q.begin());
		
		for(auto [to, w] : edge[u]){
			if(d[u] + w < d[to]){
				q.erase({d[to], to});
				
				d[to] = d[u] + w;
				d[to] = u;
				
				q.insert({d[to], to});
			}
		}
	}
}
