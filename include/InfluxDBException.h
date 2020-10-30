///
/// \author Adam Wegrzynek <adam.wegrzynek@cern.ch>
///

#ifndef INFLUXDATA_EXCEPTION_H
#define INFLUXDATA_EXCEPTION_H

#include <stdexcept>
#include <string>

#ifndef INFLUX_API
# ifdef _WIN32
#   ifdef INFLUX_LIB
       #define  INFLUX_API  __declspec(dllexport)
#   else
       #define  INFLUX_API  __declspec(dllimport)
#endif
# else
#define  INFLUX_API
# endif
#endif

namespace influxdb
{

class  INFLUX_API InfluxDBException: public std::runtime_error
{

public:
  InfluxDBException(const std::string& source, const std::string& message)
    : std::runtime_error::runtime_error("influx-cxx [" + source + "]: " + message) {}
};

} // namespace influxdb

#endif // INFLUXDATA_EXCEPTION_H
