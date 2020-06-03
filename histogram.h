#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
#include <curl/curl.h>
using namespace std;

struct myprogress
{
  double lastruntime;
  CURL *curl;
};

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(struct Input data, double& min, double& max);

#endif // HISTOGRAM_H_INCLUDED
