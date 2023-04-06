# Valve Index Macro Keyboard
Arduino R3 Beetle (AtMega32U4) based macro keyboard for front panel of Valve Index with 2 additional sockets.

You can use 2 sockets for another devices like eye trackers. Also 1 of socket can be connected to plate for extra-input.

## Images
Connected

<img width="600" src="/images/inplace.jpg"/>

Disconnected

<img width="400" src="/images/inplace_detached.jpg"/>

Detached

<img width="400" src="/images/detached.jpg"/>

3D Model

<img width="600" src="/images/Model.jpg"/>

## Connections:

<img width="600" src="/images/Scheme.jpg"/>


My example is bad because Beetle-board burned out between revisions...

Anyway: you need to measure the length of the wires with the usb plug hanging out.

<img width="400" src="/images/back_bad.jpg"/>

## Parts
- x1 Arduino R3 Beetle (AtMega32U4)
- x2 JST XH 2.54mm: https://aliexpress.ru/item/32855763468.html
- x1 USB Type A Male: https://aliexpress.ru/item/4000048686017.html
- x3 Resistors 10k
- x6 Any CherryMX-like Switches
- x6 Any Diode (I used 1n4148)

<img width="200" src="/images/Arduino.jpg"/> <img width="200" src="/images/JstXH.jpg"/>

<img width="200" src="/images/UsbMale.jpg"/><img width="200" src="/images/CherryMX.jpg"/>

## Before flashing
- Setup row-outputs in top
- Setup col-inputs in top
- Setup keys in setup function
