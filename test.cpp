// "Copyright [2024] <Jason Ossai>"
#define BOOST_TEST_MODULE UniverseTest
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include "CelestialBody.hpp"
#include "Universe.hpp"

BOOST_AUTO_TEST_CASE(CelestialBodyYOrientationTest) {
    CelestialBody body;
    std::stringstream ss;
    ss << "1.0 -2.0 3.0 4.0 5.0 mercury.gif";
    ss >> body;
    body.setPositionInWindow(400.0 / 2.50e+11);

    // Assuming you have getters for sprite position or any method to check position.
    // Check if negative Y has been correctly oriented towards the bottom of the window.
    BOOST_CHECK_EQUAL(body.getSpritePosition().y, 300);
    std::cout << "Sprite Y position: " << body.getSpritePosition().y << std::endl;
}

BOOST_AUTO_TEST_CASE(CelestialBodyReadStreamTest) {
    CelestialBody body;
    std::stringstream ss;
    ss << "1.0 2.0 3.0 4.0 5.0 earth.gif";
    ss >> body;

    BOOST_CHECK_EQUAL(body.getX(), 1.0);
    BOOST_CHECK_EQUAL(body.getY(), 2.0);
    BOOST_CHECK_EQUAL(body.getMass(), 5.0);
}

BOOST_AUTO_TEST_CASE(UniverseReadStreamTest) {
    Universe universe;
    std::stringstream ss;
    ss << "2 2.50e+11\n";
    ss << "1.0 2.0 3.0 4.0 5.0 mars.gif\n";
    ss << "2.0 3.0 4.0 5.0 6.0 venus.gif\n";
    ss >> universe;

    const auto& bodies = universe.getBodies();
    BOOST_REQUIRE_EQUAL(bodies.size(), 2);
    BOOST_CHECK_EQUAL(bodies[0].getX(), 1.0);
    BOOST_CHECK_EQUAL(bodies[1].getX(), 2.0);
}

BOOST_AUTO_TEST_CASE(UniverseInitializationTest) {
    Universe universe;

    // Check if the default number of planets is correctly initialized.
    BOOST_CHECK_EQUAL(universe.getBodies().size(), 0);

    // Check if the default universe radius is correctly initialized.
    BOOST_CHECK_EQUAL(universe.getUniverseRadius(), 2.50e+11);
}

BOOST_AUTO_TEST_CASE(CelestialBodyUpdateTest) {
    CelestialBody body;
    std::stringstream ss;
    ss << "1.0 2.0 3.0 4.0 5.0 earth.gif";
    ss >> body;
    // Update velocity and position
    body.updateVel(0.5, 0.5, 1.0);  // Acceleration in x and y for 1 second
    body.updatep(1.0);  // Update for 1 second

    // Verify updated velocity and position
    BOOST_CHECK_CLOSE(body.getX(), 4.5, 1e-6);
    BOOST_CHECK_CLOSE(body.getY(), 6.5, 1e-6);
    BOOST_CHECK_CLOSE(body.getMass(), 5.0, 1e-6);
}

BOOST_AUTO_TEST_CASE(UniverseGravitationalForcesTest) {
    Universe universe;
    std::stringstream ss;
    ss << "2 2.50e+11\n";
    ss << "0.0 0.0 0.0 0.0 1.0 mars.gif\n";  // Place body at origin
    ss << "1.0 0.0 0.0 0.0 1.0 earth.gif\n";  // Place another body 1 unit to the right
    ss >> universe;

    // Update universe for one time step
    universe.step(1.0);

    const auto& bodies = universe.getBodies();

    BOOST_CHECK_GT(bodies[0].getX(), 0.0);

    // Similarly, we expect the second body to have moved to the left.
    BOOST_CHECK_LT(bodies[1].getX(), 1.0);
}
