//解法一，最简单基础的解法
//通过确实是通过了，但是时间复杂度和空间复杂度是不是太大了
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec;
        unordered_map<int,int>m;
        if(nums.size()==0)
        {
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        if(nums.size()!=0)
        {
            for(int i=0;i<nums.size();i++)
            {
                m[nums[i]] = i;
            }   
            int flag = 0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]==target)
                    vec.push_back(j);
            
                if (m.count(target)==0)
                {
                    flag++;
                    if(flag==nums.size()){
                        vec.push_back(-1);
                        vec.push_back(-1);
                        return vec;
                    } 
                //break;
                }
            }
        }
            vector<int>vec1;
            vec1.push_back(vec[0]);
            vec1.push_back(vec[vec.size()-1]);
            return vec1;
        //}
    }
};

//方法三，这种思路比较经典，用两次二分查找去夹上下的区间
class Solution {
private:
    int findLowerBound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    int findUpBound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;

            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }


public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int num1 = findLowerBound(nums, target);

        if (num1 == -1) {
            return {-1, -1};
        }
        int num2 = findUpBound(nums, target);
        return {num1, num2};
    }
};






