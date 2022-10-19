// Kadane's algo for Maximum Sub sub-Matrix (including MS sub-array)...
vector<vector<int> > ara(n, vector<int> (n));
void MaxSumSubMatrix(int n)
{
    int max_sum=0, sum, max_;
    
    //test_input(n);
    int ansup=0, ansdown=0, ansleft=0, ansright=0, ul, dl, u, v;
    for(int K=0; K<n; K++){
        vector<int> help(n);
        for(int L=K; L<n; L++){
            for(int M=0; M<n; M++){
                help[M] += ara[M][L];
            }
    
            // Kadane's Algo for a 1D single array...
            sum = max_ = help[0];
            ul = dl = u = v = 0;
            for(int M=1; M<n; M++){
                //sum = max(sum+help[M], help[M]);
                if(sum+help[M]>=help[M]){
                    sum += help[M];
                    v++;
                }
                else{
                    sum = help[M];
                    u = M;
                    v = M;
                }
                //max_ = max(max_, sum);
                if(sum>max_){
                    max_ = sum;
                    ul = u;
                    dl = v;
                }
            }

            if(max_sum<max_){
                max_sum = max_;
                ansup = ul;
                ansdown = dl;
                ansleft = K;
                ansright = L;
            }
        }
    }

    cout << "\n" << max_sum << '\n';
    cout << ansleft << ' ' << ansright << ' ' << ansup << ' ' << ansdown << "\n";
}


// KADANE (1D)
sum = ans = ara[0];
int u = 0, v = 0;
for(int K=1; K<n; K++){
    if(sum+ara[K] >= ara[K]){
        sum += ara[K];
        v++;
    }
    else{
        sum = ara[K];
        u = v = K;
    }
    if(sum > ans){
        ans = sum;
        ans_l = u;
        ans_r = v;
    }
}
