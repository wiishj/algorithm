#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cal(int num, int sys){ //10진수 -> sys진수로
    int rtn=0;
    int mul=1;
    while(num>0){
        if(num%10>=sys) return -1;
        rtn+=(num%10)*mul;
        mul*=sys;
        num/=10;
    }
    return rtn;
}
int cal2(int num, int sys){
    string rtn="";
    while(num>0){
        rtn=to_string(num%sys)+rtn;
        num/=sys;
    }
    if(rtn=="") rtn="0";
    return stoi(rtn);
}
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> known, unknown;
    vector<int> promise;
    for(auto exp:expressions){
        bool flag=true;
        for(auto c:exp){
            if(c=='X') flag=false;
        }
        if(flag) known.push_back(exp);
        else unknown.push_back(exp);
    }
    for(int i=2; i<=9; i++){
        bool flag=true;
        for(auto exp:expressions){
            if(!flag) break;
            //숫자 자르기
            int a, b, c=0;
            char op;
            int prev=0;
            for(int i=0; i<exp.size(); i++){
                if(exp[i]=='+' || exp[i]=='-'){
                    a=stoi(exp.substr(prev,i-1-prev));
                    op=exp[i];
                    prev=i+2;
                }else if(exp[i]=='='){
                    b=stoi(exp.substr(prev,i-1-prev));
                    prev=i+2;
                    break;
                }
            }
            a=cal(a, i); b=cal(b, i);
            if(a<0 || b<0) flag=false;
            if(exp.substr(prev,exp.size()-prev)!="X"){
                c=stoi(exp.substr(prev,exp.size()-prev));
                //i진법일 때 계산
                c=cal(c, i);
                if(c<0) flag=false;
                else if(op=='+'){
                    if(a+b!=c) flag=false;
                }
                else{
                    if(a-b!=c) flag=false;
                }
            }
        }
        if(flag) {
            //cout<<i<<' ';
            promise.push_back(i);
        }
    }
   //cout<<'\n';
    for(auto exp:unknown){
        //숫자 자르기
        int a, b;
        vector<int> c;
        char op;
        int prev=0;
        for(int i=0; i<exp.size(); i++){
            if(exp[i]=='+' || exp[i]=='-'){
                a=stoi(exp.substr(prev,i-1-prev));
                op=exp[i];
                prev=i+2;
            }else if(exp[i]=='='){
                b=stoi(exp.substr(prev,i-1-prev));
                prev=i+2;
                break;
            }
        }
        bool flag=true;
        for(auto i:promise){
            int tmp;
            int tmpa=cal(a, i), tmpb=cal(b, i);
            if(op=='+'){
                tmp=cal2(tmpa+tmpb, i);
            }else{
                tmp=cal2(tmpa-tmpb, i);
            }
            if(c.empty()) c.push_back(tmp);
            else if(c[0]==tmp) continue;
            else{
                flag=false;
                break;
            }
        }
        exp=exp.substr(0,prev);
        if(flag){
            //cout<<c[0]<<' '<<promise[0]<<' '<<cal2(c[0], promise[0])<<'\n';
            exp=exp+to_string(c[0]);
        }else{
            exp=exp+"?";
        }
        answer.push_back(exp);
    }
    return answer;
}