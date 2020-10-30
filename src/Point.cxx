///
/// \author Adam Wegrzynek <adam.wegrzynek@cern.ch>
///

#include "Point.h"

#include <iostream>
#include <chrono>
#include <memory>
#include <sstream>

namespace influxdb
{
Point::Point(const std::string& measurement) :
  mMeasurement(measurement), mTimestamp(Point::getCurrentTimestamp())
{
  //mValue = {};
  mTags = {};
  mFields = {};
}

Point&& Point::addField(const std::string& name, double value)
{
  std::stringstream convert;
  if (!mFields.empty()) convert << ",";

  convert << name << "=" << value; 
  mFields += convert.str();
  return std::move(*this);
}

Point&& Point::addField(const std::string& name, int value)
{
  std::stringstream convert;
  if (!mFields.empty()) convert << ",";

  convert << name << "=" << value << 'i';
  mFields += convert.str();
  return std::move(*this);
}

Point&& Point::addField(const std::string& name, long long int value)
{
  std::stringstream convert;
  if (!mFields.empty()) convert << ",";

  convert << name << "=" << value << 'i';
  mFields += convert.str();
  return std::move(*this);
}

Point&& Point::addField(const std::string& name, const std::string& value)
{
  std::stringstream convert;
  if (!mFields.empty()) convert << ",";

  convert << name << "=" << '"' << value << '"';
  mFields += convert.str();
  return std::move(*this);
}

Point&& Point::addTag(const std::string& key, const std::string& value)
{
  mTags += ",";
  mTags += key;
  mTags += "=";
  mTags += value;
  return std::move(*this);
}

Point&& Point::setTimestamp(std::chrono::time_point<std::chrono::system_clock> timestamp)
{
  mTimestamp = timestamp;
  return std::move(*this);
}

auto Point::getCurrentTimestamp() -> decltype(std::chrono::system_clock::now())
{
  return std::chrono::system_clock::now();
}

std::string Point::toLineProtocol() const
{
  std::string strTime = std::to_string(
    std::chrono::duration_cast <std::chrono::nanoseconds>(mTimestamp.time_since_epoch()).count()
  );
  std::cout << "time is :" << strTime << std::endl;
  return mMeasurement + mTags + " " + mFields + " " + strTime; /*std::to_string(
    std::chrono::duration_cast <std::chrono::nanoseconds>(mTimestamp.time_since_epoch()).count()
  );*/
}

std::string Point::getName() const
{
  return mMeasurement;
}

std::chrono::time_point<std::chrono::system_clock> Point::getTimestamp() const
{
  return mTimestamp;
}

std::string Point::getFields() const
{
  return mFields;
}

std::string Point::getTags() const
{
  return mTags.substr(1, mTags.size());
}

} // namespace influxdb
