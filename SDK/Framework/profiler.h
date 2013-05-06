#ifndef __FRAMEWORK_PROFILER_H_INCLUDED__
#	define __FRAMEWORK_PROFILER_H_INCLUDED__

#   ifdef __cplusplus
extern "C"
{
#   endif

enum EventPhase
{
    PROF_EVENT_PHASE_BEGIN,
    PROF_EVENT_PHASE_END,
    PROF_EVENT_PHASE_MARKER,
    PROF_EVENT_PHASE_COUNT
};

struct profiler_event_t
{
    size_t  id;
    size_t  phase;
    __int64	timestamp;
    __int64 threadID;
};

struct profiler_desc_t
{
    const char* name;
};

void profilerBeginDataCapture    ();
void profilerEndDataCapture      ();
int  profilerIsCaptureInProgress ();
void profilerAddCPUEvent         (size_t id, size_t eventPhase);
void profilerGetData             (size_t* numEvents, const profiler_event_t** events);

#   ifdef __cplusplus
}

struct ProfilerCPUAutoTimeslice 
{
    size_t id;

     ProfilerCPUAutoTimeslice(const char* name) { id = (size_t)name; profilerAddCPUEvent( id, PROF_EVENT_PHASE_BEGIN ); }
    ~ProfilerCPUAutoTimeslice()                 { profilerAddCPUEvent( id, PROF_EVENT_PHASE_END ); }
};

#       define PROFILER_CPU_TIMESLICE(name) ProfilerCPUAutoTimeslice __PROFILER_AUTO_TS_VAR_##__LINE__(name)

#   endif

#endif
