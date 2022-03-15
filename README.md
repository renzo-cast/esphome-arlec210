# ESPHome with Arlec210 remote

**This project is still in progress and while the esphome lambda and switch class work as expected the remote is still not working and looks to be related to the implementation of arlec210 in rcswitch ([issue](https://github.com/nzbart/ArlecRC210Switch/issues/2))**

A repository to store my [ESPHome](https://esphome.io/) configuration and circuit for a NodeMCU connected with 433 mhz transmitter and receiver for communicating with the Arlec210 remote.

![ciruit diagram](circuit/circuit.png)

Diagram created with <https://www.circuit-diagram.org/editor/>

## Remote analysis

For more details see: https://github.com/sui77/rc-switch/wiki/Description-of-socket-protocols-from-different-brands-and-models

```bash
                            ID
A ON # 01100111000001010000 111 1 0110 111 00
A OF # 01100111000001010000 111 0 0110 111 10
B ON # 01100111000001010000 110 1 0110 110 00
B OF # 01100111000001010000 110 0 0110 110 10
C ON # 01100111000001010000 101 1 0110 101 00
C OF # 01100111000001010000 101 0 0110 101 10
D ON # 01100111000001010000 011 1 0110 011 00
D OF # 01100111000001010000 011 0 0110 011 10
* ON # 01100111000001010000 010 0 0110 010 10
* OF # 01100111000001010000 100 0 0110 100 10
```
