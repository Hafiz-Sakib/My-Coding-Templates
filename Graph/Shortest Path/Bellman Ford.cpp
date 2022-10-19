
struct Edge {
	int u, v, w;
	
	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

vector<Edge> E; // weighted edge list
int dist[100], n;

int bellman_ford(int s, int dest){
	for(int i=1; i<=n; i++) dist[i] = MXI;
	dist[s] = 0;
	
	for(int i=1; i<n; i++){
		for(Edge e:E) {
			if(dist[e.v] > dist[e.u] + e.w) {
				dist[e.v] = dist[e.u] + e.w;
			}
		}
	}
	
	for(Edge e:E) {
		if(dist[e.v] > dist[e.u] + e.w) {
			return -1;
		}
	}
	
	return dist[dest];
}
