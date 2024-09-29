#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Application.h"

class particle_system : public olc::PixelGameEngine
{
public:
	particle_system()
	{
		sAppName = "particle system";
	}

public:
	Application App;
public:

	bool OnUserCreate() override
	{
		App.Setup(this);


		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::GREY);
		App.Input(this);
		App.Update(this,fElapsedTime);
		App.Render(this);
		return true;
	}

	bool OnUserDestroy() override
	{
		App.Destroy();
		return true;
	}
};


int main()
{
	particle_system demo;
	if (demo.Construct(Graphics::width, Graphics::height, 1, 1))
		demo.Start();

}