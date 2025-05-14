#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

namespace common {
int n, l;
vector<int> t;
void read();
};  // namespace common

void common::read() {
    cin >> n >> l;
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
}

#endif