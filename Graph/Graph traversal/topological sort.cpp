const int MX = 1e4;
vi ara[MX+5], in_deg(MX+5);
vector<int> order;
void topsort(int n)
{
	queue<int> q;
	// maybe a queue is enough sometimes or need priority queue???
	order.clear();
	
	for(int K=1; K<=n; K++){
		if(!in_deg[K]){
			q.push(K);
			// As want to proccess smaller first
			// multiplying with -1 makes the small number bigger(!)
		}
	}
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		order.PB(u);
		// updating solution list
		
		for(int K=0; K<sz(ara[u]); K++){
			in_deg[ara[u][K]]--;

			if(in_deg[ara[u][K]] == 0){
				q.push(ara[u][K]);
				// child node's level is 1 step lower
				// so have to add 1 to parent node's level;
			}
		}
	}
}
