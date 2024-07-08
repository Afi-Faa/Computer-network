/*
 * NetworkLayer.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "packet_m.h"
#include <vector>

using namespace omnetpp;

class NetworkLayer : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(NetworkLayer);

void NetworkLayer::initialize() {
    // Initialization code here
}

void NetworkLayer::handleMessage(cMessage *msg) {
    const char *ipH = "IP Header Address 192.26.7.40";
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    pkt->setIpHeader(ipH);
    if (pkt->arrivedOn("ipGate$i", 0)) {
        send(pkt, "ipGate$o", 1);
    }
    if (pkt->arrivedOn("ipGate$i", 1)) {
        send(pkt, "ipGate$o", 0);
    }
}



