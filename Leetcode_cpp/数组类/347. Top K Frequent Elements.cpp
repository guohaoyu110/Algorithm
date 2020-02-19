class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> m;
        for (auto i : nums){
            m[i]++;
        }
        vector<pair<int, int>> hashv(m.begin(), m.end());//因为sort只能对有序容器排序，所以将map转成vector
        sort(hashv.begin(), hashv.end(), [](pair<int, int>& a, pair<int, int>& b)          
         {return a.second > b.second; });
        auto iter = hashv.begin();
        while (k--)
        {
            ret.push_back(iter->first);
            iter++;
        }
        return ret;
    }
};

// 方法二
class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ret;
    unordered_map<int, int> hash;
    for (auto a : nums){
        hash[a]++;
    }
    // priority_queue 默认的比较方法是：
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> freq;
    for (auto a : hash){
        freq.push(a);
        if (freq.size() > k)
            freq.pop();
    }
    while (!freq.empty()){
        ret.push_back(freq.top().first);
        freq.pop();
    }
    return ret;
    }
};