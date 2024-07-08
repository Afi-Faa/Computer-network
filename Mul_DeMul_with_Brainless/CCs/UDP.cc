/*
 * UDP.cc
 *
 *  Created on: Mar 19, 2024
 *      Author: afifa
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"packet_m.h"
#include<vector>
using namespace omnetpp;
class Udp: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Udp);
void Udp::initialize() {
}
void Udp::handleMessage(cMessage *msg) {
    int transH = 13;
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    /* Condition is applied when message received on input port of
     UDP connected to Transport layer */
    if (pkt->arrivedOn("udpGate$i", 0)) {

//Addition of UDP header
        pkt->setTcpHeader(transH);
        bubble(" UDP header added ");

        /* To send packet on output port of UDP connected to Transport
         layer */
        send(pkt, "udpGate$o", 1);
    }

    /* Condition is applied when message received on input port of
     UDP connected to Mux_Demux module */
    if (pkt->arrivedOn("udpGate$i", 1)) {

//Check Port No for TFTP

        if (pkt->getAppHeader().portNo == 100) {

//Remove TCP Header

            pkt->setTcpHeader(0);
            bubble(" Read Port 100 Send to TFTP");
            send(pkt, "udpGate$o", 0);
        }
    }
}





