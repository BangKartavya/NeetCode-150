class MinStack {
    private:
        long long mini = 0;
        stack<long long> stk;

    public:
        MinStack() {
        }

        void push(int val) {
            if(stk.empty()) {
                stk.push(0);
                mini = val;
            } else {
                stk.push(val - mini);
                if(val < mini) mini = val;
            }
        }

        void pop() {
            long long top = stk.top();
            stk.pop();

            if(top < 0) mini = mini - top;
        }

        int top() {
            long long top = stk.top();

            return (top > 0) ? top + mini : mini;
        }

        int getMin() {
            return mini;
        }
};
