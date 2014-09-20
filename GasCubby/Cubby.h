#ifndef CUBBY_H
#define CUBBY_H

class Stats
{
private:
    double s0;
    double s1;
    double s2;
    double beta;
    double calc();

public:
    Stats();
    void update(double mpg);
    double calcLower();
    double calcUpper();
    double getMean();
};

#endif // CUBBY_H
