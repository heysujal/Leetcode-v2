class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> v;
        int i = low;
        int j = mid + 1;
        while(i <= mid and j <= high){
            if(arr[i] <= arr[j]){
                v.push_back(arr[i]);
                i++;
            }
            else{
                v.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            v.push_back(arr[i]);
            i++;
        }
        while(j <= high){
            v.push_back(arr[j]);
            j++;
        }
        for(int k = low; k <= high; k++){
            arr[k] = v[k-low];
        }
    }
    void countPairs(vector<int>& arr, int low, int mid, int high){
        int right = mid+1;
        for(int i = low; i <= mid; i++){
            while(right <= high and ((long long)arr[i] > (long long)2*arr[right])){
                right++;
            }
            // above fails so right will be invalid index
            cnt += (right - 1 - (mid+1) + 1);
        }
    }
    void ms(vector<int>& arr, int low, int high){
        if(low >= high)
            return;
        int mid = (low + high)/2;
        ms(arr, low, mid);
        ms(arr, mid + 1, high);
        // count pairs before merging
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        ms(arr, 0, n-1);
        return cnt;
    }
};