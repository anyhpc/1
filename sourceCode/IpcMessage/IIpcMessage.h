#ifndef _IPCMESSAGE_IIPCMESSAGE_H_
#define _IPCMESSAGE_IIPCMESSAGE_H_
#include "IpcMessageType.h"
#include "IpSocketEndpoint.h"
#include <stdint.h>
#include <string>
#include <ostream>

namespace Serialize
{
class WriteBuffer;
class ReadBuffer;
}

namespace IpcMessage {

class IIpcMessage
{
    uint64_t messageId_;
    Network::IpSocketEndpoint source_;
    Network::IpSocketEndpoint destination_;
public:
    IIpcMessage();
    virtual ~IIpcMessage();
    virtual IpcMessageType getMessageType() const = 0;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;

public:
    uint64_t getMessageId() const;
    const Network::IpSocketEndpoint& getSource() const;
    void setSource(const Network::IpSocketEndpoint& source);
    const Network::IpSocketEndpoint& getDestnation() const;
    void setDestnation(const Network::IpSocketEndpoint& destnation);
protected:
    void write(Serialize::WriteBuffer& writeBuffer) const;
    void read(Serialize::ReadBuffer& readBuffer);
    void print(std::ostream& os) const;
};

}

inline std::ostream& operator<< (std::ostream& os, const IpcMessage::IIpcMessage& msg)
{
    msg.operator<< (os);
    return os;
}

#endif // _IPCMESSAGE_IIPCMESSAGE_H_
