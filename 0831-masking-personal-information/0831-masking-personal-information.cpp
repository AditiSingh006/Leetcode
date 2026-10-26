class Solution {
public:
    string maskPII(string s) {
        int at = s.find('@');

        // Case 1: Email address
        if (at != string::npos) {
            for (char &c : s)
                c = tolower(c);

            string name = s.substr(0, at);
            string domain = s.substr(at);

            return name.substr(0, 1) + "*****" +
                   name.substr(name.size() - 1) + domain;
        }

        // Case 2: Phone number
        string digits = "";

        for (char c : s) {
            if (isdigit(c))
                digits += c;
        }

        int country = digits.size() - 10;

        string ans = "";

        if (country > 0)
            ans = "+" + string(country, '*') + "-";

        ans += "***-***-";
        ans += digits.substr(digits.size() - 4);

        return ans;
    }
};