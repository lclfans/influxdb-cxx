#!/bin/bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/local/influxdb-cxx/build/lib
g++ -std=c++11 -o query ./query.cpp -L/local/influxdb-cxx/build/lib -lInfluxDB -I/local/influxdb-cxx/include

./query
