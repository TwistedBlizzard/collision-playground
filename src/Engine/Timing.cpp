#include "Engine/Timing.hpp"

using std::chrono::duration;

Timing::Timing() :
m_initialised(false),
m_deltaTime(0.0f)
{}

Timing::~Timing()
{}

void Timing::Init()
{
    if (m_initialised)
        return;

    m_frameA = hrc::now();
    m_frameB = m_frameA;

    m_initialised = true;
}

void Timing::Update()
{
    if (!m_initialised)
        return;

    m_frameA = m_frameB;
    m_frameB = hrc::now();

    hrc::duration deltaTime = m_frameB - m_frameA;
    m_deltaTime = duration<float>(deltaTime).count();
}

float Timing::DeltaTime()
{
    if (!m_initialised)
        return 0.0f;

    return m_deltaTime;
}