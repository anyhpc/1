#ifndef _TIMER_LISTTIMERQUEUE_H_
#define _TIMER_LISTTIMERQUEUE_H_
#include "ITimerQueue.h"
#include "Component.h"
#include "Macro.h"
#include <list>

namespace TimerHandler {
class ITimer;

class ListTimerQueue : public ITimerQueue
{
    typedef std::list<ITimer*> TimersList;
    TimersList timersList_;
public:
    ListTimerQueue();
protected:
    ~ListTimerQueue();
    virtual void AddTimer(ITimer*);
    virtual void deleteTimer(uint64_t timerID);
    virtual void executeTimers();
    virtual std::ostream& operator<<(std::ostream& os);

public:
     GETCLASSNAME(ListTimerQueue)
};

}

#endif // _TIMER_LISTTIMERQUEUE_H_