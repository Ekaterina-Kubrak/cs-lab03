#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
#include <string>
#include <sstream>
#include <cstdio>
#include <windows.h>
using namespace std;

vector<double>input_numbers(size_t count)
{
    vector<double>result(count);
    for(size_t i=0; i<count; i++)
    {
        cin >> result[i];
    }
    return result;
}

string make_info_text()
{
    stringstream buffer;
    DWORD WINAPI info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    printf("Version is %x\n", version);
    printf("Version is %u\n", version);
    DWORD platform = info >> 16;
    printf("Platform is %u\n", platform);
    DWORD version_minor = version >> 8;
    printf("Version minor is %u\n", version_minor);
    DWORD mask1 = 0xff;
    DWORD version_major = version & mask1;
    printf("Version major is %u\n", version_major);
    return buffer.str();
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count, double min, double max)
{
    vector<size_t> bins(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return (bins);
}

void show_histogram_text(vector<size_t>bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    double scaling_factor = 1;
    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";
        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }
        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}

int main()
{
    make_info_text();
    return 0;
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // Обработка данных

     double min, max;
     find_minmax(numbers, min, max);

     const auto bins = make_histogram(numbers, bin_count, min, max);

    // Вывод данных

    show_histogram_svg(bins);

    return 0;
}
