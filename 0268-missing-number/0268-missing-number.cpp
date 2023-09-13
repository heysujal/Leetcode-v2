class Solution {
public:
    int missingNumber(vector<int>& arr) {
        // every number nums[i] should be present 
        // at index nums[i]
        int i = 0;
        int n = arr.size();
        while(i < n){
            if(arr[i] < n and arr[i] != arr[arr[i]]){
                swap(arr[i], arr[arr[i]]);
            }else{
                i++;
            }
        }
        for(int i = 0; i < n; i++)
            if(arr[i] != i)
                return i;
        return n;
    }
};