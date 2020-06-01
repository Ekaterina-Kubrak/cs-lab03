#include<iostream>
#include "svg.h"

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<<baseline<<"'>"<<text<<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>'";
}

void show_histogram_svg(const vector<size_t>& bins, const size_t sred)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    double top = 0;
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count * BLOCK_WIDTH > MAX_ASTERISK;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    for (size_t bin : bins)
    {
        size_t height = bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / (max_count * BLOCK_WIDTH);
            height = (size_t)(bin * scaling_factor);
        }
        const double bin_width = BLOCK_WIDTH * height;
        if(bin > sred)
        {
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "red");
        }
        else
        {
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "green", "green");
        }
        top += BIN_HEIGHT;
    }
    svg_end();
}
