///
/// \author Adam Wegrzynek
///

#ifndef INFLUXDATA_TRANSPORTINTERFACE_H
#define INFLUXDATA_TRANSPORTINTERFACE_H

#include <string>
#include <stdexcept>

#ifndef INFLUX_API
# ifdef _WIN32
#ifdef INFLUX_LIB
#define  INFLUX_API  __declspec(dllexport)
#else
#define  INFLUX_API  __declspec(dllimport)
#endif
# else
#define  INFLUX_API
# endif
#endif

namespace influxdb
{

/// \brief Transport interface
class INFLUX_API Transport
{
  public:
    Transport() = default;

    virtual ~Transport() = default;

    /// Sends string blob
    virtual void send(std::string&& message) = 0;

    /// Sends s request
    virtual std::string query(const std::string& /*query*/) {
      throw std::runtime_error("Queries are not supported in the selected transport");
    }
};

} // namespace influxdb

#endif // INFLUXDATA_TRANSPORTINTERFACE_H
