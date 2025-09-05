#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <stdexcept>
#include <vector>

class Random {
  private:
    static std::random_device randomDevice;
    static std::mt19937 mt;

  public:
    Random ();
    Random (int nSeed);

    void seed (int nSeed);

    int genRand ();

    int genRandInt ();
    double genRandFloat ();

    int genRandBetw (int min, int max);
    double genRandBetw (double min, double max);

    int genRandIn (std::vector<int> &lst);
    char genRandIn (std::vector<char> &lst);
    double genRandIn (std::vector<double> &lst);
    template <size_t lstSize> int genRandIn (int (&lst)[lstSize]);
    template <size_t lstSize> char genRandIn (char (&lst)[lstSize]);
    template <size_t lstSize> double genRandIn (double (&lst)[lstSize]);
    template <typename... Args> auto genRandIn (Args &&...args);
};

#endif // RANDOM_HPP