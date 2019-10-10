public:
    int trap(vector<int>& heights) {
        int maxHeight = 0, maxIndex;
        if (heights.size()==0||heights.size()==1) return 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }
        int sum = 0;
        maxHeight = 0;
        // 记录前缀最大值
        for (int i = 0; i < maxIndex; i++) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        maxHeight = 0;
        // 记录后缀最大值
        for (int i = heights.size() - 1; i > maxIndex; i--) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        return sum;
    }
};