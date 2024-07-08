/*
 * DatalinkLayer.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "packet_m.h"

using namespace omnetpp;

class DataLinkLayer : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(DataLinkLayer);

void DataLinkLayer::initialize() {
    // Initialization code here
}

void DataLinkLayer::handleMessage(cMessage *msg) {
    const char *dllH = "DLL Header MAC Address EC-F4-BB-7B-57-51";
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    pkt->setDllHeader(dllH);
    if (pkt->arrivedOn("dllGate$i", 0)) {
        send(pkt, "dllGate$o", 1);
    } else if (pkt->arrivedOn("dllGate$i", 1)) {
        send(pkt, "dllGate$o", 0);
    }
}



