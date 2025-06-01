# Exercise 3 - lab 1, how networks works

Router stands between networks. It cuts networks


### Ip addresses
192.168.10.0/24 - the ip of the network 

Ip address + mask - most important for network definition

/24 - cidr - classless inter domain routing
called mostly: prefix or slash

classful ip adressing
255.255.255.0 - class a
255.255.0.0 - class b
255.0.0.0 - class c

first adress  is netowork address 192.168.0.0 - last is 0
broadcast ip address 192.168.0.255 - last is 255
Note: the biggest and lowest number defines this two addresses

### from exercise 1 
ip address add adress=____ interface=ether1       - router command
ip 10.11.12.26/24 10.11.12.254 - ip/mask, gateway - PC commnad

every router has DHCP server, every PC has DHCP client - Dynamic host configuration protocol - automatically sets IP address
exercise 1 - manual setup of addresses

question from test - what is ping used for? testing the network connection (up to layer 3)

First part of network communicatin
pc1 - 10.11.12.26
pc3 - 10.11.12.27

testing if pc1 and pc3 are in the same network
takes ip of receiving router and mask
 10.11.12.27 AND 255.255.255.0 = 10.11.12.0


### Every layer encapsilaton
```
| data | -> information from program, data is known as payload (полезен товар)
| tcp/udp | data | -> segmenet
| ip source + ip destination | tcp/udp | data | -> packet
| mac dest + mac source | ip source + destination | tcp/udp | data | CRC | -> frame (кадър)
crc - cycle redundancy check
| -- Physical layer -- |
sometimes the frame isn't fully read, etc. It's more complicated that what is explained here. 
CRC is used to check if the system is fine. If the CRC is invalid, then the frame is discarted
```

The frame is accepted (handled) by the network card. if crc passes the | CRC | and | mac des + source | segmenets are deleted ( the header and footer fof frame ). Only the packets remains and it is given to the OS. Before that is only on level chips on Network card. Until then the OS and cpu isn't bothered with anything. 

TCP/IP stack is the part of the OS that works on the packets. (OSI is just theoretical model).
on next part is again removed the header and footer and only the segments remains.

Segments have number, like ID, it is returned ID+1. On Transport layer is checked if the segments are missing - 301, 303, 304,... but 302 is missing and is returned request to send 302 back.

when the source sees that 4 segments are accepted, then it sends 8 segments
if 8 segments are accepted, then 16 are given. it always multiplies x2 system

when streaming is used, we use UDP.

### MAC address 
A1:B2:C3:15:16:0E -> 12 hex numbers -> 48 bits

A1:B2:C3 - from organization (IEEE)
15:16:0E - from manufacturer (Ethernet, wifi cards, etc.)


### Configuration of network
ISP - router interface -  router - router interface - (integrated) switch -> 4 ethernet

in router interface - public ip address

ISP uses mac address to give internet to router 

### ARP
ARP message - broadcasts address to send mac address
ARP reply   - sends to ip, returns mac address 
The response is saved in os for 5 minutes ( for windows ) in special table
ARP are especially is needed in the beginning of the communication

When the PC doesn't find a ip locally in the network, but is not found , the response is send to the gateway (most often the router).
If gateway is not configured, there will be error.
When we send to the gateway, we need to know the MAC of the gateway, so ARP request is made to it. 

When the frame is send to he gateway -> CRC is checked -> header and footer is deleted, packet remains -> for the rules of the router (lab 3,4) -> the packet is send to another interface -> ARP request is made -> new mac is captured -> new frame with the old packet is created -> package is created

every hop - new frame is created.
every interface is another lan card
hub - повторител
carrier-sense multiple access / collition detection - csma/ca - when collition is detected, the frame is repeated.
This still exists in every h/w, but is not used until needed.

The switch learns the mac addresses on every port and makes mac table. switch garantees to every port specific speeds.
If daisy chain exist, the port remembers every host mac address on this port, even if there are many.

(H/W attack) - on port, generates mac addresses from one port. if mac table gets full, the switch works as hub

in the first seconds of the router activation, it works like a hub, until mac addresses tables are configured.
