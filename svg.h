#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <vector>
using namespace std;
size_t sred_dlinna(size_t n_count, size_t b_count);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void show_histogram_svg(const vector<size_t>& bins, const size_t sred);

#endif // SVG_H_INCLUDED
