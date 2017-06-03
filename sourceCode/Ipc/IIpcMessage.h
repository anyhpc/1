#ifndef _IPC_IIPCMESSAGE_H_
#define _IPC_IIPCMESSAGE_H_
#include "IpcMessageType.h"
#include <stdint.h>

namespace Serialize
{
class WriteBuffer;
class ReadBuffer;
}

namespace Ipc {

class IIpcMessage
{
    uint64_t messageId_;
public:
    IIpcMessage();
    virtual ~IIpcMessage();
    virtual uint64_t getMessageId() const;
    virtual IpcMessageType getMessageType() const = 0;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
};

}

#endif // _IPC_IIPCMESSAGE_H_
