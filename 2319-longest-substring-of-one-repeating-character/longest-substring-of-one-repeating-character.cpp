#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Node {
        int presum = 0, suffsum = 0, maxlen = 0, len = 0;
        char lchar = 0, rchar = 0;
    };

    Node merge(Node a, Node b) {
        Node merged;
        merged.len = a.len + b.len;
        int junction = 0;
        
        if (a.rchar == b.lchar) junction = a.suffsum + b.presum;

        int mx = max(junction, max(a.maxlen, b.maxlen));
        
        int pre = (a.presum == a.len && a.rchar == b.lchar) ? junction : a.presum;
        int suf = (b.suffsum == b.len && b.lchar == a.rchar) ? junction : b.suffsum;

        merged = {pre, suf, mx, merged.len, a.lchar, b.rchar};
        return merged;     
    }

    vector<Node> segtree;
    
    void build(int i, int l, int r, string &s) {
        if (l == r) {
            segtree[i] = {1, 1, 1, 1, s[l], s[r]};
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, s);
        build(2 * i + 2, mid + 1, r, s);
        segtree[i] = merge(segtree[2 * i + 1], segtree[2 * i + 2]);
    }
    
    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segtree[i] = {1, 1, 1, 1, ch, ch};
            return;
        }
        int mid = l + (r - l) / 2;
        
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        
        segtree[i] = merge(segtree[2 * i + 1], segtree[2 * i + 2]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        segtree.resize(4 * n);
        build(0, 0, n - 1, s);

        vector<int> ans;
        for (int k = 0; k < queryCharacters.size(); ++k) {
            update(0, 0, n - 1, queryIndices[k], queryCharacters[k]);
            ans.push_back(segtree[0].maxlen);
        }
        return ans;
    }
};