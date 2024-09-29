#include "Graphics.h"

int Graphics::distance(Vec2 p0, Vec2 p1)
{
	int dx = p1.x - p0.x;
	int dy = p1.y - p0.y;
	return sqrt(dx * dx + dy * dy);
}

void Graphics::DrawLine(olc::PixelGameEngine* pge, int x0, int y0, int x1, int y1, olc::Pixel color)
{
	int delta_x(x1 - x0);
	int delta_y(y1 - y0);

	int longest_side_length = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

	float x_inc = delta_x / float(longest_side_length);
	float y_inc = delta_y / float(longest_side_length);

	float current_x = x0;
	float current_y = y0;

	for (int i = 0; i <= longest_side_length; i++)
	{
		pge->Draw(round(current_x), round(current_y), color);
		current_x += x_inc;
		current_y += y_inc;

	}
}

void Graphics::DrawRect(olc::PixelGameEngine* pge, int x, int y, int width, int height, uint32_t color)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int current_x = x + i;
			int current_y = y + j;
			pge->Draw(current_x, current_y, color);
		}
	}
}

void Graphics::DrawPolygon(olc::PixelGameEngine* pge, int x, int y, const std::vector<Vec2>& vertices, uint32_t color)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		int currIndex = i;
		int nextIndex = (i + 1) % vertices.size();
		DrawLine(pge, vertices[currIndex].x, vertices[currIndex].y, vertices[nextIndex].x, vertices[nextIndex].y, color);
	}
}

void Graphics::DraweWireFrameModel(olc::PixelGameEngine* pge, const std::vector<Vec2> vecmodelcoordinates, float x, float y, float r, float s, olc::Pixel p)
{
	std::vector<Vec2> vecTransformedCoordinates;
	int verts = vecmodelcoordinates.size();
	vecTransformedCoordinates.resize(verts);

	for (int i = 0; i < verts; i++)
	{
		vecTransformedCoordinates[i].x = vecmodelcoordinates[i].x * cosf(r) - vecmodelcoordinates[i].y * sinf(r);
		vecTransformedCoordinates[i].y = vecmodelcoordinates[i].x * sinf(r) + vecmodelcoordinates[i].y * cosf(r);
	}

	for (int i = 0; i < verts; i++)
	{
		vecTransformedCoordinates[i].x = vecTransformedCoordinates[i].x * s;
		vecTransformedCoordinates[i].y = vecTransformedCoordinates[i].y * s;
	}

	for (int i = 0; i < verts; i++)
	{
		vecTransformedCoordinates[i].x = vecTransformedCoordinates[i].x + x;
		vecTransformedCoordinates[i].y = vecTransformedCoordinates[i].y + y;
	}

	for (int i = 0; i < verts + 1; i++)
	{
		int j = (i + 1);
		pge->DrawLine(vecTransformedCoordinates[i % verts].x, vecTransformedCoordinates[i % verts].y,
			vecTransformedCoordinates[j % verts].x, vecTransformedCoordinates[j % verts].y, p);
	}

}
