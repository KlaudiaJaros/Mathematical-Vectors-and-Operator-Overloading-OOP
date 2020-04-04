#include <iostream>

using namespace std;

// vectors, as in maths, points x,y 2D
struct vec2
{
	float x = 0.0f;
	float y = 0.0f;
	
	vec2 (float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	// a copy constructor:
	vec2 (const vec2 &other)
	{
		this->x = other.x;
		this->y = other.y;	
	}
	float get_length()
	{
		return sqrt((this->x * this->x) + (this->y * this->y));
	}
	float dot_product(const vec2 &other)
	{
		float product = this->x * other.x + this->y *other.y;
		return product;
	}
	bool operator==(const vec2 &rhs)
	{
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2 &rhs)
	{
		return !(*this == rhs);
	}
	bool operator<(const vec2 &rhs)
	{
		float len1 = (this->x * this->x) + (this->y * this->y);
		float len2 = (rhs.x * rhs.x) + (rhs.y * rhs.y);
		return (len1 < len2);
	}
	bool operator>(const vec2 &rhs)
	{
		float len1 = (this->x * this->x) + (this->y * this->y);
		float len2 = (rhs.x * rhs.x) + (rhs.y * rhs.y);
		return (len1 > len2);		
	}
	bool operator<=(const vec2 &rhs)
	{
		return !(*this > rhs);
	}
	bool operator>=(const vec2 &rhs)
	{
		return !(*this < rhs);
	}
	vec2 operator+(const vec2 &rhs)
	{
		return vec2(this->x + rhs.x, this->y + rhs.y);
	}
	vec2 operator-(const vec2 &rhs)
	{
		return vec2(this->x - rhs.x, this->y - rhs.y);
	}
	vec2 operator*(float scale)
	{
		return vec2(this->x * scale, this->y * scale);
	}
	vec2 operator*(const vec2 &rhs)
	{
		return vec2(this->x * rhs.x, this->y * rhs.y);
	}
	vec2 operator/(float scale)
	{
		return vec2(this->x / scale, this->y / scale);
	}
	vec2 operator/(const vec2 &rhs)
	{
		return vec2(this->x / rhs.x, this->y / rhs.y);
	}
	// return a reference, the original object, do not create unnecessary copies:
	vec2& operator=(const vec2 &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}
	vec2 operator+=(const vec2 &rhs)
	{
		this->x = this->x + rhs.x;
		this->y = this->y + rhs.y;
		return *this;
	}	
	vec2 operator-=(const vec2 &rhs)
	{
		this->x = this->x - rhs.x;
		this->y = this->y - rhs.y;
		return *this;
	}
	vec2 operator*=(const vec2 &rhs)
	{
		this->x = this->x * rhs.x;
		this->y = this->y * rhs.y;
		return *this;
	}
	vec2 operator/=(const vec2 &rhs)
	{
		this->x = this->x / rhs.x;
		this->y = this->y / rhs.y;
		return *this;
	}
	vec2 operator*=(float scale)
	{
		this->x = this->x * scale;
		this->y = this->y * scale;
		return *this;
	}
	vec2 operator/=(float scale)
	{
		this->x = this->x / scale;
		this->y = this->y / scale;
		return *this;
	}		
};
/*
// main with a couple of random tests:
int main()
{
	vec2 a(3.0f, 5.0f);
	cout << "a = { " << a.x << ", " << a.y << " }" << endl;
	vec2 b(3.0f, 8.0f);
	cout << "b = { " << b.x << ", " << b.y << " }" << endl;	
	vec2 c(3.0f, 5.0f);
	cout << "c = { " << c.x << ", " << c.y << " }" << endl;	
	
	cout << (a==b) << endl;
	cout << (a==c) << endl;
	cout << (a!=b) << endl;
	cout << (a<b) << endl;
	cout << (a>b) << endl;
	cout << (a<=b) << endl;
	cout << (a>=b) << endl;
	
	auto d = a + b;
	auto e = b + c;
	cout << d.x << ", " << d.y << endl;
	cout << e.x << ", "<< e.y  << endl;
	auto f = b - c;
	cout << f.x << ", "<< f.y  << endl;
	
	vec2 g (3.0f, 4.0f);
	cout << "g= " << g.x << ", " << g.y << endl;
	cout << (g.get_length()) << endl;
	
	return 0;
}
*/
