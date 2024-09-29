#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "olcPixelGameEngine.h"
#include "Vec2.h"
#include <vector>

class Graphics
{
public:
    static const int PIXELS_PER_METER = 50;
    static const int width = 800;
    static const int height = 600;
    static int distance(Vec2 p0, Vec2 p1);
    static void DrawLine(olc::PixelGameEngine* pge, int x0, int y0, int x1, int y1, olc::Pixel color);
   
    
    static void DrawRect(olc::PixelGameEngine* pge, int x, int y, int width, int height, uint32_t color);
    
    static void DrawPolygon(olc::PixelGameEngine* pge, int x, int y, const std::vector<Vec2>& vertices, uint32_t color);
    
    
    static void DraweWireFrameModel(olc::PixelGameEngine* pge, const std::vector<Vec2> vecmodelcoordinates, float x, float y, float r, float s, olc::Pixel p);
};


#endif // !GRAPHICS_H
