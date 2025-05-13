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
    State stat = sera.climb(1.8, State::initState());

    cerr << "my score = " << stat.score << endl;
    cerr << "elapsed time = " << toki.elapsed() << endl;
}
