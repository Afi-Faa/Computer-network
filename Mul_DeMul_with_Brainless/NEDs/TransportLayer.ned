package NEDs;
module TransportLayer
{
    parameters:
        @display("p=123,56;i=block/filter");
    gates:
        inout transGate[4];
    submodules:
        tcp: Tcp {
            @display("p=123,137;i=old/proc2");
        }
        udp: Udp {
            @display("p=123,216;i=device/card");
        }
        muxDmux: MuxDemuxModule {
            @display("p=223,181;i=block/join");
        }
    connections:
        muxDmux.muxDemuxGate[0] <--> tcp.tcpGate[2];
        muxDmux.muxDemuxGate[1] <--> udp.udpGate[1];
        muxDmux.muxDemuxGate[2] <--> transGate[3];
        tcp.tcpGate[0] <--> transGate[0];
        tcp.tcpGate[1] <--> transGate[1];
        udp.udpGate[0] <--> transGate[2];
}
