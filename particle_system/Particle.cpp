#include "Particle.h"
#include "Sticks.h"
#include <iostream>

Particle::Particle(float x, float y, float mass) {
    this->position = Vec2(x, y);
    this->old_position = Vec2(x, y);
    this->mass = mass;
    
    if (mass != 0.0) {
        this->invMass = 1.0 / mass;
    }
    else {
        this->invMass = 0.0;
    }
    std::cout << "Particle constructor called!" << std::endl;
}



Particle::~Particle() {
    std::cout << "Particle destructor called!" << std::endl;
}

void Particle::AddForce(const Vec2& force) {
    sumForces += force;
}

void Particle::ClearForces() {
    sumForces = Vec2(0.0, 0.0);
}

void Particle::Integrate(float dt) {
    //euler integration
   acceleration = sumForces * invMass;
   velocity += acceleration * dt;
   position += velocity * dt;

    //verlet integration
   // velocity = Vec2(position.x - old_position.x, position.y - old_position.y);
   // old_position = Vec2(position.x, position.y);
   //
   // acceleration = sumForces / mass; //check to see in invmass still holds with this
   //
   // position += velocity + acceleration * dt * dt;

    ClearForces();
}

void Particle::Boundry_wall()
{
   
        if (position.x - radius <= 0)
        {
            position.x = radius;
            velocity.x *= -0.9f;
        }
        else if (position.x + radius >= Graphics::width)
        {
            position.x = Graphics::width - radius;
            velocity.x *= -0.9f;
        }

        if (position.y - radius <= 0)
        {
            position.y = radius;
            velocity.y *= -0.9f;
        }
        else if (position.y + radius >= Graphics::height)
        {
            position.y = Graphics::height - radius;
            velocity.y *= -0.9f;
        }
    
}

