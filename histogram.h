#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(struct Input data, double& min, double& max);

#endif // HISTOGRAM_H_INCLUDED
