/*
 * tftp.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"packet_m.h"
using namespace omnetpp;
class TftpProtocol: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(TftpProtocol);
void TftpProtocol::initialize() {
}
void TftpProtocol::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    applicationPacket appPacket;
    appPacket.ip = pkt->getAppHeader().ip;
    appPacket.data = pkt->getAppHeader().data;
    appPacket.protocol = pkt->getAppHeader().protocol;
    if (pkt->arrivedOn("tftpGate$i", 0)) {
        appPacket.portNo = 100;
        pkt->setAppHeader(appPacket);
        bubble("Set port 100");
        send(pkt, "tftpGate$o", 1);
    }

    /* Self-message(for initialization or to resends packet
     scenario) */

    if (pkt->arrivedOn("tftpGate$i", 1)) {
        bubble("TFTP protocol data received: port 100");
        send(pkt, "tftpGate$o", 0);
    }
}





