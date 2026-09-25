class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;

        function<set<string>()> solve = [&]() {
            set<string> res;

            while (i < expression.size() &&
                   expression[i] != '}' &&
                   expression[i] != ',') {

                set<string> cur;

                if (expression[i] == '{') {
                    i++; // skip '{'

                    while (true) {
                        set<string> temp = solve();

                        // UNION
                        cur.insert(temp.begin(), temp.end());

                        if (expression[i] == ',') {
                            i++;
                        }
                        else {
                            i++; // skip '}'
                            break;
                        }
                    }
                }
                else {
                    // Single character
                    cur.insert(string(1, expression[i]));
                    i++;
                }

                // CONCATENATION
                if (res.empty()) {
                    res = cur;
                }
                else {
                    set<string> next;

                    for (string a : res) {
                        for (string b : cur) {
                            next.insert(a + b);
                        }
                    }

                    res = next;
                }
            }

            return res;
        };

        set<string> ans = solve();

        return vector<string>(ans.begin(), ans.end());
    }
};