#include <cctype>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) s.push(stol(tokens[i]));
            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(a-b);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(a/b);
                        break;
                }
            }
        }
        return s.top();
    }
};