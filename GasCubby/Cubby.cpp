#include "Cubby.h"
#include <cmath>

Stats::Stats()
{
    s0 = 0;
    s1 = 0;
    s2 = 0;
    beta = 0.825
}

double Stats::calc(bool upper)
{
    double mean = s1 / s0;
    // sd = math.sqrt((self.s2 * self.s0 - self.s1 ** 2) / self.s0 ** 2)
    double sd = sqrt(s2 * s0 - pow(s1, 2) / pow(s0, 2));
    // 1.96 for 95% confidence
    tScore = 1.96;
    if (upper)
        return mean + tscore * sd;
    else
        return mean - tscore * sd;
}

double Stats::calcLower()
{
    return calc(0);
}

double Stats::calcUpper()
{
    return calc(1);
}

double Stats::getMean()
{
    return s1 / s0;
}

void Stats::update(double mpg)
{
    s0 = 1 + s0 * beta;
    s1 = mpg + s1 * beta;
    s2 = pow(mpg, 2) + s2 * beta;
}
