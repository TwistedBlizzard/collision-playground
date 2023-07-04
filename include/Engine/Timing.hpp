#ifndef TIMING_H
#define TIMING_H

// Standard Library

#include <memory>
using std::shared_ptr;

#include <chrono>
using hrc = std::chrono::high_resolution_clock;

// SDL

#include "SDL3/SDL.h"

class Timing
{
public:
    Timing();
    ~Timing();

    /*******\
    * Setup *
    \*******/

    void Init();

    /********\
    * Update *
    \********/

    void Update();

    /********\
    * Timing *
    \********/

    float DeltaTime();

private:
    bool m_initialised;

    float m_deltaTime;

    hrc::time_point m_frameA;
    hrc::time_point m_frameB;
};

typedef shared_ptr<Timing> TimingPtr;

#endif