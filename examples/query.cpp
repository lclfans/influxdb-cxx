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
    std::vector<influxdb::Point> dbPoints = dbPtr->query("select * from testTable");
    for(int i = 0; i < dbPoints.size(); i++)
    {
      cout << "===========================" << endl;
      cout << "Name: " <<dbPoints[i].getName()<<endl;
      cout << "Fields: " <<dbPoints[i].getFields()<<endl;
      cout << "Tags: " <<dbPoints[i].getTags()<<endl;
    }

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

