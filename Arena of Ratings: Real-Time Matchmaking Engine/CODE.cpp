#include <iostream>
#include <string>
#include <algorithm>    // for max
using namespace std;

/* -------- Node Definition -------- */
struct Node {
    int rating;
    string name;
    long long hp;
    Node *left;
    Node *right;
    int sz;   // subtree size

    Node(int r, const string &n, long long h) {
        rating = r;
        name   = n;
        hp     = h;
        left   = NULL;
        right  = NULL;
        sz     = 1;
    }
};

int getSize(Node *t) {
    return t ? t->sz : 0;
}

void updateSize(Node *t) {
    if (t) {
        t->sz = 1 + getSize(t->left) + getSize(t->right);
    }
}

/* -------- BST Class -------- */
class ArenaBST {
    Node *root;

    /* Insert a new player (recursive) */
    Node* insert(Node *cur, int r, const string &n, long long h) {
        if (!cur) return new Node(r, n, h);
        if (r < cur->rating) cur->left  = insert(cur->left,  r, n, h);
        else if (r > cur->rating) cur->right = insert(cur->right, r, n, h);
        // equal rating will not happen; JOIN checks duplicates first
        updateSize(cur);
        return cur;
    }

    /* Search by rating */
    Node* find(Node *cur, int r) const {
        if (!cur || cur->rating == r) return cur;
        if (r < cur->rating) return find(cur->left, r);
        return find(cur->right, r);
    }

    /* Find minimum node in subtree */
    Node* findMin(Node *cur) const {
        if (!cur) return NULL;
        while (cur->left) cur = cur->left;
        return cur;
    }

    /* Find maximum node in subtree */
    Node* findMax(Node *cur) const {
        if (!cur) return NULL;
        while (cur->right) cur = cur->right;
        return cur;
    }

    /* Delete by rating */
    Node* remove(Node *cur, int r) {
        if (!cur) return NULL;

        if (r < cur->rating) {
            cur->left = remove(cur->left, r);
        } else if (r > cur->rating) {
            cur->right = remove(cur->right, r);
        } else {
            // found node
            if (!cur->left && !cur->right) {
                delete cur;
                return NULL;
            } else if (!cur->left) {
                Node *t = cur->right;
                delete cur;
                return t;
            } else if (!cur->right) {
                Node *t = cur->left;
                delete cur;
                return t;
            } else {
                // two children: use inorder successor
                Node *succ = findMin(cur->right);
                cur->rating = succ->rating;
                cur->name   = succ->name;
                cur->hp     = succ->hp;
                cur->right  = remove(cur->right, succ->rating);
            }
        }
        updateSize(cur);
        return cur;
    }

    /* Successor (NEXT): smallest rating > X */
    Node* successor(Node *cur, int X) const {
        Node *ans = NULL;
        while (cur) {
            if (cur->rating > X) {
                ans = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return ans;
    }

    /* Predecessor (PREV): largest rating < X */
    Node* predecessor(Node *cur, int X) const {
        Node *ans = NULL;
        while (cur) {
            if (cur->rating < X) {
                ans = cur;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return ans;
    }

    /* In-order RANGE [L, R] printing */
    void rangePrint(Node *cur, int L, int R, bool &printedAny) const {
        if (!cur) return;
        if (cur->rating > L) rangePrint(cur->left, L, R, printedAny);
        if (cur->rating >= L && cur->rating <= R) {
            cout << cur->rating << " " << cur->name << " " << cur->hp << "\n";
            printedAny = true;
        }
        if (cur->rating < R) rangePrint(cur->right, L, R, printedAny);
    }

    /* Total number of players */
    int totalPlayers(Node *cur) const {
        return getSize(cur);
    }

    /* Tree height: empty = -1, leaf = 0 */
    int treeHeight(Node *cur) const {
        if (!cur) return -1;
        return 1 + std::max(treeHeight(cur->left), treeHeight(cur->right));
    }

    /* Leaf count */
    int leafNodes(Node *cur) const {
        if (!cur) return 0;
        if (!cur->left && !cur->right) return 1;
        return leafNodes(cur->left) + leafNodes(cur->right);
    }

    /* RANK: number of ratings strictly less than X */
    int rankLess(Node *cur, int X) const {
        if (!cur) return 0;
        if (X <= cur->rating) {
            return rankLess(cur->left, X);
        } else {
            return getSize(cur->left) + 1 + rankLess(cur->right, X);
        }
    }

    /* KTH smallest (1-indexed) using subtree sizes */
    Node* kth(Node *cur, int k) const {
        if (!cur) return NULL;
        int leftSize = getSize(cur->left);
        if (k == leftSize + 1) return cur;
        if (k <= leftSize) return kth(cur->left, k);
        return kth(cur->right, k - (leftSize + 1));
    }

    /* Depth (number of edges from root to rating key) */
    int depth(Node *cur, int key) const {
        int d = 0;
        while (cur) {
            if (key == cur->rating) return d;
            if (key < cur->rating) cur = cur->left;
            else cur = cur->right;
            d++;
        }
        return -1; // not found
    }

    /* LCA (Lowest Common Ancestor) using keys in BST */
    Node* lca(Node *cur, int a, int b) const {
        while (cur) {
            if (a < cur->rating && b < cur->rating) {
                cur = cur->left;
            } else if (a > cur->rating && b > cur->rating) {
                cur = cur->right;
            } else {
                return cur; // split or equal
            }
        }
        return NULL;
    }

public:
    ArenaBST() {
        root = NULL;
    }

    /* JOIN: insert unique rating */
    void joinPlayer(int r, const string &n, long long h) {
        if (find(root, r)) {
            cout << "DUPLICATE\n";
        } else {
            root = insert(root, r, n, h);
            cout << "JOINED\n";
        }
    }

    /* LEAVE: remove player by rating */
    void removePlayer(int r) {
        if (!find(root, r)) {
            cout << "NOT FOUND\n";
        } else {
            root = remove(root, r);
            cout << "LEFT\n";
        }
    }

    /* STATUS: print rating name hp or NOT FOUND */
    void showStatus(int r) const {
        Node *p = find(root, r);
        if (!p) {
            cout << "NOT FOUND\n";
        } else {
            cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }
    }

    /* DAMAGE: hp = max(0, hp - d) */
    void applyDamage(int r, long long d) {
        Node *p = find(root, r);
        if (!p) {
            cout << "NOT FOUND\n";
        } else {
            long long newHp = p->hp - d;
            if (newHp < 0) newHp = 0;
            p->hp = newHp;
            cout << "DAMAGED " << p->hp << "\n";
        }
    }

    /* HEAL: hp += h */
    void healPlayer(int r, long long h) {
        Node *p = find(root, r);
        if (!p) {
            cout << "NOT FOUND\n";
        } else {
            p->hp += h;
            cout << "HEALED " << p->hp << "\n";
        }
    }

    /* NEXT: successor of X */
    void nextPlayer(int X) const {
        Node *s = successor(root, X);
        if (!s) cout << "NONE\n";
        else cout << s->rating << " " << s->name << " " << s->hp << "\n";
    }

    /* PREV: predecessor of X */
    void prevPlayer(int X) const {
        Node *p = predecessor(root, X);
        if (!p) cout << "NONE\n";
        else cout << p->rating << " " << p->name << " " << p->hp << "\n";
    }

    /* MATCH X: closest-rated opponent */
    void matchPlayer(int X) const {
        Node *P = predecessor(root, X);
        Node *S = successor(root, X);

        if (!P && !S) {
            cout << "EMPTY\n";
            return;
        }
        Node *best = NULL;
        if (P && !S) best = P;
        else if (!P && S) best = S;
        else {
            int dP = abs(X - P->rating);
            int dS = abs(S->rating - X);
            if (dP <= dS) best = P;   // tie -> predecessor
            else best = S;
        }
        cout << best->rating << " " << best->name << " " << best->hp << "\n";
    }

    /* RANGE L R: print players in [L, R] in sorted order */
    void rangePlayers(int L, int R) const {
        bool printedAny = false;
        rangePrint(root, L, R, printedAny);
        if (!printedAny) cout << "EMPTY\n";
    }

    /* STATS: size, min, max, height, leaves */
    void printStats() const {
        int sz = totalPlayers(root);
        int h  = treeHeight(root);
        int leaves = leafNodes(root);

        cout << "SIZE " << sz << "\n";
        if (!root) {
            cout << "MIN NONE\n";
            cout << "MAX NONE\n";
        } else {
            Node *mn = findMin(root);
            Node *mx = findMax(root);
            cout << "MIN " << mn->rating << " " << mn->name << " " << mn->hp << "\n";
            cout << "MAX " << mx->rating << " " << mx->name << " " << mx->hp << "\n";
        }
        cout << "HEIGHT " << h << "\n";
        cout << "LEAVES " << leaves << "\n";
    }

    /* RANK X: number of ratings < X */
    void rankQuery(int X) const {
        int ans = rankLess(root, X);
        cout << ans << "\n";
    }

    /* KTH k: k-th smallest rating */
    void kthQuery(int k) const {
        if (k <= 0 || k > getSize(root)) {
            cout << "INVALID\n";
            return;
        }
        Node *res = kth(root, k);
        if (!res) cout << "INVALID\n";
        else cout << res->rating << " " << res->name << " " << res->hp << "\n";
    }

    /* DUEL A B: distance in edges between two nodes (ratings A and B) */
    void duelQuery(int A, int B) const {
        Node *nA = find(root, A);
        Node *nB = find(root, B);
        if (!nA || !nB) {
            cout << "NOT FOUND\n";
            return;
        }
        Node *L = lca(root, A, B);
        int dA = depth(root, A);
        int dB = depth(root, B);
        int dL = depth(root, L->rating);
        int dist = dA + dB - 2 * dL;
        cout << "DIST " << dist << "\n";
    }
};

/* -------- Main -------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;
     cout << "---------------------\n";

    ArenaBST arena;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "JOIN") {
            int r; long long h;
            string n;
            cin >> r >> n >> h;
            arena.joinPlayer(r, n, h);
        } else if (cmd == "LEAVE") {
            int r; cin >> r;
            arena.removePlayer(r);
        } else if (cmd == "STATUS") {
            int r; cin >> r;
            arena.showStatus(r);
        } else if (cmd == "DAMAGE") {
            int r; long long d;
            cin >> r >> d;
            arena.applyDamage(r, d);
        } else if (cmd == "HEAL") {
            int r; long long h;
            cin >> r >> h;
            arena.healPlayer(r, h);
        } else if (cmd == "NEXT") {
            int x; cin >> x;
            arena.nextPlayer(x);
        } else if (cmd == "PREV") {
            int x; cin >> x;
            arena.prevPlayer(x);
        } else if (cmd == "MATCH") {
            int x; cin >> x;
            arena.matchPlayer(x);
        } else if (cmd == "RANGE") {
            int L, R; cin >> L >> R;
            arena.rangePlayers(L, R);
        } else if (cmd == "STATS") {
            arena.printStats();
        } else if (cmd == "RANK") {
            int X; cin >> X;
            arena.rankQuery(X);
        } else if (cmd == "KTH") {
            int k; cin >> k;
            arena.kthQuery(k);
        } else if (cmd == "DUEL") {
            int A, B; cin >> A >> B;
            arena.duelQuery(A, B);
        }
    }
    
    

    return 0;
}
