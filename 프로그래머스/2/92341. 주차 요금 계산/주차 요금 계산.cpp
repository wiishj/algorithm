#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string &a, const string &b) {
    int numA = stoi(a.substr(6, 4));
    int numB = stoi(b.substr(6, 4));

    if (numA != numB) {
        return numA < numB;
    }

    int ha=stoi(a.substr(0,2)), hb=stoi(b.substr(0,2)), ma=stoi(a.substr(3, 2)), mb=stoi(b.substr(3,2));
    if(ha==hb){
        return ma<mb;
    }else{
        return ha<hb;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int standardT = fees[0], standardC = fees[1], unitM = fees[2], unitC = fees[3];
    sort(records.begin(), records.end(), cmp);
    int i=0;
    while(i<records.size()){
        vector<string> time;
        time.push_back(records[i].substr(0,5));
        string num=records[i].substr(6, 4); 
        i++;
        while(i<records.size() && records[i].substr(6, 4)==num){
            time.push_back(records[i].substr(0,5));
            i++;
        }
        int diff=0;
        for(int j=0; j<time.size(); j+=2){
            string time1=time[j], time2;
            if(j+1!=time.size()) time2=time[j+1];
            else time2="23:59";
            diff += (stoi(time2.substr(0,2))-stoi(time1.substr(0,2)))*60+(stoi(time2.substr(3,5))-stoi(time1.substr(3,5)));
        }
        
        if(diff<=standardT){
            answer.push_back(standardC);
        }else{
            int tmp = (diff-standardT)%unitM?(diff-standardT)/unitM+1:(diff-standardT)/unitM;
      
            answer.push_back(standardC+tmp*unitC);
        }
    }
    return answer;
}