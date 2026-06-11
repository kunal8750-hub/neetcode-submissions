class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<int> prime = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97, 101
        };

        unordered_map<unsigned long long, vector<string>> mp;

        for (string s : strs) {
            unsigned long long hash = 1;

            for (char ch : s) {
                hash *= prime[ch - 'a'];
            }

            mp[hash].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};