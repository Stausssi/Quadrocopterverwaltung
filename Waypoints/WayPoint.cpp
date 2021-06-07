#include "WayPoint.h"

WayPoint::WayPoint(double latitude, double longitude) {
    if (isValidLatitude(latitude) && isValidLongitude(longitude)) {
        m_location = std::make_pair(latitude, longitude);
        m_GMS = Degree2GMS(latitude, longitude);
    } else {
        throw std::out_of_range("Latitude has to be between -90 and 90, Longitude between -180 and 180");
    }
}

WayPoint::WayPoint(const std::string &name, double latitude, double longitude) {
    if (isValidLatitude(latitude) && isValidLongitude(longitude)) {
        m_location = std::make_pair(latitude, longitude);
        m_GMS = Degree2GMS(latitude, longitude);
    } else {
        throw std::out_of_range("Latitude has to be between -90 and 90, Longitude between -180 and 180");
    }
    m_name = name;
}

bool WayPoint::isValidLongitude(double longitude) {
    return std::abs(longitude) < 180;
}

bool WayPoint::isValidLatitude(double latitude) {
    return std::abs(latitude) < 90;
}

double WayPoint::distance(const WayPoint &from, const WayPoint &to) {
    double lat = radians((from.latitude() + to.latitude()) / 2.0);
    double dx = 111.3 * std::cos(lat) * (from.longitude() - to.longitude());
    double dy = 111.3 * (from.latitude() - to.latitude());
    return std::sqrt(dx * dx + dy * dy);
}

std::ostream &operator<<(std::ostream &ostream, const WayPoint &wayPoint) {
    // Append GMS to stream
    return ostream << wayPoint.name() << " - (" << wayPoint.m_GMS << ")";
}

std::string WayPoint::Degree2GMS(double latitude, double longitude) {
    std::string latDir;
    if (latitude < 0) {
        latDir = "S";
        latitude *= -1;
    } else {
        latDir = "N";
    }

    std::string longDir;
    if (longitude < 0) {
        longDir = "W";
        longitude *= -1;
    } else {
        longDir = "E";
    }

    int degreeLat = static_cast<int>(latitude);
    int degreeLong = static_cast<int>(longitude);

    double afterCommaLat = (latitude - degreeLat) * 60;
    double afterCommaLong = (longitude - degreeLong) * 60;

    int minutesLat = static_cast<int>(afterCommaLat);
    int minutesLong = static_cast<int>(afterCommaLong);

    int secondsLat = static_cast<int>((afterCommaLat - minutesLat) * 60);
    int secondsLong = static_cast<int>((afterCommaLong - minutesLong) * 60);

    return
        std::to_string(degreeLat) + "\370" + std::to_string(minutesLat) + "'" + std::to_string(secondsLat) + "\"" + latDir +
        " " +
        std::to_string(degreeLong) + "\370" + std::to_string(minutesLong) + "'" + std::to_string(secondsLong) + "\"" + longDir;
}

double WayPoint::latitude() const {
    return m_location.first;
}

[[maybe_unused]] void WayPoint::latitude(double latitude) {
    m_location.first = latitude;
    updateGMS();
}

double WayPoint::longitude() const{
    return m_location.second;
}

[[maybe_unused]] void WayPoint::longitude(double longitude) {
    m_location.second = longitude;
    updateGMS();
}

void WayPoint::updateGMS() {
    m_GMS = Degree2GMS(this->latitude(), this->longitude());
}

std::string WayPoint::name() const{
    return m_name;
}

void WayPoint::name(const std::string &name) {
    m_name = name;
}

double WayPoint::radians(double arg) {
    return arg * (M_PI / 180);
}
