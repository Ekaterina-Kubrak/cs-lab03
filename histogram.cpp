#include "histogram.h"
#include <iostream>
void find_minmax(struct Input data, double& min, double& max)
{
    if(data.numbers.size() !=0)
    {
        min = data.numbers[0];
        max = data.numbers[0];
        for (double number : data.numbers)
        {
            if (number < min)
            {
                min = number;
            }
            if (number > max)
            {
                max = number;
            }
        }
    }
}
