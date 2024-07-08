#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "packet_m.h"

using namespace omnetpp;

class MuxDemuxModule : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(MuxDemuxModule);

void MuxDemuxModule::initialize() {
    // Initialization code here
}

void MuxDemuxModule::handleMessage(cMessage *msg) {
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    if (pkt->arrivedOn("muxDemuxGate$i", 2)) {
        if (pkt->getTcpHeader() == 6) {
            bubble("Packet Deliver through TCP");
            send(pkt, "muxDemuxGate$o", 0);
        }
        if (pkt->getTcpHeader() == 13) {
            bubble("Packet Deliver through UDP");
            send(pkt, "muxDemuxGate$o", 1);
        }
    }
    if (pkt->arrivedOn("muxDemuxGate$i", 1) ||
        pkt->arrivedOn("muxDemuxGate$i", 0)) {
        send(pkt, "muxDemuxGate$o", 2);
    }
}
