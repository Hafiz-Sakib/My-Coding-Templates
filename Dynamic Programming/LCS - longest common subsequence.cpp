// longest common subsequence...


int lcs(string& a, string& b, int len_a, int len_b)  
{  
    int dp[len_a+1][len_b+1];  
    int i, j;
     
    for(i=0; i<=len_a; i++){  
        for(j=0; j<=len_b; j++){ 
			if(i==0 || j==0) dp[i][j] = 0;
			else if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  
		}  
    }  
          
    return dp[len_a][len_b];   // ans...
} 
