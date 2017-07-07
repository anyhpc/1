#ifndef _CLUSTERMANAGEMENT_CLUSTERMGTCLIENTSMANAGEMENT_H_
#define _CLUSTERMANAGEMENT_CLUSTERMGTCLIENTSMANAGEMENT_H_
#include "IClusterMgtClientsManagement.h"
#include "Component.h"
#include "Macro.h"
#include <unordered_map>
#include <string>
#include <memory>

namespace Ipc {
class IIpcServer;
}

namespace ClusterManagement {

class ClusterMgtClientsManagment : public IClusterMgtClientsManagement
{
    using IpcClientsMap = std::unordered_map<std::string, std::shared_ptr<Ipc::IIpcClient> >;
    IpcClientsMap clients_;
    std::shared_ptr<Ipc::IIpcServer> ipcServer_;
public:
    ClusterMgtClientsManagment(std::shared_ptr<Ipc::IIpcServer> ipcServer);
    virtual ~ClusterMgtClientsManagment();
    virtual void startup();
    virtual void shutdown();
    virtual void addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient);
    virtual void removeAcceptedIpcClient(const std::string& remoteEndPoint);
    virtual void handleMessage(const IpcMessage::IIpcMessage& msg);
private:
    void forwardIpcMessage(const std::string& remoteEndPoint, const IpcMessage::IIpcMessage& msg);
    void broadcastMsg(const IpcMessage::IIpcMessage& msg);

public:
    GETCLASSNAME(ClusterMgtClientsManagment)
};

}

#endif // _CLUSTERMANAGEMENT_CLUSTERMGTCLIENTSMANAGEMENT_H_
