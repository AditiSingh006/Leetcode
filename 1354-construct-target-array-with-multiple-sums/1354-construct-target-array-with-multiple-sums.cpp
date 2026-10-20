class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;

        for (int x : target) {
            pq.push(x);
            sum += x;
        }

        while (true) {
            long long largest = pq.top();
            pq.pop();

            long long rest = sum - largest;

            // If all elements are 1, we have reached the start
            if (largest == 1 || rest == 1)
                return true;

            // Invalid cases
            if (rest == 0 || largest <= rest)
                return false;

            // Reverse the last operation
            long long previous = largest % rest;

            if (previous == 0)
                return false;

            sum = rest + previous;
            pq.push(previous);
        }
    }
};