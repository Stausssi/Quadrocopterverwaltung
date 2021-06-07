#ifndef QUADROCOPTER_WAYPOINT_H
#define QUADROCOPTER_WAYPOINT_H

#include "../includes.h"

using LOCATION = std::pair<double, double>;
static const double M_PI = atan(1.0) * 4;

class WayPoint {
private:
    std::string m_name = "<Empty>";
    LOCATION m_location;
    std::string m_GMS;

    void updateGMS();
    friend std::ostream& operator<<(std::ostream& ostream, const WayPoint& wayPoint);

    static std::string Degree2GMS(double latitude, double longitude);
    [[nodiscard]] static bool isValidLongitude(double longitude);
    [[nodiscard]] static bool isValidLatitude(double latitude);
public:
    WayPoint(const std::string& name, double latitude, double longitude);
    WayPoint(double latitude, double longitude);
    WayPoint(const WayPoint& wayPoint) : WayPoint(wayPoint.name(), wayPoint.latitude(), wayPoint.longitude()) {};
    WayPoint() : WayPoint(0, 0) {};

    [[nodiscard]] double latitude() const;
    [[maybe_unused]] void latitude(double latitude);
    [[nodiscard]] double longitude() const;
    [[maybe_unused]] void longitude(double longitude);
    [[nodiscard]] std::string name() const;

    void name(const std::string& name);

    static double radians(double arg);
    static double distance(const WayPoint& from, const WayPoint& to);
};


#endif //QUADROCOPTER_WAYPOINT_H
