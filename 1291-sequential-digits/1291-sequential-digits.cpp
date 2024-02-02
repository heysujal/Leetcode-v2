class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int len = 2; len <= s.size(); len++){
            for(int i = 0; i <= s.size() - len; i++){
                string temp = s.substr(i, len);
                int num = stoi(temp);
                if(num >= low and num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};