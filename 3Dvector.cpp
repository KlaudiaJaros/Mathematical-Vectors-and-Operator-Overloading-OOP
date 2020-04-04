#include <iostream>

using namespace std;

struct vec3D
{
	float x;
	float y;
	float z;
	
	vec3D(float a, float b, float c)
	{
		this->x = a;
		this->y = b;
		this->z = c;
	}
	vec3D(const vec3D &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;		
	}
	float get_length()
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z );
	}
	float dot_product(const vec3D &other)
	{
		float product = this->x * other.x + this->y *other.y + this->z *other.z;
		return product;
	}
	vec3D cross_product(const vec3D &other)
	{
		return vec3D(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
	}
	vec3D operator+(const vec3D &rhs)
	{
		return vec3D(this->x + rhs.x , this->y + rhs.y , this->z + rhs.z);
	}
	vec3D operator-(const vec3D &rhs)
	{
		return vec3D(this->x - rhs.x , this->y - rhs.y , this->z - rhs.z);
	}
	vec3D operator*(const vec3D &rhs)
	{
		return vec3D(this->x * rhs.x , this->y * rhs.y , this->z * rhs.z);
	}
	vec3D operator*(float scale)
	{
		return vec3D(this->x * scale , this->y * scale , this->z * scale);
	}	
	vec3D operator/(const vec3D &rhs)
	{
		return vec3D(this->x / rhs.x , this->y / rhs.y , this->z / rhs.z);
	}
	vec3D operator/(float scale)
	{
		return vec3D(this->x / scale , this->y / scale , this->z / scale);
	}		
	bool operator>(const vec3D &rhs)
	{
		float len1 = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
		float len2 = (rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z);
		return (len1 > len2);		
	}
	bool operator<(const vec3D &rhs)
	{
		float len1 = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
		float len2 = (rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z);
		return (len1 < len2);		
	}
	bool operator>=(const vec3D &rhs)
	{
		return !(*this < rhs);		
	}	
	bool operator<=(const vec3D &rhs)
	{
		return !(*this > rhs);		
	}	
	bool operator==(const vec3D &rhs)
	{
		return ((this->x==rhs.x) && (this->y==rhs.y) && (this->z==rhs.z) );
	}
	bool operator!=(const vec3D &rhs)
	{
		return !(*this==rhs);
	}
	vec3D operator=(const vec3D &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;	
		return *this;
	}
	vec3D operator+=(const vec3D &rhs)
	{
		this->x = this->x + rhs.x;
		this->y = this->y + rhs.y;
		this->z = this->z + rhs.z;
		return *this;
	}	
	vec3D operator-=(const vec3D &rhs)
	{
		this->x = this->x - rhs.x;
		this->y = this->y - rhs.y;
		this->z = this->z - rhs.z;
		return *this;
	}
	vec3D operator*=(const vec3D &rhs)
	{
		this->x = this->x * rhs.x;
		this->y = this->y * rhs.y;
		this->z = this->z * rhs.z;
		return *this;
	}
	vec3D operator/=(const vec3D &rhs)
	{
		this->x = this->x / rhs.x;
		this->y = this->y / rhs.y;
		this->z = this->z / rhs.z;
		return *this;
	}
	vec3D operator*=(float scale)
	{
		this->x = this->x * scale;
		this->y = this->y * scale;
		this->z = this->z * scale;
		return *this;
	}
	vec3D operator/=(float scale)
	{
		this->x = this->x / scale;
		this->y = this->y / scale;
		this->z = this->z / scale;
		return *this;
	}	
};

int main ()
{
	vec3D a (5.0f, 4.0f, 7.0f);
	vec3D b = a;
	b=b*8.0f;
	
	cout << a.x << ", "<< a.y << ", " << a.z << endl;
	cout << b.x << ", "<< b.y << ", " << b.z << endl;
	
	cout << "dot product:" << a.dot_product(b) << endl;
	
	vec3D c = a.cross_product(vec3D(9.0, 8.0, 7.0));
	cout << c.x << ", " << c.y << ", " << c.z << endl;
	return 0;
}