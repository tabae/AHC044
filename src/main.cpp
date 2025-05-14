#include <iostream>

#include "annealer.hpp"
#include "common.hpp"
#include "state.hpp"
using namespace std;
using namespace common;

extern Timer toki;

int main() {
    toki.init();
    read();

    IterationControl<State> sera;
    State stat = sera.anneal(1.8, 1e6, 0.1, State::initState());
    stat.print();
    cerr << "my score = " << stat.score << endl;
    cerr << "elapsed time = " << toki.elapsed() << endl;
}
