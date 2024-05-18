# esp32_sensors_remote_c
esp32 sensors remote logging with c++
![circuit_diagram](https://github.com/jonathanrandall/esp32_sensors_remote_c/blob/main/circuit_diagram.png)

depnds on the very easy to set up [cpp-httplib](https://github.com/yhirose/cpp-httplib) library. 

This repo implements an bmp280 and oled on an esp32 and then logs the output remotely with C++ to a csv file.
The columns of the csv file are time stamp, temperature, altitude, pressure.


