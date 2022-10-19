// Implicit/Dynamic Segment tree
// Stress Test : "Passed"
// Call it by: Vertex* node = new Vertex(1, n);

struct Vertex{
    int left, right;
    ll sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;
    
    Vertex(){}
    
    Vertex(int lb, int rb){
        left = lb;
        right = rb;
    }
    
    void extend(){
        if(!left_child && left < right){
            int mid = (left+right)/2;
            left_child = new Vertex(left, mid);
            right_child = new Vertex(mid+1, right);
        }
    }
    
    void add(int idx, int x){
        if(left == right){
            sum += x;
            return;
        }
        
        extend();
        
        if(left_child){
            if(idx <= left_child->right) left_child->add(idx, x);
            else right_child->add(idx, x);
        }
        
        sum = left_child->sum + right_child->sum;
    }
    
    ll get_sum(int lq, int rq){
        if(lq <= left && right <= rq) return sum;
        
        if(rq < left || lq > right) return 0;
        
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};
