#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the floor mean of elements for multiple ranges [L, R].
     * Time Complexity: O(n + q)
     * Space Complexity: O(n) 
     */
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // 1. Precompute Prefix Sums
        // Using long long to prevent overflow during summation
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }

        vector<int> results;
        results.reserve(queries.size()); // Optimization: pre-allocate memory

        // 2. Answer Queries in O(1) each
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];

            // Formula for sum of range [L, R]: pref[R+1] - pref[L]
            long long rangeSum = pref[R + 1] - pref[L];
            int numElements = R - L + 1;

            // Integer division provides the floor of the mean
            results.push_back(static_cast<int>(rangeSum / numElements));
        }

        return results;
    }
};
