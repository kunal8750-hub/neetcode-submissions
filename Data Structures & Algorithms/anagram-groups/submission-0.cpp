class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(string val : strs){
            string key = val;
            sort(key.begin(),key.end());
            mp[key].push_back(val);
        }
        for(auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
