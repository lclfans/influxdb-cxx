///
/// \author Adam Wegrzynek
///

#ifndef INFLUXDATA_POINT_H
#define INFLUXDATA_POINT_H

#include <string>
#include <chrono>
#include <variant>

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

/// \brief Represents a point
class INFLUX_API Point
{
  public:
    /// Constructs point based on measurement name
    Point(const std::string& measurement);

    /// Default destructor
    ~Point() = default;

    /// Adds a tags
    Point&& addTag(const std::string& key, const std::string& value);

    /// Adds filed
    Point&& addField(const std::string& name, int value);
    Point&& addField(const std::string& name, long long int value);
    Point&& addField(const std::string& name, const std::string& value);
    Point&& addField(const std::string& name, double value);

    /// Generetes current timestamp
    static auto getCurrentTimestamp() -> decltype(std::chrono::system_clock::now());

    /// Converts point to Influx Line Protocol
    std::string toLineProtocol() const;

    /// Sets custom timestamp
    Point&& setTimestamp(std::chrono::time_point<std::chrono::system_clock> timestamp);

    /// Name getter
    std::string getName() const;

    /// Timestamp getter
    std::chrono::time_point<std::chrono::system_clock> getTimestamp() const;

    /// Fields getter
    std::string getFields() const;

    /// Tags getter
    std::string getTags() const;

  protected:
    /// A value
    //std::variant<long long int, std::string, double> mValue;

    /// A name
    std::string mMeasurement;

    /// A timestamp
    std::chrono::time_point<std::chrono::system_clock> mTimestamp;

    /// Tags
    std::string mTags;

    /// Fields
    std::string mFields;
};

} // namespace influxdb

#endif // INFLUXDATA_POINT_H
