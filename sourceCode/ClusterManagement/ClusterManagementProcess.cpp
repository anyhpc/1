#include "ClusterManagementProcess.h"
#include "ClusterMgtClientsManagement.h"
#include "ClusterMgtConnectionAcceptor.h"
#include "ClusterMgtController.h"
#include "IpcConnectionTcpServerStrategy.h"
#include "IpcServer.h"
#include "TcpServer.h"
#include "IpSocketEndpoint.h"
#include "LoopMain.h"
namespace ClusterManagement {
ClusterManagementProcess::ClusterManagementProcess()
{

}

void ClusterManagementProcess::process()
{
    // create the Cluster mananger control
    std::shared_ptr<IClusterMgtController> clusterMgtController(new ClusterMgtController());

    // create the Ipc server, will set the tcp acceptor later
    Network::IpSocketEndpoint localEndPoint("127.0.0.1:7000");
    Network::TcpServer* tcpServerPtr = new Network::TcpServer(localEndPoint);
    std::shared_ptr<Network::ITcpServer> tcpServer(tcpServerPtr);

    // create the Tcp server strategy,  this is the Tcp acceptor also
    Ipc::IpcConnectionTcpServerStrategy* strategyPtr = new Ipc::IpcConnectionTcpServerStrategy(tcpServer);
    std::shared_ptr<Ipc::IpcConnectionTcpServerStrategy> strategy(strategyPtr);

    // set the Tcp acceptor
    tcpServer->setConnectionAcceptor(strategy);

    // create the Ipc server, will set the ipc acceptor later
    Ipc::IIpcServer* ipcServerPtr = new Ipc::IpcServer(strategy);
    std::shared_ptr<Ipc::IIpcServer> ipcServer(ipcServerPtr);

    // create ipc acceptor
    ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(NodeType, clusterMgtController);
    std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);
    // set the ipc acceptor
    strategyPtr->setIpcConnectionAcceptor(acceptor);

    // add the client manger to the  mananger control
    std::shared_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment(ipcServer));
    clusterMgtController->addClientManager(NodeType, clientsManager);


    std::unique_ptr<Core::LoopMain> loopMain(new Core::LoopMain());

    loopMain->registerIo(Io::IoFdType::IoFdRead, tcpServerPtr);

    clusterMgtController->startup();
    // run
    loopMain->loop();

}


}
