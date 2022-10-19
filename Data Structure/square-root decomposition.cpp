int main()
{
    int n;

    cin >> n;

    int block_size = sqrt(n);
    int ara[n], block_ans[n] = {0};

    for(int K = 0; K < n; K++){
            cin >> ara[K];
            block_ans[K/block_size] += ara[K];
    }

    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        l--;
        r--;

        // query operation
        int block_l = l/block_size;
        int block_r = r/block_size;
        int ans = 0;

        if(block_l == block_r){
                for(int K = l; K <= r; K++) ans += ara[K];
        }
        else{
            for(int K = l; K < (block_l+1)*block_size; K++) ans += ara[K];
            for(int K = block_l+1; K < block_r; K++) ans += block_ans[K];
            for(int K = block_r*block_size; K <= r; K++) ans += ara[K];
        }

        cout << ans << "\n";
    }

    return 0;
}
