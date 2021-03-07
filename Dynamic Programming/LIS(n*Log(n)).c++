#include <bits/stdc++.h>

using namespace std;

void LIS(vector<int> &a);

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        LIS(a);
    }
    return 0;
}
//9                         -> n
// 0 1 2 3  4 5 6 7 8       -> indices of a[]
//-7 1 2 9 -1 3 8 8 6       -> a[]
// 0 0 1 2  0 2 5 5 5       -> parent[]
// 0 4 2 5  8 0 0 0 0       -> seq_indices[]

//-7 -1 2 3 6               -> seq[]
//-7  1 2 3 6               -> lis[]

void LIS(vector<int> &a) {
    vector<int> seq;
    vector<int> seq_indices(a.size(), 0);
    vector<int> parent(a.size(), 0);
    int len = 1;
    seq.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        //if you do not need to have a strictly increasing sequences you can use upper_bound() instead of lower_bound().
        //if you use upper_bound() for {-7,1,2,3,-1,3,8,8,6} the Longest Increasing subsequence will be( 7 -> {-7,1,2,3,3,8,8} ).
        auto it = lower_bound(seq.begin(), seq.end(), a[i]);
        int pos = it - seq.begin();

        parent[i] = seq_indices[pos - 1];   //parents of indices of longest increasing subsequence of array ->a[]
        seq_indices[pos] = i;              //indices of -> seq[]
        if (pos > len)
            len = pos;                      //tracing the index of the last updated element in -> seq_indices[]. you can replace it with (seq.size()-1).
        if (it == seq.end()) {
            //seq[] do no save the Longest increasing subsequence of a[]. it means that seq_indices[]!=parent[].
            //if a[]={-7,1,2,9,-1,3,8,8,6} -> seq[] will equal {-7,-1,2,3,6} but the expected returned value equal {-7,1,2,3,6}.
            seq.push_back(a[i]);        //append if current element (a[i]) is greater than last element in seq.
        } else {
            *it = a[i];              //replace with the element that is greater than or equal to a[i].
        }
    }

    //printing the solution.
    vector<int> lis(seq.size(), 0);
    printf("%d\n-\n", len + 1);
    int idx = seq_indices[len];
    for (int i = len; i >= 0; --i) {
        lis[i] = a[idx];
        idx = parent[idx];
    }

    for (auto it:lis)cout << it << "\t";
    puts("");
}
