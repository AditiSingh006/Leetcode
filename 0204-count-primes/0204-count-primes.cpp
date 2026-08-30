class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Only store odd numbers.
        // index i represents number (2*i + 1)
        int size = n / 2;
        vector<bool> isPrime(size, true);

        // index 0 -> number 1, which isn't prime
        isPrime[0] = false;

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i / 2]) {
                // Start at i*i
                // We only mark odd multiples
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        int count = 1; // 2 is prime

        for (int i = 1; i < size; i++) {
            if (isPrime[i])
                count++;
        }

        return count;
    }
};