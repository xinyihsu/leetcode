//2220. Minimum Bit Flips to Convert Number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int> startBinary = createBinary(start);
        vector<int> goalBinary = createBinary(goal);
        int diff = startBinary.size() - goalBinary.size();

        while (diff != 0) {
            if (diff < 0) {
                startBinary.push_back(0);
                diff += 1;
            }else {
                goalBinary.push_back(0);
                diff -= 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < startBinary.size(); i++) {
            if (startBinary[i] ^ goalBinary[i]) ans++;
        }
        
        return ans;
    }

    vector<int> createBinary(int num) {
        vector<int> binary;

        while (num) {
            binary.push_back(num % 2);
            num /= 2;
        }
        
        return binary;
    }
};

int main() {
    Solution s;
    int start, goal;

    cin >> start >> goal;
    s.minBitFlips(start, goal);
}