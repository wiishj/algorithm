#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    int n = nodes.size(), A = 0, B = 0;
    unordered_map<int,int> id; 
    id.reserve(n*2);
    for(int i = 0; i < n; i++) id[nodes[i]] = i;

    vector<int> p(n), deg(n), cnt(n), same(n);
    for(int i = 0; i < n; i++) p[i] = i;
    auto f = [&](int x) { while(p[x] != x) { p[x] = p[p[x]]; x = p[x]; }  return x; };

    for(auto &e: edges) {
        int a = id[e[0]], b = id[e[1]];
        int ra = f(a), rb = f(b); 
        if(ra != rb) p[ra] = rb;
        deg[a] ^= 1; deg[b] ^= 1;                  
    }
    for(int i = 0; i < n; i++) {
        int r = f(i);
        cnt[r]++; 
        same[r] += (deg[i] == (nodes[i]&1));
    }
    for(int i = 0; i < n; i++) if(p[i] == i) {
        if(same[i] == 1) A++;
        if(same[i] == cnt[i]-1) B++;
    }
    return {A, B};
}
