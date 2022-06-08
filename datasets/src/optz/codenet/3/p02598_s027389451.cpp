#include <bits/stdc++.h>
using namespace std;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    // http://yohshiy.blog.fc2.com/blog-entry-300.html
    // https://ja.wikipedia.org/wiki/C%2B%2B11#.E5.8F.AF.E5.A4.89.E9.95.B7.E5.BC.95.E6.95.B0.E3.83.86.E3.83.B3.E3.83.97.E3.83.AC.E3.83.BC.E3.83.88
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print1() {}
template <typename Head, typename... Tail>
void print1(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print1(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 素数判定
bool is_prime(int64_t n) {
    if (n <= 1) {
        return false;
    }
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 約数の列挙
vector<int64_t> divisor(int64_t n) {
    vector<int64_t> res;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);  // n=6, i=2 => 3 を入れる. n=9, i=3 のときは除外.
            }
        }
    }
    return res;
}

// 素因数分解
map<int64_t, int64_t> prime_factor(int64_t n) {
    map<int64_t, int64_t> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (res.count(i) == 0) {
                res[i] = 0;
            }
            res[i]++;
            n = n / i;
        }
    }
    if (n != 1) {
        res[n] = 1;  // n自身が素数
    }
    return res;
}

// エラトステネスのふるい
vector<int64_t> mkprimes(int64_t N) {
    vector<bool> isprime(N + 1);
    vector<int64_t> primes;
    for (int64_t i = 0; i <= N; i++) {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;

    for (int64_t i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int64_t j = 2 * i; j <= N; j += i) {  // 素数iの倍数は素数ではない
                isprime[j] = false;
            }
        }
    }
    return primes;
}

// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
// https://qiita.com/Ushio/items/a19083514d087a57fc72
static const uint64_t FNV_OFFSET_BASIS_64 = 14695981039346656037LLU;
static const uint64_t FNV_PRIME_64 = 1099511628211LLU;
uint64_t fnv64(uint64_t dat) {
    uint64_t hash = FNV_OFFSET_BASIS_64;
    for (int i = 0; i < 8; i++) {
        hash = (FNV_PRIME_64 * hash) ^ (dat & 255);
        dat = dat >> 8;
    }
    return hash;
}

struct xstruct {
    int64_t val;
};
bool operator<=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val <= rhs.val;
}
bool operator<(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val < rhs.val;
}
bool operator>=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val >= rhs.val;
}
bool operator>(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val > rhs.val;
}
bool operator==(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val == rhs.val;
}
bool operator!=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val != rhs.val;
}
ostream& operator<<(ostream& os, xstruct const& xst) {
    return os << xst.val;
}
uint64_t xhash(xstruct& x) {
    return fnv64(x.val);
}

struct ystruct {
    double val;
    int64_t init_length;
    int64_t split_num;
};
bool operator<=(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val <= rhs.val;
}
bool operator<(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val < rhs.val;
}
bool operator>=(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val >= rhs.val;
}
bool operator>(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val > rhs.val;
}
bool operator==(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val == rhs.val;
}
bool operator!=(const ystruct& lhs, const ystruct& rhs) {
    return lhs.val != rhs.val;
}
ostream& operator<<(ostream& os, ystruct const& yst) {
    return os << yst.val;
}
uint64_t xhash(ystruct& x) {
    return fnv64(x.val);
}

struct kstruct {
    int64_t val;
};
bool operator<=(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val <= rhs.val;
}
bool operator<(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val < rhs.val;
}
bool operator>=(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val >= rhs.val;
}
bool operator>(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val > rhs.val;
}
bool operator==(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val == rhs.val;
}
bool operator!=(const kstruct& lhs, const kstruct& rhs) {
    return lhs.val != rhs.val;
}
ostream& operator<<(ostream& os, kstruct const& kst) {
    return os << kst.val;
}
uint64_t xhash(kstruct& k) {
    return fnv64(k.val);
}

// vector xvector
template <class T>
class bvector {
    // https://compute-sigma.com/2019/06/22/c%E3%81%AEvector%E3%82%92%E8%87%AA%E4%BD%9C%E3%81%97%E3%81%AA%E3%81%8C%E3%82%89%E5%AD%A6%E3%81%B6/
   public:
    T* array;
    uint64_t cap;
    uint64_t length;

    bvector() {
        cap = 5;
        array = new T[cap];
        length = 0;
    }
    bvector(uint64_t init_cap) {
        if (init_cap == 0) {
            throw exception();
        }
        cap = init_cap;
        array = new T[cap];
        length = cap;
    }
    ~bvector() {
        delete array;
    }
    void push_back(T n) {
        // https://blog.golang.org/slices-intro
        if (length == cap) {
            T* new_array = new T[cap * 2];
            memcpy(new_array, array, sizeof(T) * cap);
            delete array;
            array = new_array;
            cap = cap * 2;
        }
        array[length] = n;
        length++;
    }
    void erase(uint64_t position) {
        if (position >= length) {
            ;
        } else if (position == length - 1) {
            length--;
        } else {
            // array+positionの位置へ、array+position+1以降をコピー
            memcpy(array + position, array + position + 1, sizeof(T) * (length - position - 1));
            length--;
        }
    }
    void insert(uint64_t position, T n) {
        if (position > length) {
            ;
        } else if (position == length) {
            push_back(n);
        } else {
            // cap足りない可能性があるので増やしておく
            push_back(n);
            // 一つずつ後ろに追いやる
            for (uint64_t i = 1; i <= length - position; i++) {
                assign(length - i, array[length - i - 1]);
            }
            assign(position, n);
        }
    }
    T at(uint64_t position) {
        return array[position];
    }
    void assign(uint64_t position, T n) {
        array[position] = n;
    }
    uint64_t size() {
        return length;
    }
    void clear() {
        length = 0;
    }
    // int64_t operator[](uint64_t position) {
    //     return at(position);
    // }
};
using xvector = bvector<xstruct>;

// スタック xstack
template <class T>
class bstack {
   public:
    bvector<T>* vec;

    bstack() {
        vec = new bvector<T>();
    }
    ~bstack() {
        delete vec;
    }
    void push(T n) {
        vec->push_back(n);
    }
    T top() {
        return vec->at(vec->size() - 1);
    }
    void pop() {
        vec->erase(vec->size() - 1);
    }
    uint64_t size() {
        return vec->size();
    }
    bool empty() {
        return (vec->size() == 0);
    }
};
using xstack = bstack<xstruct>;

// 双方向キュー xdqueue
template <class T>
class bdqueue {
    // リングバッファ使用. 動的にサイズを増やせるほうがいいのだが難しいのでサイズ固定.
   public:
    bvector<T>* vec;
    uint64_t head;
    uint64_t tail;

    bdqueue(uint64_t max_size) {
        vec = new bvector<T>(max_size + 2);
        head = 0;
        tail = 1;
    }
    ~bdqueue() {
        delete vec;
    }
    void push_back(T n) {
        if (tail == vec->size()) {
            vec->assign(tail - 1, n);
            tail = 1;
        } else {
            vec->assign(tail - 1, n);
            tail++;
        }
        if (head == tail) {
            throw exception();
        }
    }
    void push_front(T n) {
        if (head == 0) {
            head = vec->size() - 1;
        } else {
            head--;
        }
        vec->assign(head, n);
        if (head == tail) {
            throw exception();
        }
    }
    T front() {
        return at(0);
    }
    T back() {
        if (head + 2 > tail) {
            return at(tail + vec->size() - 2 - head);
        } else {
            return at(tail - 2 - head);
        }
    }
    T at(uint64_t position) {
        uint64_t p = head + position;
        if (p >= vec->size()) {
            p = p - vec->size();
        }
        return vec->at(p);
    }
    void pop_front() {
        if (head == vec->size() - 1) {
            head = 0;
        } else {
            head++;
        }
        if (head == tail) {
            throw exception();
        }
    }
    void pop_back() {
        if (tail == 1) {
            tail = vec->size();
        } else {
            tail--;
        }
        if (head == tail) {
            throw exception();
        }
    }
    uint64_t size() {
        if (tail > head) {
            return tail - head - 1;
        } else {
            return vec->size() - head + tail - 1;
        }
    }
    bool empty() {
        return size() == 0;
    }
};
using xdqueue = bdqueue<xstruct>;

// キュー xqueue
template <class T>
class bqueue {
    // コンポジション (xdqueueの機能制限版)
   public:
    bdqueue<T>* q;

    bqueue(uint64_t max_size) {
        q = new bdqueue<T>(max_size);
    }
    ~bqueue() {
        delete q;
    }
    void push(T n) {
        q->push_back(n);
    }
    T front() {
        return q->front();
    }
    void pop() {
        q->pop_front();
    }
    uint64_t size() {
        return q->size();
    }
    bool empty() {
        return q->empty();
    }
};
using xqueue = bqueue<xstruct>;

// リスト xlist
template <class T>
struct blistnode {
    T val;
    blistnode<T>* next;
    blistnode<T>* prev;
};

template <class T>
class blist {
    // stlとだいぶ違う. ナイーブなC風.
   public:
    blistnode<T>* first;
    blistnode<T>* last;
    uint64_t length;

    blist() {
        first = NULL;
        last = NULL;
        length = 0;
    }
    ~blist() {
        blistnode<T>* node = begin();
        while (true) {
            if (node == NULL) {
                break;
            } else if (node->next == NULL) {
                delete node;
                break;
            } else {
                node = node->next;
                delete node->prev;
            }
        }
    }
    void push_front(T n) {
        if (first == NULL) {
            blistnode<T>* single = new blistnode<T>{val : n, next : NULL, prev : NULL};
            first = single;
            last = single;
        } else {
            blistnode<T>* front = new blistnode<T>{val : n, next : first, prev : NULL};
            first->prev = front;
            first = front;
        }
        length++;
    }
    void push_back(T n) {
        if (last == NULL) {
            blistnode<T>* single = new blistnode<T>{val : n, next : NULL, prev : NULL};
            first = single;
            last = single;
        } else {
            blistnode<T>* back = new blistnode<T>{val : n, next : NULL, prev : last};
            last->next = back;
            last = back;
        }
        length++;
    }
    void pop_front() {
        if (first == NULL) {
            throw exception();
        }
        blistnode<T>* old = first;
        first = first->next;
        delete old;
        length--;
    }
    void pop_back() {
        if (last == NULL) {
            throw exception();
        }
        blistnode<T>* old = last;
        last = last->prev;
        delete old;
        length--;
    }
    void insert_next(blistnode<T>* prevnode, T n) {
        if (prevnode == last) {
            blistnode<T>* newnode = new blistnode<T>{val : n, next : NULL, prev : prevnode};
            newnode->prev->next = newnode;
            last = newnode;
        } else {
            blistnode<T>* newnode = new blistnode<T>{val : n, next : prevnode->next, prev : prevnode};
            newnode->next->prev = newnode;
            newnode->prev->next = newnode;
        }
        length++;
    }
    void erase(blistnode<T>* delnode) {
        if (length == 1) {
            first = NULL;
            last = NULL;
            delete delnode;
        } else if (delnode == first) {
            first = first->next;
            if (first != NULL) {
                first->prev = NULL;
            }
            delete delnode;
        } else if (delnode == last) {
            last = last->prev;
            if (last != NULL) {
                last->next = NULL;
            }
            delete delnode;
        } else {
            delnode->prev->next = delnode->next;
            delnode->next->prev = delnode->prev;
            delete delnode;
        }
        length--;
    }
    blistnode<T>* begin() {
        return first;
    }
    blistnode<T>* end() {
        return last;
    }
    blistnode<T>* next_node(blistnode<T>* node) {
        return node->next;
    }
    blistnode<T>* prev_node(blistnode<T>* node) {
        return node->prev;
    }
    uint64_t size() {
        return length;
    }
};
using xlist = blist<xstruct>;

// クイックソート xsort
template <class T>
void xsort(bvector<T>* vec, bool asc) {
    if (vec->size() <= 1) {
        return;
    }

    bstack<int64_t> task;
    task.push(0);
    task.push((int64_t)vec->size() - 1);
    while (!task.empty()) {
        int64_t end = task.top();
        task.pop();
        int64_t start = task.top();
        task.pop();

        int64_t left = start;
        int64_t right = end;
        int64_t mid = (left + right) / 2;

        // 基準値を左端・中央・右端のmedianにする
        T ll = vec->at(left);
        T mm = vec->at(mid);
        T rr = vec->at(right);
        if ((ll <= mm && mm <= rr) || (ll >= mm && mm >= rr)) {
            T lll = ll;
            vec->assign(left, mm);
            vec->assign(mid, lll);
        } else if ((ll <= rr && rr <= mm) || (ll >= rr && rr >= mm)) {
            T lll = ll;
            vec->assign(left, rr);
            vec->assign(right, lll);
        }

        uint64_t sameval = 0;
        while (right > left) {
            bool cmp;
            if (vec->at(left) == vec->at(left + 1)) {
                // 基準値と等しい値は左右均等に振り分ける
                cmp = (sameval % 2 == 0);
                sameval++;
            } else if (asc) {
                cmp = (vec->at(left) > vec->at(left + 1));
            } else {
                cmp = (vec->at(left) < vec->at(left + 1));
            }
            if (cmp) {
                // leftとleft+1をswap
                auto t = vec->at(left);
                vec->assign(left, vec->at(left + 1));
                vec->assign(left + 1, t);
                left++;
            } else {
                // left+1とrightをswap
                auto t = vec->at(left + 1);
                vec->assign(left + 1, vec->at(right));
                vec->assign(right, t);
                right--;
            }
        }
        // 0  1  2  3  4  5  6  7
        //    s     lr    e
        if (start + 2 <= right) {
            task.push(start);
            task.push(left - 1);
        }
        if (right + 2 <= end) {
            task.push(right + 1);
            task.push(end);
        }
    }
};

// 二分探索木 xmap, xset
// https://www.slideshare.net/iwiwi/2-12188757
template <class K, class V>
struct bmapnode {
    K key;
    V val;
    bmapnode<K, V>* left;
    bmapnode<K, V>* right;
    uint64_t priority;
    // 今回cnt,sumはサボる
};
template <class K, class V>
class bmap {
   public:
    bmapnode<K, V>* root;
    uint64_t nodenum;

    bmapnode<K, V>* rotate_left(bmapnode<K, V>* node) {
        // 左回転. 上になったノードを返す
        bmapnode<K, V>* right = node->right;
        node->right = right->left;
        right->left = node;
        return right;
    }
    bmapnode<K, V>* rotate_right(bmapnode<K, V>* node) {
        // 右回転. 上になったノードを返す
        bmapnode<K, V>* left = node->left;
        node->left = left->right;
        left->right = node;
        return left;
    }
    bmapnode<K, V>* insert_main(bmapnode<K, V>* node, K key, V value, uint64_t priority) {
        if (node == NULL) {
            nodenum++;
            return new bmapnode<K, V>{key : key, val : value, left : NULL, right : NULL, priority : priority};
        }
        if (key == node->key) {
            // キーがすでに存在する場合、ノードを置き換え
            node->key = key;
            node->val = value;
            node->priority = priority;
            return node;
        } else if (key < node->key) {
            // 再帰的に挿入
            node->left = insert_main(node->left, key, value, priority);
            // 優先度の条件を満たすよう回転する,またはしない. 上になったノードを返す.
            if (node->priority < node->left->priority) {
                return rotate_right(node);
            } else {
                return node;
            }
        } else {
            node->right = insert_main(node->right, key, value, priority);
            if (node->priority < node->right->priority) {
                return rotate_left(node);
            } else {
                return node;
            }
        }
    }
    void erase_main(K key) {
        // parentが必要なためfind_mainが使えない.
        bmapnode<K, V>* node = root;
        bmapnode<K, V>* parent = NULL;
        while (true) {
            if (node == NULL) {
                return;
            } else if (key == node->key) {
                break;
            } else if (key < node->key) {
                parent = node;
                node = node->left;
            } else {
                parent = node;
                node = node->right;
            }
        }

        while (true) {
            // nodeが葉になった.
            if (node->left == NULL && node->right == NULL) {
                if (node == root) {
                    // rootしかないときrootを削除
                    root = NULL;
                    delete node;
                } else if (parent->right == node) {
                    parent->right = NULL;
                    delete node;
                } else if (parent->left == node) {
                    parent->left = NULL;
                    delete node;
                } else {
                    throw exception();
                }
                nodenum--;
                return;
            }

            // nodeが葉に近づくよう回転する.
            // 回転はいくらしてもbinary treeとしての構造は壊れない.
            // 優先度heapが壊れない向きの回転をする.
            // 左の優先度が高いなら右回転, 右の優先度が高いなら左回転.
            if ((node->right == NULL) || (node->left != NULL && node->left->priority > node->right->priority)) {
                if (parent->right == node) {
                    parent->right = rotate_right(node);
                    parent = parent->right;
                } else {
                    parent->left = rotate_right(node);
                    parent = parent->left;
                }
            } else {
                if (parent->right == node) {
                    parent->right = rotate_left(node);
                    parent = parent->right;
                } else {
                    parent->left = rotate_left(node);
                    parent = parent->left;
                }
            }
        }
    }
    bmapnode<K, V>* find_main(K key) {
        bmapnode<K, V>* node = root;
        while (true) {
            if (node == NULL) {
                return NULL;
            } else if (key == node->key) {
                return node;
            } else if (key < node->key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    bmap() {
        root = NULL;
        nodenum = 0;
    }
    ~bmap() {
        //TODO
    }
    void insert(K key, V value) {
        root = insert_main(root, key, value, xhash(key));
    }
    void erase(K key) {
        erase_main(key);
    }
    V at(K key) {
        bmapnode<K, V>* node = find_main(key);
        if (node == NULL) {
            throw exception();
        }
        return node->val;
    }
    uint8_t count(K key) {
        auto node = find_main(key);
        if (node == NULL) {
            return 0;
        } else {
            return 1;
        }
    }
    uint64_t size() {
        return nodenum;
    }
    bmapnode<K, V>* begin() {
        if (root == NULL) {
            return NULL;
        }
        bmapnode<K, V>* node = root;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    bvector<bmapnode<K, V>*>* iterate() {
        bvector<bmapnode<K, V>*>* nodes = new bvector<bmapnode<K, V>*>(nodenum + 2);
        uint64_t i = 0;
        iterate_recursive(root, nodes, i);
        nodes->assign(i, NULL);
        return nodes;
    }
    void iterate_recursive(bmapnode<K, V>* node, bvector<bmapnode<K, V>*>* nodes, uint64_t& i) {
        if (node->left != NULL) {
            iterate_recursive(node->left, nodes, i);
        }
        nodes->array[i] = node;
        i++;
        if (node->right != NULL) {
            iterate_recursive(node->right, nodes, i);
        }
    }
};
using xmapnode = bmapnode<kstruct, xstruct>;
using xmap = bmap<kstruct, xstruct>;

template <class K>
class bset {
   public:
    bmap<K, bool>* m;

    bset() {
        m = new bmap<K, bool>();
    }
    ~bset() {
        delete m;
    }
    uint64_t size() {
        return m->size();
    }
    void insert(K key) {
        m->insert(key, true);
    }
    void erase(K key) {
        m->erase(key);
    }
    uint8_t count(K key) {
        return m->count(key);
    }
    bvector<K>* iterate() {
        bvector<bmapnode<K, bool>*>* nodes = m->iterate();
        bvector<K>* v = new bvector<K>();
        for (uint64_t i = 0; nodes->at(i) != NULL; i++) {
            v->push_back(nodes->at(i)->key);
        }
        return v;
    }
};
using xset = bset<kstruct>;

// ヒープ xpriority_queue
template <class T>
class bpriority_queue {
    // https://ja.wikipedia.org/wiki/%E4%BA%8C%E5%88%86%E3%83%92%E3%83%BC%E3%83%97
    // 1始まりの場合
    // 左の子は2n
    // 右の子は2n+1
    // 親はfloor(n/2)
    // 0 は使わないようにする

   public:
    bvector<T>* heapvec;
    bool large;
    bpriority_queue(bool large_) {
        large = large_;
        heapvec = new bvector<T>(1);
    }
    ~bpriority_queue() {
        delete heapvec;
    }
    void push(T n) {
        heapvec->push_back(n);
        uint64_t index = heapvec->size() - 1;
        while (index > 1) {
            bool swap;
            uint64_t parent_index = index / 2;
            if (large) {
                swap = heapvec->at(index) > heapvec->at(parent_index);
            } else {
                swap = heapvec->at(index) < heapvec->at(parent_index);
            }
            if (swap) {
                auto tmp = heapvec->at(index);
                heapvec->assign(index, heapvec->at(parent_index));
                heapvec->assign(parent_index, tmp);
                index = parent_index;
            } else {
                break;
            }
        }
    }
    T top() {
        if (heapvec->size() <= 1) {
            throw exception();
        }
        return heapvec->at(1);
    }
    void pop() {
        // 最後の要素を1番上にもってくる
        heapvec->assign(1, heapvec->at(heapvec->size() - 1));
        heapvec->length--;

        // ヒープ条件に合うようにswapを繰り返す
        uint64_t last = heapvec->size() - 1;
        uint64_t index = 1;
        while (true) {
            auto elem = heapvec->at(index);
            if (2 * index + 1 <= last) {
                auto left = heapvec->at(2 * index);
                auto right = heapvec->at(2 * index + 1);
                if ((large && left > elem && left >= right) || (!large && left < elem && left <= right)) {
                    heapvec->assign(index, left);
                    heapvec->assign(2 * index, elem);
                    index = 2 * index;
                    continue;
                }
                if ((large && right > elem && right >= left) || (!large && right < elem && right <= left)) {
                    heapvec->assign(index, right);
                    heapvec->assign(2 * index + 1, elem);
                    index = 2 * index + 1;
                    continue;
                }
            } else if (2 * index <= last) {
                auto left = heapvec->at(2 * index);
                if ((large && left > elem) || (!large && left < elem)) {
                    heapvec->assign(index, left);
                    heapvec->assign(2 * index, elem);
                    index = 2 * index;
                    continue;
                }
            }
            break;
        }
    }
    uint64_t size() {
        return (heapvec->size() - 1);
    }
    bool empty() {
        return (size() == 0);
    }
};
using xpriority_queue = bpriority_queue<xstruct>;
using ypriority_queue = bpriority_queue<ystruct>;

// ハッシュテーブル xunordered_map, xunordered_set
const uint8_t HASH_EMPTY = 0;
const uint8_t HASH_EXIST = 1;
const uint8_t HASH_DELETED = 2;
template <class K, class V>
struct bunordered_map_elem {
    uint8_t exist;  // 0:存在しない, 1:存在する, 2:削除後
    K key;
    V value;
};
template <class K, class V>
class bunordered_map {
   public:
    bunordered_map_elem<K, V>* table;
    uint64_t cap;
    uint64_t length;
    bunordered_map() {
        cap = 97;
        table = new bunordered_map_elem<K, V>[cap];
        for (uint64_t i = 0; i < cap; i++) {
            table[i].exist = HASH_EMPTY;
        }
        length = 0;
    }
    bunordered_map(uint64_t init_cap) {
        if (init_cap == 0) {
            throw exception();
        }
        cap = init_cap;
        table = new bunordered_map_elem<K, V>[cap];
        for (uint64_t i = 0; i < cap; i++) {
            table[i].exist = HASH_EMPTY;
        }
        length = 0;
    }
    ~bunordered_map() {
        delete table;
    }
    void insert(K key, V value) {
        uint64_t idx = (xhash(key) % cap);
        while (true) {
            auto elem = table[idx];
            if (elem.exist == HASH_EMPTY || elem.exist == HASH_DELETED) {
                // 新規登録
                table[idx] = bunordered_map_elem<K, V>{exist : HASH_EXIST, key : key, value : value};
                length++;
                if (length >= cap / 2) {
                    rehash();
                }
                break;
            } else if (elem.exist == 1 && elem.key == key) {
                // 上書き
                table[idx] = bunordered_map_elem<K, V>{exist : HASH_EXIST, key : key, value : value};
                break;
            } else {
                idx++;
                if (idx >= cap) {
                    idx = 0;
                }
            }
        }
    }
    void rehash() {
        auto old_table = table;
        auto old_cap = cap;
        table = new bunordered_map_elem<K, V>[cap * 2 + 1];
        cap = cap * 2 + 1;
        length = 0;
        for (uint64_t i = 0; i < old_cap; i++) {
            auto elem = old_table[i];
            if (elem.exist == HASH_EXIST) {
                insert(elem.key, elem.value);  // TODO ハッシュ値をキャッシュしておきたい
            }
        }
        delete old_table;
    }
    bvector<K>* keys() {
        bvector<K>* result = new bvector<K>(length);
        uint64_t j = 0;
        for (uint64_t i = 0; i < cap; i++) {
            auto elem = table[i];
            if (elem.exist == HASH_EXIST) {
                result->assign(j, elem.key);
                j++;
            }
        }
        return result;
    }
    uint64_t get_index(K key) {
        // 見つからなかったときは cap+1 (ありえない値)
        // オープンアドレス法によるハッシュでは、削除後ノードに達したときに探索を打ち切らずに続ける必要がある
        // https://programming-place.net/ppp/contents/algorithm/search/007.html
        uint64_t idx = (xhash(key) % cap);
        while (true) {
            auto elem = table[idx];
            if (elem.exist == HASH_EMPTY) {
                return cap + 1;
            } else if (elem.exist == HASH_EXIST && elem.key == key) {
                return idx;
            } else {
                idx++;
                if (idx >= cap) {
                    idx = 0;
                }
            }
        }
    }
    uint8_t count(K key) {
        if (get_index(key) == cap + 1) {
            return 0;
        } else {
            return 1;
        }
    }
    V at(K key) {
        uint64_t idx = get_index(key);
        if (idx == cap + 1) {
            throw exception();
        }
        return table[idx].value;
    }
    void erase(K key) {
        uint64_t idx = get_index(key);
        if (idx == cap + 1) {
            throw exception();
        }
        table[idx].exist = HASH_DELETED;
        length--;
    }
    uint64_t size() {
        return length;
    }
};
using xunordered_map_elem = bunordered_map_elem<kstruct, xstruct>;
using xunordered_map = bunordered_map<kstruct, xstruct>;

// 二分探索 xlower_bound, xupper_bound
// インデックスを返す
template <class T>
int64_t xlower_bound(bvector<T>* vec, T val) {
    if (vec->size() == 0) {
        throw exception();
    }
    if (vec->at(vec->size() - 1) < val) {
        return -1;
    }
    uint64_t left = 0;
    uint64_t right = vec->size() - 1;
    while (right >= left + 2) {
        uint64_t mid = (right + left) / 2;
        if (vec->at(mid) < val) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (vec->at(left) >= val) {
        return left;
    } else {
        return right;
    }
}

template <class T>
int64_t xupper_bound(bvector<T>* vec, T val) {
    if (vec->size() == 0) {
        throw exception();
    }
    if (vec->at(vec->size() - 1) <= val) {
        return -1;
    }
    uint64_t left = 0;
    uint64_t right = vec->size() - 1;
    while (right >= left + 2) {
        uint64_t mid = (right + left) / 2;
        if (vec->at(mid) <= val) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (vec->at(left) > val) {
        return left;
    } else {
        return right;
    }
}

int main() {
    int64_t N, K;
    cin >> N;
    cin >> K;

    // int input_num = 0;
    // cin >> input_num;
    // string s = "";
    // getline(cin, s);
    // int result = 0;
    // cout << result << endl;
    ypriority_queue* yp = new ypriority_queue(true);
    for (uint64_t i = 0; i < N; i++) {
        int64_t A;
        cin >> A;
        yp->push(ystruct{val : 1.0 * A, init_length : A, split_num : 0});
    }
    for (uint64_t j = 0; j < K; j++) {
        ystruct y = yp->top();
        yp->pop();
        ystruct ynew;
        ynew.split_num = y.split_num + 1;
        ynew.init_length = y.init_length;
        ynew.val = 1.0 * ynew.init_length / (ynew.split_num + 1);
        yp->push(ynew);
    }
    ystruct yy = yp->top();
    if (yy.init_length % (yy.split_num + 1) == 0) {
        cout << (yy.init_length / (yy.split_num + 1)) << endl;
    } else {
        cout << (1 + (yy.init_length / (yy.split_num + 1))) << endl;
    }
}
