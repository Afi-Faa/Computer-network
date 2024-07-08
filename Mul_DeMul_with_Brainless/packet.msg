struct applicationPacket{
    int data;
    int protocol;
    int ip;
    int portNo;
};
 packet TcpIpPacket {
    int srcAdd;
    int destAdd;
    applicationPacket appHeader;
    int tcpHeader;
    string ipHeader;
    string dllHeader;
    string phyHeader;
 }