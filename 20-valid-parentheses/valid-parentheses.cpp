class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto it:s){
            if(it == '(' || it == '[' || it == '{') stk.push(it);
            else{
                if(!stk.size()) return false;
                char c = stk.top();
                stk.pop();
                if((it == ')' && c == '(') || (it == '}' && c == '{') || (it == ']' && c == '[')) continue;
                else return false;
            }
        }
        if(stk.size()) return false;
        return true;
    }
};