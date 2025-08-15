class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> stk;

            for(string& token : tokens) {
                if(token != "*" && token != "+" && token != "-" && token != "/") {
                    stk.push(stoi(token));
                } else {
                    int b = stk.top();
                    stk.pop();
                    int a = stk.top();
                    stk.pop();

                    if(token == "+") stk.push(a + b);
                    else if(token == "-") stk.push(a - b);
                    else if(token == "*") stk.push(a * b);
                    else stk.push(a / b);
                }
            }

            return stk.top();
        }
};
