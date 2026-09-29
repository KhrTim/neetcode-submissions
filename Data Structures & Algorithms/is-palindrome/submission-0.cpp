class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = static_cast<int>(s.size()) - 1;
        while (l < r) {
            if (not std::isalnum(static_cast<unsigned char>(s[l])))
                l++;
            else if (not std::isalnum(static_cast<unsigned char>(s[r])))
                r--;
            else if (std::tolower(static_cast<unsigned char>(s[r])) !=
                     std::tolower(static_cast<unsigned char>(s[l]))) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
};
