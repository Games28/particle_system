#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec2.h"
#include "Graphics.h"



struct Particle {
    int radius;

    Vec2 position;
    Vec2 old_position;
    Vec2 init_position;
    Vec2 velocity;
    Vec2 acceleration;

    Vec2 sumForces;
   
    float mass;
    float invMass;
   
    olc::Pixel color;
  

    Particle(float x, float y, float mass);
    
    ~Particle();

    void AddForce(const Vec2& force);
    void ClearForces();

    void Integrate(float dt);

    void Boundry_wall();

   
};

#endif


