#ifndef STICK_H
#define STICK_H
#include "Vec2.h"
#include "olcPixelGameEngine.h"
#include "Graphics.h"


class Stick
{
public:
	Stick() = default;
	//cube to application stuff
	Stick(Vec2 p0, Vec2 p1,int start,int end, int length);
	
	
	void Update(Vec2& p0, Vec2& p1, float dt);
	void Render(olc::PixelGameEngine* pge);
	

	
public:

	Vec2 p0;
	Vec2 p1;

	
	float length;
	int S_particle, E_particle;

	olc::Pixel color = olc::WHITE;
	olc::Pixel colorWhenSelected = olc::CYAN;

};
#endif // !STICK_H


