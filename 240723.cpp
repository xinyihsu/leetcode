/*1636. Sort Array by Increasing Frequency*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
private:
    map<int, set<int>> sort;
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        countNumber(nums);

        for (auto i : sort) {
            for (auto it = i.second.rbegin(); it != i.second.rend(); it++) {
                for (int k = 0; k < i.first; k++) {
                    ans.push_back(*it);
                }
            }
        }
    }

    void countNumber(vector<int>& nums) {
        map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++) {
            auto it = frequency.find(nums[i]);
            if (it != frequency.end()) {
                it->second += 1;
            }
            else {
                frequency.insert(pair<int, int>(nums[i], 1));
            }
        }

        //map<int, set<int>> sort; //(frequency, num)
        for (auto i : frequency) {
            auto it = sort.find(i.second);

            if (it != sort.end()) {
                it->second.insert(i.first);
            }
            else {
                set<int> temp;
                temp.insert(i.first);
                sort.insert(pair<int, set<int>>(i.second, temp));
            }
            
        }
    }
};

int main() {
    int x;
    

    Solution mySolution;
}