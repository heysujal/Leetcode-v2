class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        k--;
        int fact = 1;
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        for(int i = 1; i < n; i++){
            // getting n-1 factorial
            fact *= i;
        }

        while(true){
            int index = k / fact;
            ans = ans + to_string(nums[index]);
            // erase this index element
            nums.erase(nums.begin() + index);
            if(nums.size() == 0){
                return ans;
            }
            k = k % fact;
            fact = fact / nums.size(); // size has now been decrease by 1
            // so it becomes n-2 ka factorial
        }
        return ans;
    }
};