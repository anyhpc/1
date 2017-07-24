#include "ClusterMgtClientsManagement.h"
#include "ClusterMgtBrieflyRequest.h"
#include "ClusterMgtBrieflyResponse.h"
#include "IIpcClient.h"
#include "IIpcServer.h"
#include "IIpcMessage.h"
#include "IpcMessageType.h"
#include "Trace.h"

namespace ClusterManagement {

ClusterMgtClientsManagment::ClusterMgtClientsManagment(ClientType clientType, std::shared_ptr<Ipc::IIpcServer> ipcServer)
    : clientType_(clientType)
    , ipcServer_(ipcServer)
{

}

ClusterMgtClientsManagment::~ClusterMgtClientsManagment()
{

}

void ClusterMgtClientsManagment::startup()
{
    TRACE_ENTER();
    ipcServer_->startup();
}

void ClusterMgtClientsManagment::shutdown()
{
    TRACE_ENTER();
    ipcServer_->shutdown();
}

void ClusterMgtClientsManagment::addAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient)
{
    TRACE_DEBUG("Add client:" << remoteEndPoint);
    IpcClientsMap::iterator it= clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already exist!");
    }

    clients_[remoteEndPoint] = ipcClient;
}

void ClusterMgtClientsManagment::removeAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint)
{
    TRACE_DEBUG("remove client:" << remoteEndPoint);
    IpcClientsMap::iterator it = clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        clients_.erase(it);
    }
    else
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already been removed!");
    }
}

void ClusterMgtClientsManagment::handleMessage(const IpcMessage::IIpcMessage& msg, ClientType fromClientType, const Network::IpSocketEndpoint& remoteIpEndpoint)
{
    IpcMessage::IpcMessageType type = msg.getMessageType();
    if (type == IpcMessage::IpcMessageType::IpcMessage_ClusterMgt)
    {
        if (fromClientType != clientType_)
        {
            return;
        }

        handleClusterMgtMessage(msg, remoteIpEndpoint);
    }
    else
    {
        if (fromClientType == clientType_)
        {
            return;
        }
        const std::string invalidDest("Invalid_IpAddress:0");
        const std::string dest = msg.getDestnation().toString();
        TRACE_DEBUG("destination:" << dest);
        if (dest == invalidDest)
        {
            broadcastMsg(msg);
        }
        else
        {
            IpcClientsMap::iterator it = clients_.find(dest);
            forwardIpcMessage(dest, msg);
        }
    }
}

void ClusterMgtClientsManagment::forwardIpcMessage(const Network::IpSocketEndpoint& remoteEndPoint, const IpcMessage::IIpcMessage& msg)
{
    TRACE_DEBUG("Forward msg to:" << remoteEndPoint << ", msg = " << msg);
    IpcClientsMap::iterator it = clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        std::shared_ptr<Ipc::IIpcClient>& ipcClient = it->second;
        ipcClient->send(msg);
    }
}

void ClusterMgtClientsManagment::broadcastMsg(const IpcMessage::IIpcMessage& msg)
{
    TRACE_DEBUG("broad cast message to all client");
    for (IpcClientsMap::iterator it= clients_.begin(); it != clients_.end(); ++it)
    {
        std::shared_ptr<Ipc::IIpcClient>& ipcClient = it->second;
        ipcClient->send(msg);
    }
}

void ClusterMgtClientsManagment::handleClusterMgtMessage(const IpcMessage::IIpcMessage& msg, const Network::IpSocketEndpoint& remoteIpEndpoint)
{
    const ClusterMgtMessage::ClusterMgtBrieflyRequest* request = dynamic_cast<const ClusterMgtMessage::ClusterMgtBrieflyRequest*>(&msg);
    if (request != nullptr)
    {
        ClusterMgtMessage::ClusterMgtBrieflyResponse response;
        Environment::SystemInfoBriefly info;
        info.update();
        response.setSystemInfoBriefly(info);
        IpcClientsMap::iterator it = clients_.find(remoteIpEndpoint);
        if (it != clients_.end())
        {
            std::shared_ptr<Ipc::IIpcClient>& ipcClient = it->second;
            ipcClient->send(response);
        }
    }
}

}
