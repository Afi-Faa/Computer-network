/*
 * TCP.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include<packet_m.h>
#include<vector>
using namespace omnetpp;
class Tcp: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Tcp);
void Tcp::initialize() {
}
void Tcp::handleMessage(cMessage *msg) {
    int transH = 6;
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    if (pkt->arrivedOn("tcpGate$i", 0) || pkt->arrivedOn("tcpGate$i", 1)) {
        pkt->setTcpHeader(transH);
        bubble(" TCP header added ");
        send(pkt, "tcpGate$o", 2);
    }
    if (pkt->arrivedOn("tcpGate$i", 2)) {
        if (pkt->getAppHeader().portNo == 80) {
            pkt->setTcpHeader(0);
            bubble(" Read Port 80: Send to HTTP");
            send(pkt, "tcpGate$o", 0);
        }
        if (pkt->getAppHeader().portNo == 90) {
            pkt->setTcpHeader(0);
            bubble(" Read Port 90: Send to FTP");
            send(pkt, "tcpGate$o", 1);
        }
    }
}




