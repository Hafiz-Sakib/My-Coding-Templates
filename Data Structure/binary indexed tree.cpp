// copied ...

int n, a[MX], tree[MX]; //tree is 1-indexed

void update(int idx, int val) {//add val to index idx
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {//returns sum from index 1 to index idx
    int sum = 0;
    while(idx) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int query(int idi, int idj) {//return sum from index idi to index idj 
    int sum = 0;
    while(idi <= idj) {
        sum += tree[idj];
        idj -= (idj & -idj);
    }
    idi--;
    while(idi != idj) {
        sum -= tree[idi];
        idi -= (idi & -idi);
    }
    return sum;
}

int bS(int sum) {//normal binary search, return the index for which element 1-n sum equals this parameter 'sum' 
    int idx = 0;
    while(bitMask != 0) {
        int mid = idx + bitMask;
        if(mid <= n) {
            if(tree[mid] == sum) {
                return mid;
            }
            else if(tree[mid] < sum) {
                sum -= tree[mid];
                idx = mid;
            }
        }
        bitMask >>= 1;
    }
    if(sum != 0) return -1; //not found 
    return idx;
}

int bS(int sum) {//returns the greatest index which equals sum 
    int idx = 0;
    while(bitMask != 0) {
        int mid = idx + bitMask;
        if(mid <= n && (tree[mid] <= sum)) {
            sum -= tree[mid];
            idx = mid;
        }
        bitMask >>= 1;
    }
    if(sum != 0) return -1; //not found return idx;
}
