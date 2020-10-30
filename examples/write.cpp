#include "InfluxDBFactory.h"
#include "InfluxDBException.h"
#include <iostream>
using namespace std;

int main()
{
  std::unique_ptr<influxdb::InfluxDB> dbPtr;
  try
  {
    dbPtr = influxdb::InfluxDBFactory::Get("http://tsuser:tsuser@localhost:8086/?db=tsDB");
    influxdb::Point point("testTable");
    point.addField("Temperature", 300.10);
    point.addTag("Device", "D1");
    cout << point.toLineProtocol() <<endl;
    dbPtr->write(std::move(point));

    influxdb::Point point1("testString");
    point1.addField("Temperature", "300.10");
    point1.addTag("Device", "D1");
    cout << point1.toLineProtocol() <<endl;
    dbPtr->write(std::move(point1));

  }
  catch(influxdb::InfluxDBException& e)
  {
    cout <<"error:"<<e.what()<<endl;
  }
  catch(...)
  {
    cout <<"other errors"<<endl;
  }

  cout << "Write done" << endl;
  return 0;
}

