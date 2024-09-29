#include "Application.h"

void Application::Setup(olc::PixelGameEngine* pge)
{
	Particle* body1 = new Particle(pge->ScreenWidth() / 2, pge->ScreenHeight() / 2, 1.0f);
	body1->radius = 5;
	body1->color = olc::BLUE;
	particles.push_back(body1);

	Particle* body2 = new Particle(pge->ScreenWidth() / 4, pge->ScreenHeight() / 2, 1.0f);
	body2->radius = 5;
	body2->color = olc::GREEN;
	particles.push_back(body2);


}

void Application::Input(olc::PixelGameEngine* pge)
{

	if (pge->GetKey(olc::UP).bPressed)
	{
		pushforce.y = -50;
	}
	if (pge->GetKey(olc::DOWN).bPressed)
	{
		pushforce.y = +50;
	}
	if (pge->GetKey(olc::LEFT).bPressed)
	{
		pushforce.x = -50;
	}
	if (pge->GetKey(olc::RIGHT).bPressed)
	{
		pushforce.x = +50;
	}

	if (pge->GetKey(olc::UP).bReleased)
	{
		pushforce.y = 0;
	}
	if (pge->GetKey(olc::DOWN).bReleased)
	{
		pushforce.y = 0;
	}
	if (pge->GetKey(olc::LEFT).bReleased)
	{
		pushforce.x = 0;
	}
	if (pge->GetKey(olc::RIGHT).bReleased)
	{
		pushforce.x = 0;
	}
	if (pge->GetMouse(1).bPressed)
	{
		mousepos = Vec2(pge->GetMouseX(), pge->GetMouseY());
		Particle* particle = new Particle(mousepos.x, mousepos.y, 1.0f);
		particle->radius = 5;
		particle->color = olc::CYAN;
		particles.push_back(particle);
		
	}
	


}

void Application::Update(olc::PixelGameEngine* pge, float deltatime)
{
	

	for (auto particle : particles)
	{
		particle->AddForce(pushforce);

		Vec2 drag = Force::GenerateDragForce(*particle, 0.002);
		//particle->AddForce(drag);
		Vec2 friction = Force::GenerateFrictionForce(*particle, 10);
		particle->AddForce(friction);
		Vec2 weight = Vec2(0.0f, (particle->mass * 9.8f * 50));
		particle->AddForce(weight);
	}

	
	for (auto particle : particles)
	{
		particle->Integrate(deltatime);
	}


	//collision detection for out of bounds
	for (auto particle : particles)
	{
		particle->Boundry_wall();
	}

	
}

void Application::Render(olc::PixelGameEngine* pge)
{
	for (auto particle : particles)
	{
		pge->FillCircle(particle->position.x, particle->position.y, particle->radius, particle->color);
	}
}

void Application::Destroy()
{
  
}
