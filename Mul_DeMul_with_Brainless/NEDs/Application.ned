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
module Application
{
    parameters:
        @display("i=device/pc2,gold;bgl=2");
    gates:
        inout appgate[];
    submodules:
        user: UserApplicationLayer {
            @display("i=block/browser;p=319,148;is=vl");
        }
        http: HttpProtocol {
            @display("p=123,56;i=block/filter");
        }
        ftp: FtpProtocol {
            @display("p=123,137;i=old/proc2");
        }
        tftp: TftpProtocol {
            @display("p=123,216;i=device/card");
        }
    connections allowunconnected:
        user.appGate[0] <--> http.httpGate[0];
        user.appGate[1] <--> ftp.ftpGate[0];
        user.appGate[2] <--> tftp.tftpGate[0];
        http.httpGate[1] <--> appgate[0];
        ftp.ftpGate[1] <--> appgate[1];
        tftp.tftpGate[1] <--> appgate[2];
}
