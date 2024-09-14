//2419. Longest Subarray With Maximum Bitwise AND
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, maxCount = 0, max = 0;

        for (const int& i: nums) {
            if (i == max) {
                count++;
            } else if (i > max) {
                count = 1;
                maxCount = 0;
                max = i;
            } else {
                if (count > maxCount) {
                    maxCount = count;
                }
                count = 0;
            }
        }

        return maxCount > count ? maxCount : count;
    }
};