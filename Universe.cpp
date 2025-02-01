// "Copyright [2024] <Jason Ossai>"
#include "Universe.hpp"
#include <cmath>

const double Universe::G = 6.67e-11;

Universe::Universe() : num_planets(0), universe_radius(2.50e+11) {
    bodies.resize(num_planets);
}

double Universe::getUniverseRadius() const {
    return universe_radius;
}

std::vector<CelestialBody>& Universe::getBodies() {
    return bodies;
}

std::istream& operator>>(std::istream& in, Universe& universe) {
    in >> universe.num_planets >> universe.universe_radius;
    universe.bodies.resize(universe.num_planets);
    for (int i = 0; i < universe.num_planets; ++i) {
        in >> universe.bodies[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Universe& universe) {
    out << universe.num_planets << " " << universe.universe_radius << "\n";
    for (const auto& body : universe.bodies) {
        out << body << "\n";
    }
    return out;
}

void Universe::step(double dt) {
    std::vector<double> changesInXvel(bodies.size(), 0);  // Store changes in x velocity
    std::vector<double> changesInYvel(bodies.size(), 0);  // Store changes in y velocity

    // 1. Calculate forces and change in velocities (changesV) for each body
    for (size_t i = 0; i < bodies.size(); i++) {
        for (size_t j = 0; j < bodies.size(); j++) {
            if (i != j) {
                double dx = bodies[j].getX() - bodies[i].getX();
                double dy = bodies[j].getY() - bodies[i].getY();
                double r = sqrt(dx * dx + dy * dy);
                double F = G * bodies[i].getMass() * bodies[j].getMass() / (r * r * r);
                changesInXvel[i] += F * dx / bodies[i].getMass() * dt;
                changesInYvel[i] += F * dy / bodies[i].getMass() * dt;
            }
        }
    }

    // 2. Update velocities and positions for each body
    for (size_t i = 0; i < bodies.size(); i++) {
        bodies[i].updateVel(changesInXvel[i], changesInYvel[i], 1);
        bodies[i].updatep(dt);
    }
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& body : bodies) {
        target.draw(body, states);
    }
}
