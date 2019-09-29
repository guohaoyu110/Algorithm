/*class Solution {
public:
    //这个解法时间开销太大了
    vector<int> twoSum(vector<int>& numbers, int target) {
        //int count = 0;
        vector<int>res(2);
        for (int i=0;i<numbers.size();i++)
        {
            for (int j=i+1;j<numbers.size();j++)
            {
                if(numbers[i]+numbers[j] == target)
                {
                    //res.push_back(i+1);
                    //res.push_back(j+1);
                    res[0]=i+1;
                    res[1]=j+1;
                    break;
                    //return res;
                    
                }
                //break;
                    
            }
        }
        return res;   
    }
};*/
//多用while循环，不要条件反射只会用for

//第二种解法属于指针对撞的解法，可以降低时间复杂度，复杂度是O(n)
//也可以用二分法，时间复杂度也是O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> result;

        int left = 0, right = numbers.size() - 1;
        
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else if(numbers[left] + numbers[right] < target){
                left++;
            }
        }
        return result;
    }
};