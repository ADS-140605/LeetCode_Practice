# LeetCode 403 — Frog Jump — Complete Notes

## Problem Statement

A frog crosses a river by jumping on stones. Given `stones[]` (sorted, strictly increasing, `stones[0] == 0`), determine if the frog can reach the **last stone**.

Rules:
- First jump must be exactly `1` unit.
- If the last jump was `k` units, the next jump must be `k-1`, `k`, or `k+1` units.
- Jump size must always be **positive** (no zero or backward jumps).

**Constraints:** `2 <= stones.length <= 2000`, `0 <= stones[i] <= 2^31 - 1`

---

## Core Idea

State = **(current stone index, size of the last jump)**.
From any state, try the 3 possible next jump sizes (`k-1`, `k`, `k+1`), and recurse/iterate if a stone exists at that landing spot.

Base case: reaching the last index → success.

---

## Bugs Found Along the Way (in order encountered)

1. **Inverted membership check** — checking "does this position already exist → fail" instead of "does the next landing spot exist → proceed."
2. **`mp[...]` used as a lookup** — `unordered_map::operator[]` **inserts** a default entry (0) for missing keys. Always use `mp.find(...)` + compare to `mp.end()` when just *checking* existence.
3. **No memoization** — naive recursion is exponential (`O(3^n)`), which TLEs for `n` up to 2000.
4. **Wrong starting call** — starting at `(index 0, k=0)` works "by luck" through the `k+1` branch, but the clean start is `(index of stone 1, k=1)` since the first jump is validated as size 1 upfront.
5. **`result = solve(...)` inside a loop** (no `||`) — each iteration **overwrites** `result`, silently discarding an earlier success. Must accumulate with `||` or `return true` immediately.
6. **Looking up the wrong key** — `mp[next_k]` (jump size) instead of `mp[stones[crr_idx] + next_k]` (actual landing stone value). `mp` maps *stone value → index*, so you must search by value, not by jump size.
7. **`memset(dp, -1, sizeof(dp))` placed directly in the class body** — illegal; statements must be inside a function. Belongs at the top of `canCross`.
8. **Checking `dp[idx][k]` before checking `k < 0`** — risks negative array indexing (undefined behavior) if `k` is ever negative. Always validate bounds *before* touching the array.

---

## Final Working Solution — Memoization (Top-Down), Dense Array

```cpp
class Solution {
public:
    int n;
    unordered_map<int,int> mp;      // stone value -> index
    int dp[2001][2001];             // dp[idx][k] = -1 unknown, 0 fail, 1 success

    bool solve(vector<int>& stones, int crr_idx, int k){
        if (crr_idx == n - 1) return true;
        if (k <= 0) return false;
        if (dp[crr_idx][k] != -1) return dp[crr_idx][k];

        bool result = false;
        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) continue;
            auto it = mp.find(stones[crr_idx] + next_k);
            if (it != mp.end()) {
                if (solve(stones, it->second, next_k)) { result = true; break; }
            }
        }
        dp[crr_idx][k] = result;
        return result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (n == 1) return true;
        if (stones[1] != 1) return false;

        memset(dp, -1, sizeof(dp));
        mp.clear();
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        return solve(stones, mp[1], 1);
    }
};
```

**Complexity:** looks like `O(n²)` time/space from the array size, but see the space-optimization section below — the real bound is much tighter.

---

## Tabulation (Bottom-Up) Version

Instead of recursing backward from the end, walk **forward** from stone 0, tracking which jump sizes can land you on each stone.

```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return true;
        if (stones[1] != 1) return false;

        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        vector<unordered_set<int>> dp(n);   // dp[i] = set of jump sizes that can land on stone i
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                for (int next_k = k - 1; next_k <= k + 1; next_k++) {
                    if (next_k <= 0) continue;
                    auto it = mp.find(stones[i] + next_k);
                    if (it != mp.end()) {
                        if (it->second == n - 1) return true;
                        dp[it->second].insert(next_k);
                    }
                }
            }
        }
        return false;
    }
};
```

**Memo vs. Tabulation — which to prefer here:** Memoization is generally the better fit for this problem. The reachable `(index, k)` state space is naturally sparse and driven by the recursion itself, so top-down only visits states that matter and can short-circuit (`return true`) the instant a path is found. Tabulation processes every stone in a fixed forward order even for dead-end paths, and recursion depth isn't a real risk here (`n ≤ 2000`).

---

## Space-Optimized Version (Recommended Final Answer)

The `dp[2001][2001]` array is mostly empty in practice. Why: jump size `k` can grow by at most 1 per jump, so after `m` jumps the max reachable distance is roughly `1+2+...+m ≈ m²`. Since stone values are bounded (~2000 range for `n` up to 2000), `m² ≲ n`, meaning **`k` never actually grows past roughly `√n`** — the dense `2001×2001` array reserves way more space than is ever touched.

**Fix:** replace the dense array with a sparse hash-based structure — only store `(index, k)` states that actually occur.

```cpp
class Solution {
public:
    int n;
    unordered_map<int,int> mp;                 // stone value -> index
    vector<unordered_set<int>> visited;         // visited[i] = set of k's already tried & failed at stone i

    bool solve(vector<int>& stones, int crr_idx, int k){
        if (crr_idx == n - 1) return true;
        if (k <= 0) return false;
        if (visited[crr_idx].count(k)) return false;
        visited[crr_idx].insert(k);

        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) continue;
            auto it = mp.find(stones[crr_idx] + next_k);
            if (it != mp.end()) {
                if (solve(stones, it->second, next_k)) return true;
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (n == 1) return true;
        if (stones[1] != 1) return false;

        mp.clear();
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        visited.assign(n, unordered_set<int>());
        return solve(stones, mp[1], 1);
    }
};
```

**Real complexity:** `O(n√n)` time, `O(n√n)` space — far better than the naive `O(n²)` array suggests.

---

## Bonus: Path Reconstruction

To return the *actual sequence of stones* the frog lands on (not just true/false), add a parallel table recording which `next_k` led to success.

```cpp
class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];
    int choice[2001][2001];   // choice[idx][k] = the next_k that worked (-1 if none)

    bool solve(vector<int>& stones, int crr_idx, int k){
        if (crr_idx == n - 1) return true;
        if (k <= 0) return false;
        if (dp[crr_idx][k] != -1) return dp[crr_idx][k];

        bool result = false;
        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) continue;
            auto it = mp.find(stones[crr_idx] + next_k);
            if (it != mp.end()) {
                if (solve(stones, it->second, next_k)) {
                    result = true;
                    choice[crr_idx][k] = next_k;
                    break;
                }
            }
        }
        dp[crr_idx][k] = result;
        return result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;

        memset(dp, -1, sizeof(dp));
        memset(choice, -1, sizeof(choice));
        mp.clear();
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        bool result = solve(stones, mp[1], 1);

        if (result) {
            vector<int> path = {stones[0], stones[1]};
            int idx = mp[1], k = 1;
            while (idx != n - 1) {
                int next_k = choice[idx][k];
                idx = mp[stones[idx] + next_k];
                k = next_k;
                path.push_back(stones[idx]);
            }
            // `path` now holds the sequence of stones visited
        }
        return result;
    }
};
```

**Key idea:** the recursion logic is unchanged — just record `choice[idx][k] = next_k` right before returning `true`. Reconstruct by walking forward from `(index of stone 1, k=1)`, following `choice[]` at each step.

---

## Follow-Up Questions & Answers

### 1. Tighten the complexity bound
`dp[2001][2001]` *looks* like `O(n²)`, but `k` never actually grows past `~√n`. Since jump sizes increase by at most 1 per step, the total distance covered after `m` jumps is `~m²`, and stone positions are bounded by `n`. So `m² ≲ n → m ≲ √n`. Real complexity: **`O(n√n)`** time and space, not `O(n²)`.

### 2. Multiple frogs, each stone usable only once (no two frogs on the same stone at the same time)
This becomes a **scheduling/matching problem**, not just reachability. First compute all possible paths per frog (via the DP, tracking full paths). Then assign each frog a path such that no two frogs occupy the same stone at the same time — this resembles multi-agent pathfinding / bipartite matching over (stone, time-slot) resources. Fundamentally harder than the single-frog case.

### 3. Frog can jump backward too, can't revisit a stone
Forward-only movement lets you use *index* as state, which is compact. Once backward jumps are allowed, the same stone can be reached via different visit-histories, and you must track the **full set of visited stones** to avoid repeats. State becomes `(current stone, visited set)` — exponential in the worst case (same flavor as Traveling Salesman Problem).

### 4. Online version — stones arrive one at a time; answer reachability after each new stone
Don't recompute from scratch. Keep the `mp` and memo/DP tables growable. When a new stone arrives, add it to `mp`, check which earlier `(index, k)` states could jump directly to it, and update reachability incrementally rather than rebuilding everything.

### 5. BFS instead of DFS — what do you gain?
DFS + memo only answers yes/no. **BFS explores states level-by-level**, so the first time the last stone is reached, the number of levels processed equals the **minimum number of jumps** needed to cross — extra information DFS doesn't give for free.

```cpp
// state = (stone index, last jump size)
queue<pair<int,int>> q;
q.push({1, 1});
unordered_set<long long> visited;

int jumps = 1;
while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
        auto [idx, k] = q.front(); q.pop();
        if (idx == n - 1) return jumps;

        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) continue;
            auto it = mp.find(stones[idx] + next_k);
            if (it != mp.end()) {
                long long key = (long long)it->second * 2001 + next_k;
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push({it->second, next_k});
                }
            }
        }
    }
    jumps++;
}
return -1; // can't cross
```

Trade-off: BFS needs a queue + `visited` set, slightly more bookkeeping than DFS+memo, but both touch roughly the same set of `(index, k)` states overall — BFS just processes them in level order to extract the "minimum jumps" guarantee.

---

## Summary Table

| Approach | Time | Space | Notes |
|---|---|---|---|
| Naive recursion | O(3^n) | O(n) stack | TLEs, no memo |
| Memo, dense `dp[2001][2001]` | O(n√n) real / O(n²) allocated | O(n²) allocated | Simple, but wastes memory |
| Tabulation, `vector<unordered_set<int>>` | O(n√n) | O(n√n) | Bottom-up, forward pass |
| Memo, sparse `unordered_set` per index | O(n√n) | O(n√n) | **Best balance** — recommended |
| + path reconstruction | same + O(path length) | + O(n√n) for `choice[][]` | Adds one parallel table |
| BFS variant | O(n√n) | O(n√n) | Also gives minimum jump count |
