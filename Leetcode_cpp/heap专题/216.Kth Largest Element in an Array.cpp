class Solution {
public:
    // use heap to solve this problem
    int findKthLargest(std::vector<int>& nums, int k) {
        // std::set<int> setptr; // judge whether it is empty or not
        // for(int i=0;i< nums.size();i++){
        //     setptr.insert(nums[i]);
        // }
        //if (nums.size()>setptr.size()) return -1;
        //if (k>=nums.size()) return -1; // when k is beyond the size of inputs, there is no meaning
        buildheap(nums,k);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < nums[0]) continue;
            std::swap(nums[0],nums[i]);
            heapify(nums, k, 0);
        }
    //K个元素的小顶堆的堆顶即是第K大元素
        return nums[0];
    }
    
    void buildheap(std::vector<int>& inputs, int k){
        for (int i = k/2 ; i >= 0; i--) {
            heapify(inputs, k, i);
        }
    }


    void heapify(std::vector<int>& inputs, int k, int i){
        int min = i;
        while (true) {
      //compare with the left node
            if (i*2+1 < k && inputs[i*2+1] < inputs[i]) 
            min = i*2+1;
    //compare with the right node
            if (i*2+2 < k && inputs[i*2+2] < inputs[min]) 
            min = i*2+2;
    //如果min没有发生变化，说明父节点已经是最小了，直接跳出
            if (min == i) break;
            std::swap(inputs[i],inputs[min]);
    //父节点下标进行更新，继续heapify
            i = min;
        }
    }
    
};