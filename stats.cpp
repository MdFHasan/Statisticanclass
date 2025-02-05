#include <iostream> 
#include <cassert>  // Provides assert
#include "stats.h"  // Provides the statistician class definition
using namespace std;
namespace main_savitch_2C
{
    statistician::statistician()
    {
        count = 0;
        total = 0;
    }

    void statistician::next(double r)
    {
        if (count == 0) {
            count = 1;
            total = r;
            tinyest = r;
            largest = r;
        }
        else {
            count++;
            total += r;
            if (r < tinyest) tinyest = r;
            if (r > largest) largest = r;
        }
    }

    void statistician::reset()
    {
        count = 0;
        total = 0;
    }

    string statistician::hello() const
    {
        return "Hello World!";
    }


    int statistician::length() const
    {
        return count;
    }

    double statistician::sum() const
    {
        return total;
    }

    double statistician::mean() const
    {
        assert(length() > 0);
        return total/count;
    }

    double statistician::minimum() const
    {
        assert(length() > 0);
        return tinyest;
    }

    double statistician::maximum() const
    {
        assert(length() > 0);
        return largest;
    }

    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician result;

        if (s1.length() == 0 && s2.length() == 0)
            return result;
        
        if (s1.length() == 0)
            return s2;
            
        if (s2.length() == 0)
            return s1;

        result.count = s1.count + s2.count;
        result.total = s1.total + s2.total;
        result.tinyest = (s1.tinyest < s2.tinyest) ? s1.tinyest : s2.tinyest;
        result.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;

        return result;
    }

    statistician operator *(double scale, const statistician& s)
    {
        statistician result;

        if (s.length() == 0)
            return result;

        result.count = s.count;
        result.total = s.total * scale;
        
        if (scale >= 0) {
            result.tinyest = s.tinyest * scale;
            result.largest = s.largest * scale;
        }
        else {
            result.tinyest = s.largest * scale;
            result.largest = s.tinyest * scale;
        }

        return result; 
    }

    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if (s1.length() == 0 && s2.length() == 0)
            return true;

        if (s1.length() == 0 || s2.length() == 0)
            return false;

        return (s1.length() == s2.length() &&
                s1.sum() == s2.sum() &&
                s1.minimum() == s2.minimum() &&
                s1.maximum() == s2.maximum() &&
                s1.mean() == s2.mean());
    }
}
