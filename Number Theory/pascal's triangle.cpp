const int MX = 1e2;
ll C[MX+5][MX+5];

void pascal()
{
	C[0][0] = 1;
	for(int K=1; K<=MX; K++){
		C[K][0] = C[K][K] = 1;
		for(int L=1; L<K; L++){
			C[K][L] = C[K-1][L-1] + C[K-1][L];
		}
	}
}
