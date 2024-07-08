/*
 * UserApplicationLayer.cc
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "UserApplicationLayer.h"

using namespace omnetpp;

void UserApplicationLayer::initialize() {
    // To send the first message from PC1
    if (strcmp(par("userID").stringValue(), "PC1") == 0) {
        scheduleAt(0.0, generateNextMessage());
    }
}

void UserApplicationLayer::handleMessage(cMessage *msg) {
    TcpIpPacket* pkt = check_and_cast<TcpIpPacket *>(msg);
    if (pkt->arrivedOn("appGate$i", 0) ||
        pkt->arrivedOn("appGate$i", 1) ||
        pkt->arrivedOn("appGate$i", 2)) {
        if (pkt->getAppHeader().protocol == 1)
            bubble("data of HTTP protocol received");
        else if (pkt->getAppHeader().protocol == 2)
            bubble("data of FTP protocol received");
        else if (pkt->getAppHeader().protocol == 3)
            bubble("data of TFTP protocol received");
        delete pkt;
    }

    // Self-message (for initialization or resending packet)
    if (msg->isSelfMessage()) {
        if (pkt->getAppHeader().protocol == 1)
            send(pkt, "appGate$o", 0);
        else if (pkt->getAppHeader().protocol == 2)
            send(pkt, "appGate$o", 1);
        else if (pkt->getAppHeader().protocol == 3)
            send(pkt, "appGate$o", 2);
        scheduleAt(simTime() + 0.1, generateNextMessage());
    }
}

TcpIpPacket* UserApplicationLayer::generateNextMessage() {
    char packetInfo[200];
    int message = intuniform(6, 9);
    int protocol = intuniform(0, 4);
    applicationPacket appHdr;
    appHdr.data = message;
    appHdr.ip = 192168641;
    appHdr.protocol = protocol;
    sprintf(packetInfo, "Data:%d", message);
    TcpIpPacket* nextPkt = new TcpIpPacket(packetInfo);
    nextPkt->setAppHeader(appHdr);
    return nextPkt;
}
