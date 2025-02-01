// "Copyright [2024] <Jason Ossai>"
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP
#include <vector>
#include "CelestialBody.hpp"

class Universe : public sf::Drawable {
public:
    Universe();
    double getUniverseRadius() const;
    std::vector<CelestialBody>& getBodies();
    // Reads Universe data from an input stream
    friend std::istream& operator>>(std::istream& in, Universe& universe);

    // Writes Universe data to an output stream
    friend std::ostream& operator<<(std::ostream& out, const Universe& universe);
    void addBody(const CelestialBody& body);
    void step(double dt);

private:
    int num_planets;
    double universe_radius;
    std::vector<CelestialBody> bodies;
    static const double G;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
