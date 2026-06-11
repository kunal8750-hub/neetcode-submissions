class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        if(s.length() != t.length()){
            return false;
        }
        for(char val : s){
            mp1[val]++;
        }
        for(char val : t){
            mp2[val]++;
        }
        if(mp1==mp2){
            return true;
        }
        return false;

        
    }
};
