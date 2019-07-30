class MedianFinder {
private:
    vector<int> nums;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) {
        nums.push_back(num);
        for(int i = nums.size()-1; i > 0; i--) {
            if(nums[i] >= nums[i-1]) break;
            else swap(nums[i], nums[i-1]);
        }
    }
    
    double findMedian() {
        int number = nums.size();
        if(number % 2) { // odd
            return nums[number/2] / 1.0;
        } else { // even
            return (nums[(number-1)/2] + nums[number/2]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */