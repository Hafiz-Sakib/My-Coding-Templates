#define MX 1e5+6;

// phi pre-calculation function . . .
ll phi[MX];
void phi_function()
{
  memset(phi, 0, sizeof phi);
  
	phi[1] = 1;
	for(int i=2; i<=MAX; ++i)
	{
	    if(phi[i]==0)
	    {
	        phi[i]=i-1;
			for(int j=i+i; j<=MAX; j+=i)
			{
				if(phi[j]==0)   phi[j] = j;
                phi[j]= phi[j]/i * (i-1);
			}
	    }
	}
}

// gcd sum calculation function . . .
ll table[MAX];
void div()
{
    memset(table, 0, sizeof table);
    
    for(int i=1;i<MAX;i++)
    {
        for(int j=i+i;j<MAX;j=j+i)
        {
            table[j]+=(i*phi[j/i]);
        }
    }
    for(int i=2;i<MAX;i++)
        table[i]+=table[i-1];
}
