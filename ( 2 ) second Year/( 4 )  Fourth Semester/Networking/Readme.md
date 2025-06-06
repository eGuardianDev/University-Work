# Computer Networking



## info 1 за Изпита:
- Половината въпроси са от упражненията
- 2 въпроса от wireshark

## info 2 за изпита
- 8 еднакви мрежи разделяне (домашно 1)
- IP calculator (домашно 1)


## test prep
Дали два хоста са в една мрежа

Theory:
 - RIP

## network kontrolno
izpit kn

subnet
ip adressing


## random
5 и 6 темма са уводни няма да се изпитва толкова много


## last week 
частни адрес и класове мрежи



### main gns commands
```
=== router ===

system identity set name=XXX  

ip address add address=a.b.c.d/n interface=XXX - gateway/mask

=== rip ===
routing rip set redistribute-connected=yes

routing rip set update-timer=15s
routing rip set timeout-timer=30s
routing rip set garbage-timer=30s


routing rip interface add interface=all send=v2 receive=v2

routing rip interface add interface=etherX send=v2 receive=v2 # За интерфейса, който отива към други рутери
routing rip interface add interface=etherY passive=yes # За интерфейса, който отива към клиентите



добави всички мрежи, дори между рутери
routing rip network add network=ip/mask  - network ip, network mask



routing rip network print

routing rip route print

=== dhcp ===

ip pool add name=pool1 ranges=10.0.1.1-10.0.1.(2*YY)
ip pool print

ip dhcp-server add interface=ether1 address-pool=pool1 lease-time=24h name=dhcp1
disabled=no
ip dhcp-server print

ip dhcp-server network add address=10.0.1.0/24 dns-server=8.8.8.8,8.8.4.4 gateway=10.0.1.254
ip dhcp-server network print

ip dhcp-server lease print



=== VPC ===

ip a.b.c.d/n w.x.y.z - ipPc/mask gateway

save

ip dhcp # Request IP address via DHCP
show ip # See what address you were assigned
save


```



some resources:
 - [network chuck free ccna list](https://www.youtube.com/watch?v=S7MNX_UD7vY&list=PLIhvC56v63IJVXv0GJcl9vO5Z6znCVb1P)
