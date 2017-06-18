#ifndef _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
#define _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
#include <memory>

namespace Serialize {
class WriteBuffer;
}

namespace IpcMessage {
class IIpcMessage;
class IIpcMessageFactory;
}

namespace Ipc {

class IIpcConnectionReceiver;
class IIpcConnectionClientStrategy
{
public:
    IIpcConnectionClientStrategy();
    virtual ~IIpcConnectionClientStrategy();
    virtual void connect() = 0;
    virtual void send(const IpcMessage::IIpcMessage& msg) = 0;
    virtual void disconnect() = 0;
    virtual void setIpcConnectionReceiver(std::shared_ptr<IIpcConnectionReceiver> receiver) = 0;
    virtual void setIpcMessageFactory(std::shared_ptr<IpcMessage::IIpcMessageFactory> factory) = 0;
};

}

#endif // _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
