class Solution {
public:
    int n;
    void fillNextSmaller(vector<int> &height, vector<int> &next){
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and height[st.top()] >= height[i])
                    st.pop();
            if(st.empty()){
                next[i] = n;
                st.push(i);
            }else{
                next[i] = st.top();
                st.push(i);
            }
        }
    }
    void fillPrevSmaller(vector<int> &height, vector<int> &prev){
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and height[st.top()] >= height[i])
                st.pop();
            if(st.empty()){
                prev[i] = -1;
                st.push(i);
            }else{
                prev[i] = st.top();
                st.push(i);
            }
        }
    }
    int largestRectangleArea(vector<int>& height) {
        int area = 0;
        n =  height.size();
        vector<int> next(n);
        vector<int> prev(n);
        fillNextSmaller(height,next);
        fillPrevSmaller(height,prev);
        for(int i=0;i<n;i++){
            int width = 1;
            area = max(area,width*height[i]);
            width = (next[i]-1) - (prev[i]+1) + 1;
            area = max(area, width*height[i]);
        }
        return area;
    }
};