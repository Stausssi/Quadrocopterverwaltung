#ifndef QUADROCOPTER_QUADROCOPTERMODEL_H
#define QUADROCOPTER_QUADROCOPTERMODEL_H

#include "Waypoints/WayPoint.h"
#include "Waypoints/WayPointContainer.h"

class QuadroCopterModel {
protected:
    std::string m_model;
    double m_range{ 0 };
    WayPointContainer m_Container;

    [[maybe_unused]] virtual void configure(const std::string& model, double range) = 0;
public:
    virtual void add(const WayPoint& arg) = 0;
    virtual void print() const = 0;
    [[maybe_unused]] [[nodiscard]] virtual double distance() const = 0;
};

#endif //QUADROCOPTER_QUADROCOPTERMODEL_H
