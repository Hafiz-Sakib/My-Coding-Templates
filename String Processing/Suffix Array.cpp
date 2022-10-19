#include<bits/stdc++.h>
using namespace std;

#define MAXLG   18
#define MAXN    100000
#define fi      first
#define se      second

const int inf = 1000000000;

int Plc[MAXLG+5][MAXN+10], stp;
int S[MAXN+10], n;                     //Sorted Suffixes. . . .
pair< pair<int,int> , int> C[MAXN+10];

string str;

void Generate_SA()
{
    int i, len = n, cur;
    for(i=0; i<len; i++)    Plc[0][i] = str[i];

    for(cur=stp=1; (cur>>1)<len; cur*=2, stp++)
    {
        for(i=0; i<len; i++)
        {
            C[i].fi.fi = Plc[stp-1][i];
            C[i].fi.se = i+cur<len ? Plc[stp-1][i+cur] : -inf; // set it to -inf when dealing with negative numbers
            C[i].se = i;
        }
        
        sort(C, C+len);
        
        for(i=0; i<len; i++)
        {
            if(!i || C[i-1].fi.fi!=C[i].fi.fi || C[i-1].fi.se!=C[i].fi.se) Plc[stp][C[i].se] = i;
            else Plc[stp][C[i].se] = Plc[stp][C[i-1].se];
        }
    }
    
    for(i = 0; i < len; i++)
        S[Plc[stp-1][i]] = i;
    stp--;
}

int LCP[MAXN+10], PLCP[MAXN+10], Phi[MAXN+10];
void build_LCP()
{
    Phi[S[0]]=-1;
    for(int i=1; i<n; i++)
        Phi[S[i]]=S[i-1];
    for(int i=0,L=0; i<n; i++)
    {
//        D(i);
        if(Phi[i]==-1)
        {
            PLCP[i]=0;
            continue;
        }
        while(str[i+L]==str[Phi[i]+L]) L++;
        PLCP[i] = L;
        L = max(L-1,0);
    }
 
    for(int i=0; i<n; i++)
        LCP[i] = PLCP[S[i]];
}

int main()
{
	cin >> str;
	
	n = str.size();
	
    Generate_SA();
    build_LCP();
    
    for(int i = 0; i < (int) str.size(); i++){
        cout <<  S[i] << endl;
    }
    return 0;
}
