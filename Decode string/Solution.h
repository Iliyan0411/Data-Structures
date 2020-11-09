#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s) {
        stack<string> st;
        int num = 0, i = 0;
        string str = "";
        
        while(i<s.size()){
            while(i<s.size() && isdigit(s[i])){
                num *= 10;
                num += s[i]-'0';
                i++;
            }
            
            while(i<s.size() && isalpha(s[i])){
                str += s[i];
                i++;
            }
            
            if(s[i] == '['){
                st.push(str);
                st.push(to_string(num));
                st.push("[");
                num = 0;
                str = ""; 
                i++;
                
            } else if (s[i]==']'){
                st.pop(); //pop [
                int cnt = stoi(st.top());
                st.pop(); //pop number
                string temp = "";
                while(cnt > 0){
                    temp += str;
                    cnt--;
                }
                str = st.top() + temp;
                st.pop();
                i++;
            }
        }
        return str;
    }
};


#endif