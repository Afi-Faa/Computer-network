/*
 * PhysicalLayer.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include<packet_m.h>
using namespace omnetpp;
class PhysicalLayer: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(PhysicalLayer);
void PhysicalLayer::initialize() {
}
void PhysicalLayer::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    if (pkt->arrivedOn("phyGate$i", 0)) {
        send(pkt, "phyGate$o", 1);
    } else if (pkt->arrivedOn("phyGate$i", 1))
        send(pkt, "phyGate$o", 0);
}



