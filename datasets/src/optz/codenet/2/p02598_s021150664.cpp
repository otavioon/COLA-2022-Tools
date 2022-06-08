#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int64_t N, K;
    cin >> N;
    cin >> K;

    int64_t total_length = 0;
    priority_queue<ystruct> yp;
    vector<int64_t> avec;
    for (uint64_t i = 0; i < N; i++) {
        int64_t A;
        cin >> A;
        yp.push(ystruct{val : 1.0 * A, init_length : A, split_num : 0});
        avec.push_back(A);
        total_length += A;
    }

    // 適当な初期値を与えて上界とする
    double upper_bound = -1;
    for (auto a : avec) {
        int64_t split_num_heuristic = (K * a) / total_length;
        upper_bound = max(upper_bound, 1.0 * a / (split_num_heuristic + 1));
    }
    int64_t j = 0;
    while (j < K) {
        ystruct y = yp.top();
        yp.pop();

        //int64_t split_num_min = (y.init_length / upper_bound) - 1L;
        int64_t split_num_min;
        if (upper_bound == 0) {
            split_num_min = 0;
        } else {
            split_num_min = (y.init_length / upper_bound) - 1L;
        }

        if (y.split_num < split_num_min) {
            y.split_num = split_num_min;
            y.val = 1.0 * y.init_length / (y.split_num + 1);
            j += split_num_min;
            yp.push(y);
        } else {
            y.split_num = y.split_num + 1;
            y.val = 1.0 * y.init_length / (y.split_num + 1);
            j++;
            yp.push(y);
        }
    }
    ystruct yy = yp.top();
    if (yy.init_length % (yy.split_num + 1) == 0) {
        cout << (yy.init_length / (yy.split_num + 1)) << endl;
    } else {
        cout << (1 + yy.init_length / (yy.split_num + 1)) << endl;
    }
}
