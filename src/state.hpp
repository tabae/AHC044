#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <algorithm>
#include <cassert>
#include <numeric>

#include "common.hpp"
#include "ryuka.hpp"

using namespace std;
using namespace common;

extern RandGenerator ryuka;

struct State {
    static constexpr long long inf = 1LL << 60;
    long long score;
    vector<int> a, b;
    State() : score(-inf) { 
        a.resize(n); 
        b.resize(n);
    };
    long long calc_score();
    void print();
    void rollback();
    void nextState();
    static State initState();
    static State generateState(const State& input_state);
};

long long State::calc_score() {
    vector<bool> reachable(n, false);
    auto dfs = [&](auto dfs, int v) -> void {
        reachable[v] = true;
        if(!reachable[a[v]]) dfs(dfs, a[v]);
        if(!reachable[b[v]]) dfs(dfs, b[v]);
    };
    dfs(dfs, 0);
    vector<int> in_degrees(n, 0);
    for(int i = 0; i < n; i++) {
        in_degrees[a[i]]++;
        in_degrees[b[i]]++;
    }
    long long diff = 0;
    for(int i = 0; i < n; i++) {
        if(reachable[i]) {
            diff += abs(2 * n * t[i] - in_degrees[i] * l);
        } else {
            diff += abs(2 * n * t[i]);
        }
    }
    score = 1000000 - diff / (2 * n);
    return score;
}

void State::print() {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " " << b[i] << endl;
    }
}

State State::initState() {
    State res;
    for(int i = 0; i < n; ++i) {
        res.a[i] = (i+1) % n;
        res.b[i] = (i+1) % n;
    }
    res.calc_score();
    return res;
}

State State::generateState(const State& input_state) {
    State res = input_state;
    int i = ryuka.rand(n);
    int a_or_b = ryuka.rand(2);
    if (a_or_b == 0) {
        res.a[i] = ryuka.rand(n);
    } else {
        res.b[i] = ryuka.rand(n);
    }
    res.calc_score();
    return res;
}

void State::nextState() {
    // do something
}

void State::rollback() {
    // do something
}

#endif
