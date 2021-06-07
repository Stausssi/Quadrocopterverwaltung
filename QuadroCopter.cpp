#include "QuadroCopter.h"

QuadroCopter::QuadroCopter(const std::string &name, const WayPoint &home, const std::string &model, double range) {
    m_name = name;
    m_home = home;
    m_model = model;
    m_range = range;
}

void QuadroCopter::configure(const std::string &model, double range) {
    m_model = model;
    m_range = range;
}

void QuadroCopter::add(const WayPoint &arg) {
    m_Container.add(arg);
}

double QuadroCopter::distance() const {
    // Weg von home zu erstem Wegpunkt
    double distance = WayPoint::distance(m_home, m_Container[0]);
    // Distanz aller Wegpunkte
    distance += m_Container.distance();
    // Distanz von letztem Wegpunkt zu home
    distance += WayPoint::distance(m_Container[m_Container.count() - 1], m_home);
    return distance;
}

void QuadroCopter::print() const {
    std::cout << "Quadrocopter '" << m_name << "':" << std::endl;
    std::cout << "\t- Modell: " << m_model << std::endl;
    std::cout << "\t- Reichweite: " << m_range << "km" << std::endl;
    std::cout << "\t- Heimatort: " << m_home << std::endl;

    m_Container.print();

    std::cout << "- Gesamte Distanz: " << QuadroCopter::distance() << "km" << std::endl << std::endl;
}
