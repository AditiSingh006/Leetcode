class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;

        int prevTime = 0;

        for (string log : logs) {
            // Split log: id:type:time
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                // Current function was running before this start
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }

                st.push(id);
                prevTime = time;
            }
            else {
                // Current function runs until the END of this timestamp
                ans[st.top()] += time - prevTime + 1;

                st.pop();

                // Parent resumes from the next timestamp
                prevTime = time + 1;
            }
        }

        return ans;
    }
};