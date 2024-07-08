//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package NEDs;
module PC
{
    parameters:
        @display("i=device/pc2,gold");
    gates:
        inout gate[];

    submodules:
        appL: UserApplicationLayer {
            @display("p=45,26;i=block/sink");
        }
        tcpL: TransportLayer {
            @display("p=123,56;i=block/filter");
        }
        ipL: NetworkLayer {
            @display("p=123,137;i=old/proc2");
        }
        dlL: DataLinkLayer {
            @display("p=123,216;i=device/card");
        }
        phyL: PhysicalLayer {
            @display("p=57,226;i=device/card");
        }
    connections allowunconnected:
        appL.appGate[0] <--> tcpL.transGate[0];
        appL.appGate[1] <--> tcpL.transGate[1];
        appL.appGate[2] <--> tcpL.transGate[2];
        tcpL.transGate[3] <--> ipL.ipGate[0];
        ipL.ipGate[1] <--> dlL.dllGate[0];
        dlL.dllGate[1] <--> phyL.phyGate[0];
        phyL.phyGate[1] <--> gate++;
        
        
}
