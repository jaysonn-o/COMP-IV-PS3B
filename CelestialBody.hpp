// "Copyright [2024] <Jason Ossai>"
#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
class CelestialBody : public sf::Drawable {
public:
    CelestialBody();
    CelestialBody(double x, double y, double xvel, double yvel, double mass);

    // Sets the sprite position in window based on the conversion factor
    void setPositionInWindow(double conversionFactor);
    sf::Vector2f getSpritePosition() const;
    void setX(double value) { x = value; }
    void setY(double value) { y = value; }
    double getX() const;
    double getY() const;
    double getMass() const;
    friend std::istream& operator>>(std::istream& in, CelestialBody& body);
    friend std::ostream& operator<<(std::ostream& out, const CelestialBody& body);
    void updatep(double dt);
    void updateVel(double x1, double y1, double dt);
private:
    double x, y, xvel, yvel, mass;
    sf::Texture texture;
    sf::Sprite sprite;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
