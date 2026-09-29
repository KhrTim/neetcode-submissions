class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encoded_string = "";
        for(const auto& st : strs)
        {
            int str_len = st.length();
            encoded_string += '|';
            encoded_string += std::to_string(str_len);
            encoded_string += '|';
            encoded_string += st;

        }
        return encoded_string;
    }

    vector<string> decode(string s) {
    vector<string> strs;
    bool opened = false;
    string cur_str_len_st;
    string cur_str_symb;
    int st_chr_count = 0;
    for(const auto& ch : s)
    {
        if(ch == '|' and st_chr_count == 0)
        {
            if(opened)
            {
                st_chr_count = std::stoi(cur_str_len_st);
                if(st_chr_count == 0)
                {
                    strs.push_back("");
                }
                cout << st_chr_count << '\n';
                cur_str_len_st = "";
                opened = false;
            }
            else
            {
                opened = true;
            }
        }
        else if(opened and isdigit(ch))
        {
            cur_str_len_st += ch;
        }
        else if(st_chr_count != 0 and not opened)
        {
            cur_str_symb += ch;
            st_chr_count-=1;
            if (st_chr_count == 0)
            {
                cout << cur_str_symb;
                strs.push_back(cur_str_symb);
                cur_str_symb = "";
            }
        }
    }
    return strs;
}
};
