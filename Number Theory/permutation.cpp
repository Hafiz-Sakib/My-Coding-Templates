//Permutation generator for number 1 to n;


vector<int> used(20);
int number[20];

//call with: permutation(1, n);
// makesure, all the entries in used[] is 0;
void permutation(int now, int n)
{
    if(now == n+1){
        for(int K=1; K<=n; K++) printf("%d ", number[K]);
        printf("\n");
        return;
    }

    for(int K=1; K<=n; K++){
        if(!used[K]){
            used[K] = 1;
            number[now] = K;
            permutation(now+1, n);
            used[K] = 0;
        }
    }
}
