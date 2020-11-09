#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> st;
        int num = 0, i = 0;
        std::string str = "";
        
        while(i<s.size()){
            while(i<s.size() && std::isdigit(s[i])){
                num *= 10;
                num += s[i]-'0';
                i++;
            }

            while(i<s.size() && std::isalpha(s[i])){
                str += s[i];
                i++;
            }
            
            if(s[i] == '['){
                st.push(str);
                st.push(std::to_string(num));
                st.push("[");
                num = 0;
                str = ""; 
                i++;
                
            } else if (s[i]==']'){
                st.pop(); //pop [
                int cnt = stoi(st.top());
                st.pop(); //pop number
                std::string temp = "";
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