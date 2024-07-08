#ifndef USERAPPLICATIONLAYER_H_
#define USERAPPLICATIONLAYER_H_

#include <omnetpp.h>
#include "packet_m.h"

using namespace omnetpp;

class UserApplicationLayer : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual TcpIpPacket* generateNextMessage();
};

Define_Module(UserApplicationLayer);

#endif /* USERAPPLICATIONLAYER_H_ */
