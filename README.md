# esp32_sensors_remote_c
esp32 sensors remote logging with c++

depnds on the [cpp-httplib](https://github.com/yhirose/cpp-httplib) library.

This repo implements an bmp280 and oled on an esp32 and then logs the output remotely with C++ to a csv file.
The columns of the csv file are time stamp, temperature, altitude, pressure.


