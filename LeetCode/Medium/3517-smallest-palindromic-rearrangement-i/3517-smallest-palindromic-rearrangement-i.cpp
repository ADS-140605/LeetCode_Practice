class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        sort(s.begin(),s.begin()+n/2);
        sort(s.begin()+(n+1)/2,s.end(),greater<char>());
        return s;

    }
};