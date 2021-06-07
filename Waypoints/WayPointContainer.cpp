#include "WayPointContainer.h"

WayPoint& WayPointContainer::operator[](const int &i) const {
    if (i >= m_numItems) {
        throw std::out_of_range("Invalid index!");
    }

    return *const_cast<WayPoint *>(m_waypoints.at(i));
}

int WayPointContainer::count() const {
    return m_numItems;
}

void WayPointContainer::add(const WayPoint &arg) {
    m_waypoints.at(m_numItems++) = new WayPoint(arg);
}

void WayPointContainer::print(bool contentFlag) const {
    if (!contentFlag) {
        // Nur Adresse der Instanz
        std::cout << "Startadresse des Containers: " << this << std::endl;
    } else {
        std::cout << "Wegpunktcontainer mit " << count() << " Stationen:" << std::endl;
        for (int i = 0; i < m_numItems; i++) {
            std::cout << "\t[" << i << "]: " << *m_waypoints[i] << std::endl;
        }
    }
}

double WayPointContainer::distance() const {
    double distance = 0;
    for (int i = 0; i < m_numItems - 1; i++) {
        // Addiere Distanz von jedem Element zum Nächsten
        distance += WayPoint::distance(*m_waypoints[i], *m_waypoints[i + 1]);
    }
    return distance;
}
