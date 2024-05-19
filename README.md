# esp32_sensors_remote_c
esp32 sensors remote logging with c++
![circuit_diagram](https://github.com/jonathanrandall/esp32_sensors_remote_c/blob/main/circuit_diagram.png)

depnds on the very easy to set up [cpp-httplib](https://github.com/yhirose/cpp-httplib) library. 

This repo implements an bmp280 and oled on an esp32 and then logs the output remotely with C++ to a csv file.
The columns of the csv file are time stamp, temperature, altitude, pressure.

__tst_esp32_coms__: Remote side (client) C++ code. This has a makelists.txt file. If you want to compile just the code, you need to link the ssl and crypot, so for example run: _g++ -o ssl_client tst_comms2.cpp -lssl -lcrypto_

__esp32_local_sensor__: Esp32 local sketch.


