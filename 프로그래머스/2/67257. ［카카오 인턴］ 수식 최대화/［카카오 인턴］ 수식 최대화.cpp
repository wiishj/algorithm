#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;

vector<vector<char>> pri;

void seq(vector<char> exp, int idx, vector<char> val, vector<int> visited) {
    visited[idx] = 1;
    val.push_back(exp[idx]);

    if (val.size() == exp.size()) {
        pri.push_back(val);
        return;
    }
    for (int i = 0; i < exp.size(); i++) {
        if (visited[i]) continue;
        seq(exp, i, val, visited);
    }
}

long long cal(deque<long long> num, deque<char> exp, vector<char> p) {
    int idx = 0;
    while (num.size() != 1) {
        deque<long long> num_tmp;
        deque<char> exp_tmp;
        bool flag = false;

        while (!num.empty() && !exp.empty()) {
            long long val = num.front(); 
            num.pop_front();
            char e = exp.front(); 
            exp.pop_front();

            if (e == p[idx]) {
                flag = true;
                int val2 = num.front(); 
                num.pop_front();
                if (e == '*') num.push_front(val * val2);
                else if (e == '+') num.push_front(val + val2);
                else num.push_front(val - val2);
            } else {
                num_tmp.push_back(val);
                exp_tmp.push_back(e);
            }
        }

        num_tmp.push_back(num.front()); 
        num.pop_front();

        if (!flag) idx++;
        num = num_tmp;
        exp = exp_tmp;
    }
    return num.front();
}

long long solution(string expression) {
    long long answer = 0;
    deque<long long> num;
    deque<char> exp;
    set<char> exp_set;
    string tmp = "";

    for (auto e : expression) {
        if (isdigit(e)) {
            tmp += e;
        } else {
            num.push_back(stoi(tmp));
            tmp = "";
            exp.push_back(e);
            exp_set.insert(e);
        }
    }
    num.push_back(stoi(tmp));

    vector<char> exp_vec;
    exp_vec.assign(exp_set.begin(), exp_set.end());

    for (int i = 0; i < exp_vec.size(); i++) {
        vector<int> visited(exp_vec.size(), 0);
        seq(exp_vec, i, {}, visited);
    }

    for (auto p : pri) {
        answer = max(answer, abs(cal(num, exp, p)));
    }

    return answer;
}
