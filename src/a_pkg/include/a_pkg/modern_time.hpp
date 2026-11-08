#ifndef MODERNTIME_H_
#define MODERNTIME_H_

#include <chrono>
#include <cstdlib>

using namespace std::chrono;
namespace ModernTime
{
    double NowInMs(){
        const auto now = system_clock::now();
        const auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count();
        return (double)ms;
    }
};

#endif