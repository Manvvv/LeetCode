class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    int curPos;

    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int size) {
            n = size;
            tree.assign(4 * n, 0);
        }

        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
                return;
            }

            int mid = (start + end) / 2;

            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);

            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return tree[node];

            int mid = (start + end) / 2;

            return query(2 * node, start, mid, l, r)
                 ^ query(2 * node + 1, mid + 1, end, l, r);
        }
    };

    int dfs(int v, int p) {
        parent[v] = p;
        subtree[v] = 1;
        int maxSize = 0;

        for (int u : adj[v]) {
            if (u == p) continue;

            depth[u] = depth[v] + 1;
            int size = dfs(u, v);
            subtree[v] += size;

            if (size > maxSize) {
                maxSize = size;
                heavy[v] = u;
            }
        }

        return subtree[v];
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = curPos++;

        if (heavy[v] != -1)
            decompose(heavy[v], h);

        for (int u : adj[v]) {
            if (u != parent[v] && u != heavy[v])
                decompose(u, u);
        }
    }

    int queryPath(int a, int b, SegTree& seg) {
        int res = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]])
                swap(a, b);

            res ^= seg.query(1, 0, seg.n - 1, pos[head[a]], pos[a]);
            a = parent[head[a]];
        }

        if (depth[a] > depth[b]) swap(a, b);

        res ^= seg.query(1, 0, seg.n - 1, pos[a], pos[b]);

        return res;
    }

    // ✅ EXACT FUNCTION NAME LEETCODE EXPECTS
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        curPos = 0;
        decompose(0, 0);

        SegTree seg(n);

        // Build segment tree
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            seg.update(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> answer;

        for (string& q : queries) {

            if (q[0] == 'u') {  // update

                int spacePos = q.find_last_of(' ');
                int node = stoi(q.substr(7, spacePos - 7));
                char c = q.back();

                int mask = 1 << (c - 'a');
                seg.update(1, 0, n - 1, pos[node], mask);
            }
            else {              // query

                int spacePos = q.find(' ', 6);
                int u = stoi(q.substr(6, spacePos - 6));
                int v = stoi(q.substr(spacePos + 1));

                int mask = queryPath(u, v, seg);

                answer.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return answer;
    }
};

