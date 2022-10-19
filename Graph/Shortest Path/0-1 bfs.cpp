const int N = 2e5;
vector<int> d(N+5, -1), p(N+5, -1);
vector<pair<int, int>> edge[N+5];

void dijkstra(int s)
{
	d[s] = 0;
	deque<int> q;
	q.push_back(s);
	
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		
		for(auto [to, w] : edge[u]){
			if(d[u] + w < d[to]){
				d[to] = d[u] + w;
				
				if(w == 1) q.push_back(to);
				else q.push_front(to);
			}
		}
	}
}
