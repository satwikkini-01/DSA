class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<map<string, int>> s;
        map<string, int> mpp;

        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                s.push(mpp);
                mpp.clear();
                i++;
            } 
            else if (formula[i] == ')') {
                map<string, int> temp = mpp;
                mpp = s.top();
                s.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int m = (i == start) ? 1 : stoi(formula.substr(start, i - start));
                for (auto it : temp) {
                    mpp[it.first] += it.second * m;
                }
            } 
            else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string e = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = (i == start) ? 1 : stoi(formula.substr(start, i - start));
                mpp[e] += count;
            }
        }

        string ans;
        for (auto it : mpp) {
            ans += it.first;
            if (it.second == 1) continue; 
            ans += to_string(it.second);
        }
        return ans;
    }
};