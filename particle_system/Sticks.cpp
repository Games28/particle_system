#include "Sticks.h"
#include "Particle.h"



Stick::Stick(Vec2 p0, Vec2 p1,int start, int end, int length)
{
	this->p0 = p0;
	this->p1 = p1;
	this->length = length;
	this->S_particle = start;
	this->E_particle = end;
	
}





void Stick::Update(Vec2& p0, Vec2& p1, float dt)
{
	
	

	  this->p0 = p0;
	 this->p1 = p1;
	float dx = this->p1.x - this->p0.x;
	float dy = this->p1.y - this->p0.y;
	float dist = sqrt(dx * dx + dy * dy);
	float diff = this->length - dist;
	
	float percent = (diff / dist) / 2;
	
	float offsetX = dx * percent;
	float offsetY = dy * percent;
	
	this->p0.x -= offsetX;
	this->p0.y -= offsetY;
	
	this->p1.x += offsetX;
	this->p1.y += offsetY;
	
	p0 = this->p0;
	p1 = this->p1;
		
		
	
		
	
}

void Stick::Render(olc::PixelGameEngine* pge)
{
	
	olc::Pixel p = olc::WHITE;
	
	Graphics::DrawLine(pge, this->p0.x, this->p0.y, this->p1.x, this->p1.y, p);
}


