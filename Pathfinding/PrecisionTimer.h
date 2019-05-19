#include <windows.h>
#include <cassert>


class PrecisionTimer
{

private:

	LONGLONG  m_CurrentTime,
			m_LastTime,
			m_LastTimeInTimeElapsed,
			m_NextTime,
			m_StartTime,
			m_PerfCountFreq;

	double    m_TimeElapsed,
			m_LastTimeElapsed,
			m_TimeScale;

	bool      m_bStarted;

	//if true a call to TimeElapsed() will return 0 if the current
	//time elapsed is much smaller than the previous. Used to counter
	//the problems associated with the user using menus/resizing/moving 
	//a window etc
	bool      m_bSmoothUpdates;

public:

	//ctors
	PrecisionTimer(): m_TimeElapsed(0.0),m_LastTime(0),m_LastTimeInTimeElapsed(0),
		m_PerfCountFreq(0),m_bStarted(false),m_StartTime(0),
		m_LastTimeElapsed(0.0),m_bSmoothUpdates(false)
	{
		//how many ticks per sec do we get
		QueryPerformanceFrequency((LARGE_INTEGER*) &m_PerfCountFreq);
		m_TimeScale = 1.0/m_PerfCountFreq;
	}

	//whatdayaknow, this starts the timer
	void PrecisionTimer::Start()
	{
		m_bStarted = true;

		m_TimeElapsed = 0.0;

		//get the time
		QueryPerformanceCounter( (LARGE_INTEGER*) &m_LastTime);

		//keep a record of when the timer was started
		m_StartTime = m_LastTimeInTimeElapsed = m_LastTime;

		return;
	}
	//determines if enough time has passed to move onto next frame
	inline bool    ReadyForNextFrame();

	//only use this after a call to the above.
	//double  GetTimeElapsed(){return m_TimeElapsed;}

	inline double  TimeElapsed();

	double  CurrentTime()
	{ 
		QueryPerformanceCounter( (LARGE_INTEGER*) &m_CurrentTime);

		return (m_CurrentTime - m_StartTime) * m_TimeScale;
	}

	bool    Started()const{return m_bStarted;}

	void    SmoothUpdatesOn(){m_bSmoothUpdates = true;}
	void    SmoothUpdatesOff(){m_bSmoothUpdates = false;}

};

inline double PrecisionTimer::TimeElapsed()
{
	m_LastTimeElapsed = m_TimeElapsed;

	QueryPerformanceCounter( (LARGE_INTEGER*) &m_CurrentTime);

	m_TimeElapsed = (m_CurrentTime - m_LastTimeInTimeElapsed) * m_TimeScale;

	m_LastTimeInTimeElapsed    = m_CurrentTime;

	const double Smoothness = 5.0;

	if (m_bSmoothUpdates)
	{
		if (m_TimeElapsed < (m_LastTimeElapsed * Smoothness))
		{
			return m_TimeElapsed;
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return m_TimeElapsed;
	}
}

	