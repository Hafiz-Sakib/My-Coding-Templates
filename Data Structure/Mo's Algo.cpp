const int MX = 2e5;   // query size . . .
const int MXI = 1e6;  // maximum value in array . . .
ll cnt[MXI+5];

ll block_size, range_ans;

struct Query{
    int id, l, r;
    
    Query() {}
    Query(int _id, int _l, int _r){
        id = _id;
        l = _l;
        r = _r;
    }
    
    bool operator<(Query &other) const{
        int curr_size = l/block_size;
        int other_size = other.l/block_size;
        
        if(curr_size == other_size) return r < other.r;
        return curr_size < other_size;
    }
} query[MX+5];

void add(ll x)
{
    if(cnt[x]) range_ans -= cnt[x]*cnt[x]*x;
    cnt[x]++;
    range_ans += cnt[x]*cnt[x]*x;
}
void rmv(ll x)
{
    range_ans -= cnt[x]*cnt[x]*x;
    cnt[x]--;
    if(cnt[x]) range_ans += cnt[x]*cnt[x]*x;
}
ll get_solution()
{
    return range_ans;
}

void mos_algo()
{
    int n, t, l, r;
    
    cin >> n >> t;
    
    // setting block size ...
    block_size = sqrt(n);
    
    int ara[n];
    for(int K = 0; K < n; K++) cin >> ara[K];
    
    for(int K = 0; K < t; K++){
        cin >> l >> r;
        
        query[K] = Query(K, l-1, r-1); // 0-based indexing . . .
    }
    sort(query, query+t);
    
    int L = 0, R = -1;
    ll v[t];
    
    for(int K = 0; K < t; K++){
        l = query[K].l;
        r = query[K].r;
        
        while(L < l){
            rmv(ara[L]);
            L++;
        }
        while(L > l){
            L--;
            add(ara[L]);
        }
        while(R < r){
            R++;
            add(ara[R]);
        }
        while(R > r){
            rmv(ara[R]);
            R--;
        }
        
        v[query[K].id] = get_solution();
    }
    
    for(int K = 0; K < t; K++) cout << v[K] << "\n";
}

