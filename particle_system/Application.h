#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "Graphics.h"
#include "Force.h"
#include "Sticks.h"
#include <random>



class Application
{
public:
	Application() = default;
	~Application() = default;

	void Setup(olc::PixelGameEngine* pge);
	void Input(olc::PixelGameEngine* pge);
	void Update(olc::PixelGameEngine* pge, float deltatime);
	void Render(olc::PixelGameEngine* pge);
	void Destroy();

private:
	
	std::vector<Particle*> particles;
	
	Vec2 mousepos;
	Vec2 pushforce;

	
};

#endif // !APPLICATION_h



