class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        // missing will be index + 1
        // repeated will be arr[index]
        int n = arr.size();
        int i = 0;
        while(i < n){
            if(arr[i]-1 >= 0 and arr[i] != arr[arr[i]-1]){
                swap(arr[i], arr[arr[i]-1]);
            }
            else{
                i++;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                return {arr[i], i+1};
            }
        }
        return {-1, -1};
    }
};