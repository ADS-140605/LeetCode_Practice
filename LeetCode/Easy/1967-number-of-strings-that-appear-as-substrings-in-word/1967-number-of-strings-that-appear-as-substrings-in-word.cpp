class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(const auto& s: patterns){
            if(word.contains(s)) count++;
        }
        return count;
    }
};