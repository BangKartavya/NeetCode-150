class Solution {
    public:
        string encode(vector<string>& strs) {
            string result;

            for(string& str : strs) {
                result += str + "\r";
            }

            return result;
        }

        vector<string> decode(string s) {
            vector<string> result;

            string temp;

            for(char& ch : s) {
                if(ch == '\r') {
                    result.push_back(temp);
                    temp = "";
                } else {
                    temp += ch;
                }
            }

            return result;
        }
};
