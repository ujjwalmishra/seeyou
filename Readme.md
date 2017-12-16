It is a peer to peer desktop application built using QT Creator. 
Install QT Creator and import .pro file.
Application uses tcp and udp to communicate with peers.
Peer connects which broadcast his state to other online peers.
This happens over UDP. Peers get notified and a peer ui is added to his screen.
Peers when add  a new activity like 'eating' etc. it broadcasts it updated state to peers.
Peers can ask for updated task description from the updated peers.
Updated peer will send his descirption using TCP.
Its work in progress.