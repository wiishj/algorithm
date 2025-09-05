#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> s, e;
char direction[4] = {'d', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
int row, col, tmpk;
string answer = "";

bool dfs(string &path, pair<int,int> coor, int depth) {
    if(depth == tmpk) {
        if(coor == e) {
            answer = path;
            return true;
        }
        return false;
    }

    int remain = tmpk - depth;
    int dist = abs(coor.first - e.first) + abs(coor.second - e.second);
    if(dist > remain || (dist % 2 != remain % 2)) return false; // pruning

    for(int i = 0; i < 4; i++) {
        int nx = coor.first + dx[i];
        int ny = coor.second + dy[i];
        if(nx <= 0 || nx > row || ny <= 0 || ny > col) continue;
        
        path.push_back(direction[i]);
        if(dfs(path, {nx, ny}, depth+1)) return true; // 정답 찾으면 바로 return
        path.pop_back();
    }
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    s = {x,y}; e = {r,c}; row = n; col = m; tmpk = k;
    string path = "";

    if(!dfs(path, s, 0)) return "impossible";
    return answer;
}
