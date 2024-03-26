class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        while(i < n){
            if(arr[i]-1 < n and arr[i] - 1 >= 0 and arr[i] != arr[arr[i] - 1]){
                swap(arr[i], arr[arr[i] - 1]);
            }
            else{
                i++;
            }
        }

        for(int i = 0; i < n; i++){
            if(i+1 != arr[i]){
                return i+1;
            }
        }
        return -1;
    }
};