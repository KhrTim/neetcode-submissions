class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(const auto& i : nums)
        {
            counts[i]++;
        }
        vector<pair<int,int>> topKHeap;
        topKHeap.reserve(counts.size());
        for(const auto& [key, val] : counts)
        {
            topKHeap.emplace_back(key, val);
        }
        auto cmp = [](const auto& a, const auto &b) {return a.second < b.second;};
        make_heap(topKHeap.begin(), topKHeap.end(), cmp);
        vector<int> res;
        res.reserve(k);
        for(int i =0; i<k; i++)
        {
            res.push_back(topKHeap.front().first);
            pop_heap(topKHeap.begin(), topKHeap.end(), cmp);
            topKHeap.pop_back();

        }
        return res;

    }
};
