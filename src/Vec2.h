#pragma once

class Vec2
{
public:
	float x = 0.0f;
	float y = 0.0f;

	Vec2() {}
	Vec2(float xin, float yin)
		: x(xin), y(yin)
	{
	}

	Vec2 operator + (const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	void operator += (const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}
};