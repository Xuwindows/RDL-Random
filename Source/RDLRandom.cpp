#include "RDLRandom.hpp"

using namespace std;

std::random_device Random::randomDevice;
std::mt19937 Random::mt;

template <typename T, typename... Args>
inline auto genRandInList (int step, int breakIndex, T first, Args &&...args) {
    if (step == breakIndex) {
        return first;
    } else {
        return genRandInList (step + 1, breakIndex, args...);
    }
}

template <typename T, typename... Args>
inline auto genRandInList (int step, int breakIndex, T first) {
    return first;
}

Random::Random () { mt.seed (randomDevice ()); }
Random::Random (int nSeed) { mt.seed (nSeed); }

void Random::seed (int nSeed) { mt.seed (nSeed); }

int Random::genRand () {
    uniform_int_distribution<int> dist (0, 1);
    return dist (mt);
}
int Random::genRandInt () {
    uniform_int_distribution<int> dist (INT_MIN, INT_MAX);
    return dist (mt);
}
double Random::genRandFloat () {
    uniform_real_distribution<double> dist (0, 1);
    return dist (mt);
}

int Random::genRandBetw (int min, int max) {
    uniform_int_distribution<int> dist (min, max);
    return dist (mt);
}
double Random::genRandBetw (double min, double max) {
    uniform_real_distribution<double> dist (min, max);
    return dist (mt);
}

int Random::genRandIn (vector<int> &lst) {
    if (lst.empty ()) {
        return 0;
    }
    uniform_int_distribution<int> dist (0, lst.size () - 1);
    return lst[dist (mt)];
}
char Random::genRandIn (vector<char> &lst) {
    if (lst.empty ()) {
        return 32;
    }
    uniform_int_distribution<int> dist (0, lst.size () - 1);
    return lst[dist (mt)];
}
double Random::genRandIn (vector<double> &lst) {
    if (lst.empty ()) {
        return 0.0;
    }
    uniform_int_distribution<int> dist (0, lst.size () - 1);
    return lst[dist (mt)];
}
template <size_t lstSize> int Random::genRandIn (int (&lst)[lstSize]) {
    if (lstSize == 0) {
        return 0;
    }
    uniform_int_distribution<int> dist (0, static_cast<int> (lstSize - 1));
    return lst[dist (mt)];
}

template <size_t lstSize> char Random::genRandIn (char (&lst)[lstSize]) {
    if (lstSize == 0) {
        return 32;
    }
    uniform_int_distribution<int> dist (0, static_cast<int> (lstSize - 1));
    return lst[dist (mt)];
}

template <size_t lstSize> double Random::genRandIn (double (&lst)[lstSize]) {
    if (lstSize == 0) {
        return 0.0;
    }
    uniform_int_distribution<int> dist (0, static_cast<int> (lstSize - 1));
    return lst[dist (mt)];
}
template <typename... Args> auto Random::genRandIn (Args &&...args) {
    int maxIndex = sizeof...(args) - 1;

    if (maxIndex <= -1) {
        throw invalid_argument ("genRandIn called with no arguments");
    }

    int index = genRandBetw (0, maxIndex);
    return genRandInList (0, index, args...);
}