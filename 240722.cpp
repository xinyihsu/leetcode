#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> people;
        vector<string> ans;

        for (int i = 0; i < names.size(); i++) {
            people.insert(pair<int, string>(heights[i], names[i]));
        }

        for (auto it = people.rbegin(); it != people.rend(); it++) {
            ans.push_back((*it).second);
        }

        return ans;
    }
};