#include <bits/stdc++.h>
using namespace std;


// Computing hashing of a string . . .
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    
    long long hash_value = 0;
    long long p_pow = 1;
    
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    
    return hash_value;
}

// Search for duplicate strings in an array of strings . . .
// Puts the same strings in a group . . .
/// Example . . 
/// 5
/// asaf
/// asad
/// asae
/// asaf
/// asad
/// 1 4 
/// 2 
/// 0 3
vector<vector<int> > group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

// String Matching . . .
// Robin-Karp Algorithm . . .
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    
    return occurences;
}

// Main function . . .
int main()
{
	vector<string> v;
	string s;
	int n;
	
	cin >> n;
	for(int K=0; K<n; K++){
		cin >> s;
		v.push_back(s);
	}
	
	vector<vector<int> > ara = group_identical_strings(v);
	
	for(int K=0; K<(int)ara.size(); K++){
		for(int L=0; L<(int)ara[K].size(); L++) cout << ara[K][L] << ' ';
		cout << "\n";
	}
	
	return 0;
}
