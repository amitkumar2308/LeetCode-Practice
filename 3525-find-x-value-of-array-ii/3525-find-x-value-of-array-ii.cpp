class Solution {
public:

    struct Node {
        long long prod;
        long long cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> seg;

    Node merge(Node &L, Node &R) {
        Node res;

        // Product of whole segment
        res.prod = (L.prod * R.prod) % k;

        // Prefixes ending inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefixes entering right segment
        for (int r = 0; r < k; r++) {
            int newRem = (L.prod * r) % k;
            res.cnt[newRem] += R.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            nums[l] %= k;

            seg[node].prod = nums[l];

            // Single element is one possible prefix
            seg[node].cnt[nums[l]] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {

        if (l == r) {

            val %= k;

            seg[node].prod = val;

            memset(seg[node].cnt, 0, sizeof(seg[node].cnt));

            seg[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        // Entirely in right
        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Entirely in left
        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        // Split query
        Node L = query(node * 2, l, mid, ql, qr);
        Node R = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->nums = nums;
        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};