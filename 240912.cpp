//1684. Count the Number of Consistent Strings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for std::remove
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;

        for (string i: words) {
            //erase allowed char
            for (char j: allowed) {
                i.erase(remove(i.begin(), i.end(), j), i.end());
            }

            if (i == "") count++;
        }

        return count;
    }
};

int main() {
    Solution s;
}