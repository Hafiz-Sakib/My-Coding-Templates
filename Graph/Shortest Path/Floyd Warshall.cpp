const int MX = 400;
ll dist[MX+5][MX+5];
	
// Inside main function . . .
// dist[] <- Infinity
for(int M=1; M<=n; M++){
	for(int K=1; K<=n; K++){
		for(int L=1; L<=n; L++){
			if(dist[K][L] > dist[K][M]+dist[M][L])
				dist[K][L] = dist[K][M]+dist[M][L];
		}
	}
}
