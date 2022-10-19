const int MX = 2e5;
int dsu[MX+5];
int Find(int x)
{
	if(dsu[x] == x) return x;
	
	return dsu[x] = Find(dsu[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	dsu[b] = a;
}

vector<pair<int, pair<int, int> > > Edges;
int kruskal()
{
	sort(Edges.begin(), Edges.end());
	int E = (int)Edges.size();
	int mst_cost = 0;
	
	for(int K = 0; K < E; K++){
		if(Find(Edges[K].second.first) != Find(Edges[K].second.second)){
			Union(Edges[K].second.first, Edges[K].second.second);
			mst_cost += Edges[K].first;
		}
	}
	
	return mst_cost;
}




