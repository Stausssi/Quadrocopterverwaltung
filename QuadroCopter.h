#ifndef QUADROCOPTER_QUADROCOPTER_H
#define QUADROCOPTER_QUADROCOPTER_H

#include "QuadroCopterModel.h"

class QuadroCopter final : public QuadroCopterModel {
private:
    std::string m_name;
    WayPoint m_home;

    void configure(const std::string &model, double range) override;
public:
    QuadroCopter() = delete;
    QuadroCopter(
            const std::string& name,
            const WayPoint& home,
            const std::string& model,
            double range
            );

    void add(const WayPoint& arg) override;
    [[nodiscard]] double distance() const override;
    void print() const override;
};

#endif //QUADROCOPTER_QUADROCOPTER_H
