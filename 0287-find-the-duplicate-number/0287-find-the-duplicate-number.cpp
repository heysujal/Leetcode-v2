class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int s = 0;
        int e = n-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(arr[mid] < mid+1){
                 e = mid;
            }else{
                 s = mid + 1; 
            }
        }
        return s;
    }
};