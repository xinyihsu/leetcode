#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    int len;
    int count = 0;
    string myString;
    vector<pair<string, int>> point;

public:
    int maximumGain(string s, int x, int y) {
        myString = s;
        len = s.length();
        if (x > y) {
            point.push_back(make_pair("ab", x));
            point.push_back(make_pair("ba", y));
        }
        else {
            point.push_back(make_pair("ba", y));
            point.push_back(make_pair("ab", x));
        }

        stack<char> myStack;
        for (size_t i = 0; i < len; i++) {
            if (myStack.empty()) {
                myStack.push(s[i]);
                continue;
            }

            if(myStack.top() == point[0].first[0] && s[i] == point[0].first[1]) {
                myStack.pop();
                count += point[0].second;
            }
            else {
                myStack.push(s[i]);
            }
        }

        len = myStack.size();
        stack<char> tempStack;
        while (!myStack.empty()) {
            char current = myStack.top();
            myStack.pop();

            if (tempStack.empty()) {
                tempStack.push(current);
                continue;
            }

            if(tempStack.top() == point[0].first[0] && current == point[0].first[1]) {
                tempStack.pop();
                count += point[1].second;
            }
            else {
                tempStack.push(current);
            }
        }

            // cout << count << " " << s;
            return count;
    }
};

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;

    Solution mySolution;
    cout << mySolution.maximumGain(s, x, y);
}