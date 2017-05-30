#include "IoControlEvent.h"
#include "SocketWrapper.h"
#include "EventIdGenerator.h"
#include "Generic.h"
#include <string>
#include "Trace.h"

namespace Io {

IoControlEvent::IoControlEvent()
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
{
    Network::FdZero(&readFds_);
    Network::FdZero(&writeFds_);
    Network::FdZero(&exceptFds_);
}

IoControlEvent::~IoControlEvent()
{
    Network::FdZero(&readFds_);
    Network::FdZero(&writeFds_);
    Network::FdZero(&exceptFds_);
}

void IoControlEvent::registerIoFd(int fd, IoFdType type, EventHandler::IEvent* event)
{
    TRACE_NOTICE("fd = " << fd << ", type = " << type << ", event = " << event);

    if (type & IoFdType::IoFdRead)
    {
        Network::FdSet(fd, &readFds_);
    }
    else if(type & IoFdType::IoFdWrite)
    {
        Network::FdSet(fd, &writeFds_);
    }
    else if (type & IoFdType::IoFdExcept)
    {
        Network::FdSet(fd, &exceptFds_);
    }
    else
    {
        throw std::invalid_argument(std::string("Invalid fd type: ") + lexical_cast<std::string>(static_cast<uint32_t>(type)));
    }

    fdEventMap_[fd] = IoFdEvent(type, event);
}

void IoControlEvent::unRegisterIoFd(int fd)
{
    TRACE_NOTICE("fd = " << fd);

    IoFdEventMap::iterator it = fdEventMap_.find(fd);
    if (it != fdEventMap_.end())
    {
        const IoFdEvent& event = it->second;
        fdEventMap_.erase(it);

        if (event.fdType & IoFdType::IoFdRead)
        {
            Network::FdClear(fd, &readFds_);
        }
        else if(event.fdType & IoFdType::IoFdWrite)
        {
            Network::FdClear(fd, &writeFds_);
        }
        else if (event.fdType & IoFdType::IoFdExcept)
        {
            Network::FdClear(fd, &exceptFds_);
        }
        else
        {
            return;
        }
    }
}

uint64_t IoControlEvent::getEventId() const
{
    return eventId_;
}

void IoControlEvent::run(EventHandler::EventFlag flag)
{
    TRACE_DEBUG("flag = " << flag);
    Network::Select(readFds_, writeFds_, exceptFds_);
}

std::ostream& IoControlEvent::operator<< (std::ostream& os) const
{

}

}