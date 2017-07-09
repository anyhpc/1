#include "ClusterMgtConnectionReceiver.h"
#include "IClusterMgtController.h"
#include "IIpcMessage.h"
#include "Trace.h"

namespace ClusterManagement {
ClusterMgtConnectionReceiver::ClusterMgtConnectionReceiver(ClientType type,
                                                           std::shared_ptr<IClusterMgtController> clusterMgtController,
                                                           const std::string& remoteIpEndpoint)
    : clientType_(type)
    , clusterMgtController_(clusterMgtController)
    , remoteIpEndpoint_(remoteIpEndpoint)
{
}

ClusterMgtConnectionReceiver::~ClusterMgtConnectionReceiver()
{

}

void ClusterMgtConnectionReceiver::onConnect()
{
    TRACE_NOTICE("client connected!");
}

void ClusterMgtConnectionReceiver::onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    TRACE_NOTICE("receive message:" << *msg);
    clusterMgtController_->handleMessage(*msg, clientType_);
}

void ClusterMgtConnectionReceiver::onDisconnect()
{
    TRACE_NOTICE("client " << remoteIpEndpoint_ << "disconnected!");
    clusterMgtController_->removeAcceptedIpcClient(remoteIpEndpoint_, clientType_);
}

}
