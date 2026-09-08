#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;

        // Convert linked list to array
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(arr.size(), 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Remove elements smaller than or equal to current
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Top is the next greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};