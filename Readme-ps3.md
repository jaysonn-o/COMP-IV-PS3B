PS3b: N-Body Simulation (Dynamic)
Contact
Name: Jason Ossai
Section:COMP 2040
Time to Complete: 3 days

Description
This project extends static N-body simulation to model celestial bodies' motion in 2D space under gravitational pull, using dynamic physics simulation and animation for accurate simulation.

Features
Physics Simulation: Added heavenly body movement based on velocity. Over time, the position of each body changes in accordance with its velocity, while other bodies' gravitational pull affects velocities.
Time-Stepping: Using the elapsed time as a parameter and the celestial bodies' velocities, a step method was implemented in the Universe class to advance the celestial bodies in time.

Smart Pointers: To manage the lifetimes of celestial body objects, avoid memory leaks, and guarantee appropriate resource management, smart pointers (std::shared_ptr) were used.
Animation: The simulation was animated by continuously changing the locations of the heavenly bodies as they interacted with one another.
Data structures and algorithms

Physics Simulation: We used Newton's law of universal gravitation to determine the gravitational forces between all of the heavenly bodies. The resulting force from every other body in the cosmos is taken into account while updating the velocity of each body.
Velocity and Position Update: Each celestial body's position is updated according to its velocity for every time step (position = position + velocity × time). In a similar manner, the velocity is modified according to the net force acting on the body (acceleration = force / mass).

Initially, I faced issues with test, though they ran all successful 6 tests for me, but failed with the auto grader, I also had valgrind nad lint errors. I also faced issues with incorrect application of gravitational forces led to unexpected body movements, but after reviewing force calculation logic, errors were corrected in computing distance and direction between celestial bodies.

CHANGES: I was able to fix some lint errors, also my simulation moved better than the previous time I attempted it.

Extra Features
Added smart pointer usage to improve memory safety and efficiency.
I made minor improvements to the graphics, allowing for a more visually appealing simulation.

Acknowledgements
I received help from my instructor in understanding how to use classes and member requirement for tests file.

Credits
Celestial body images were obtained from NASA's public domain image library.

Statement of functionality of your program : Partial works , I say this though my simulation runs fine, I have testing and linting problems and valgrind which I tried and can't fix . Especially the namespace requirement for test file.