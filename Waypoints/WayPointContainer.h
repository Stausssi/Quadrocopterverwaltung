#ifndef QUADROCOPTER_WAYPOINTCONTAINER_H
#define QUADROCOPTER_WAYPOINTCONTAINER_H

#include "../includes.h"
#include "WayPoint.h"

template <typename T, size_t n>
using Container = std::array<T, n>;

class WayPointContainer {
private:
    static const int MAX_ITEMS = 100;
    Container<const WayPoint*, MAX_ITEMS> m_waypoints { nullptr };
    int m_numItems = 0;
public:
    WayPointContainer() = default;

    WayPoint& operator[](const int& i) const;

    [[nodiscard]] int count() const;
    void add(const WayPoint& arg);
    void print(bool contentFlag=true) const;
    [[nodiscard]] double distance() const;
};

#endif //QUADROCOPTER_WAYPOINTCONTAINER_H
