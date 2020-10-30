///
/// \author Adam Wegrzynek
///

#ifndef INFLUXDATA_INFLUXDB_H
#define INFLUXDATA_INFLUXDB_H

#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include <deque>

#include "Transport.h"
#include "Point.h"

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

class INFLUX_API InfluxDB
{
  public:
    /// Disable copy constructor
    InfluxDB & operator=(const InfluxDB&) = delete;

    /// Disable copy constructor
    InfluxDB(const InfluxDB&) = delete;

    /// Constructor required valid transport
    InfluxDB(std::unique_ptr<Transport> transport);

    /// Flushes buffer
    ~InfluxDB();

    /// Writes a metric
    /// \param metric
    void write(Point&& metric);

    /// Queries InfluxDB database
    std::vector<Point> query(const std::string& query);

    /// Flushes metric buffer (this can also happens when buffer is full)
    void flushBuffer();

    /// Enables metric buffering
    /// \param size
    void batchOf(const std::size_t size = 32);

    /// Adds a global tag
    /// \param name
    /// \param value
    void addGlobalTag(std::string& name, std::string& value);

  private:
    /// Buffer for points
    std::deque<std::string> mBuffer;

    /// Flag stating whether point buffering is enabled
    bool mBuffering;

    /// Buffer size
    std::size_t mBufferSize;

    /// Underlying transport UDP/HTTP/Unix socket
    std::unique_ptr<Transport> mTransport;

    /// Transmits string over transport
    void transmit(std::string&& point);

    /// List of global tags
    std::string mGlobalTags;
};

} // namespace influxdb

#endif // INFLUXDATA_INFLUXDB_H
