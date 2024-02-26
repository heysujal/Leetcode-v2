class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.size() == 0 and minh.size() == 0){
            maxh.push(num);
        }
        else{
            if(num > maxh.top()){
                minh.push(num);
            }
            else{
                maxh.push(num);
            }
        }

        // the max size diff can be 1 only
        // as soon as the diff becomes 2 then make them even
        int m = maxh.size();
        int n = minh.size();
        if(abs(m-n) == 2){
            if(m > n){
                minh.push(maxh.top());
                maxh.pop();
            }
            else{
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        int m = maxh.size();
        int n = minh.size();
        if((m+n)%2 != 0){
            // odd len
            if(m > n){
                return maxh.top();
            }
            else{
                return minh.top();
            }
        }
        else{
            // even len
            return (double)(maxh.top() + minh.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */