/*
 * http.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"packet_m.h"
using namespace omnetpp;
class HttpProtocol: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(HttpProtocol);
void HttpProtocol::initialize() {
}
void HttpProtocol::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    applicationPacket appPacket;
    appPacket.ip = pkt->getAppHeader().ip;
    appPacket.data = pkt->getAppHeader().data;
    appPacket.protocol = pkt->getAppHeader().protocol;
    if (pkt->arrivedOn("httpGate$i", 0)) {
        appPacket.portNo = 80;
        pkt->setAppHeader(appPacket);
        bubble("Set port 80");
        send(pkt, "httpGate$o", 1);
    }
// Self-message for initialization or re-sending scenario

    if (pkt->arrivedOn("httpGate$i", 1)) {
        bubble("http protocol data received: port 80");
        send(pkt, "httpGate$o", 0);
    }
}




