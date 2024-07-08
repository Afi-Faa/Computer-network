/*
 * ftp.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"packet_m.h"
using namespace omnetpp;
class FtpProtocol: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(FtpProtocol);
void FtpProtocol::initialize() {
}
void FtpProtocol::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    applicationPacket appPacket;
    appPacket.ip = pkt->getAppHeader().ip;
    appPacket.data = pkt->getAppHeader().data;
    appPacket.protocol = pkt->getAppHeader().protocol;
    if (pkt->arrivedOn("ftpGate$i", 0)) {
        appPacket.portNo = 90;
        pkt->setAppHeader(appPacket);
        bubble("Set port 90");
        send(pkt, "ftpGate$o", 1);
    }
    if (pkt->arrivedOn("ftpGate$i", 1)) {
        bubble("ftp protocol data received: port 90");
        send(pkt, "ftpGate$o", 0);
    }
}



