#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int max_c;
int cnt[11];
vector<vector<string>> val(11);
unordered_map<string, int> map;
void dfs(string order, string cur, int idx){
    if(cur.size()>max_c) return;
    sort(cur.begin(), cur.end());
    map[cur]++;
    //cout<<cur<<' '<<map[cur]<<'\n';
    if(map[cur]>cnt[cur.size()]) {
        cnt[cur.size()]=map[cur];
        val[cur.size()].clear();
        val[cur.size()].push_back(cur);
    }else if(map[cur]==cnt[cur.size()]) val[cur.size()].push_back(cur);
    for(int i=idx; i<order.size(); i++){
        dfs(order, cur+order[i], i+1);
    }

}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    max_c=course[course.size()-1];
    for(auto& o:orders){
        //cout<<o<<'\n';
        for(int i=0; i<o.size(); i++) dfs(o,string(1,o[i]), i+1);
        //cout<<'\n';
    }
    for(auto& c:course){
        if(cnt[c]<2) continue;
        for(auto& s:val[c]) answer.push_back(s);
    }
    sort(answer.begin(), answer.end());
    return answer;
}