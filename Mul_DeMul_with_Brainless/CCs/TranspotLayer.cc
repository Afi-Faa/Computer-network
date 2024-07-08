/*
 * TranspotLayer.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include<packet_m.h>
using namespace omnetpp;
class TransportLayer: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(TransportLayer);
void TransportLayer::initialize() {
}
void TransportLayer::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    if (pkt->arrivedOn("transGate$i", 0)) {
        send(pkt, "transGate$o", 1);
    } else if (pkt->arrivedOn("phyGate$i", 1))
        send(pkt, "transGate$o", 0);
}





