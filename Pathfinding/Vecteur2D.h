#pragma once
#include <math.h>
#include <limits>

struct Vecteur2D
{
	float x;
	float y;

	Vecteur2D(void);
	Vecteur2D(const Vecteur2D& v);
	Vecteur2D(int x,int y);
	Vecteur2D(float x,float y):x(x),y(y){}

	//mettre a zero
	void Zero(){x=0; y=0;}

	bool isZero()const{return (x*x + y*y) < 1E-10;}

	inline float Length()const;

	inline float LengthSq()const;

	inline void Normalize();

	inline float Dot(const Vecteur2D& v2)const;

	inline float Sign(const Vecteur2D& v2)const;

	inline Vecteur2D  Perp()const;

	inline void      Truncate(int max);

	inline float    Distance(const Vecteur2D &v2)const;

	inline float    DistanceSq(const Vecteur2D &v2)const;

	inline void      Reflect(const Vecteur2D& norm);

	inline Vecteur2D  GetReverse()const;

	const Vecteur2D& operator+=(const Vecteur2D &rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	const Vecteur2D& operator-=(const Vecteur2D &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	const Vecteur2D& operator*=(const float& rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	const Vecteur2D& operator/=(const float& rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	bool operator==(const Vecteur2D& rhs)const
	{
		return (x == rhs.x) && (y == rhs.y);
	}

	bool operator!=(const Vecteur2D& rhs)const
	{
		return (x != rhs.x) || (y != rhs.y);
	}
  
};


inline Vecteur2D operator*(const Vecteur2D &lhs, float rhs);
inline Vecteur2D operator*(float lhs, const Vecteur2D &rhs);
inline Vecteur2D operator-(const Vecteur2D &lhs, const Vecteur2D &rhs);
inline Vecteur2D operator+(const Vecteur2D &lhs, const Vecteur2D &rhs);
inline Vecteur2D operator/(const Vecteur2D &lhs, float val);


inline float Vecteur2D::Length()const
{
	return sqrt((double)(x * x + y * y));
}

inline float Vecteur2D::LengthSq()const
{
	return (x * x + y * y);
}

inline float Vecteur2D::Dot(const Vecteur2D &v2)const
{
	return x*v2.x + y*v2.y;
}

enum {clockwise = 1, anticlockwise = -1};

inline float Vecteur2D::Sign(const Vecteur2D& v2)const
{
	if (y*v2.x > x*v2.y)
	{ 
		return anticlockwise;
	}
	else 
	{
		return clockwise;
	}
}

inline Vecteur2D Vecteur2D::Perp()const
{
	return Vecteur2D(-y, x);
}

inline float Vecteur2D::Distance(const Vecteur2D &v2)const
{
	int ySeparation = v2.y - y;
	int xSeparation = v2.x - x;

	return sqrt((double)(ySeparation*ySeparation + xSeparation*xSeparation));
}

inline float Vecteur2D::DistanceSq(const Vecteur2D &v2)const
{
	int ySeparation = v2.y - y;
	int xSeparation = v2.x - x;

	return ySeparation*ySeparation + xSeparation*xSeparation;
}

inline void Vecteur2D::Truncate(int max)
{
	if (this->Length() > max)
	{
		this->Normalize();

		*this *= max;
	} 
}

inline void Vecteur2D::Reflect(const Vecteur2D& norm)
{
	*this += norm.GetReverse() * 2.0f * this->Dot(norm)  ;
}

inline Vecteur2D Vecteur2D::GetReverse()const
{
	return Vecteur2D(-this->x, -this->y);
}

inline void Vecteur2D::Normalize()
{ 
	int vector_length = this->Length();

	if (vector_length > std::numeric_limits<int>::epsilon())
	{
		this->x /= vector_length;
		this->y /= vector_length;
	}
}

inline Vecteur2D Vec2DNormalize(const Vecteur2D &v)
{
	Vecteur2D vec = v;

	int vector_length = vec.Length();

	if (vector_length > std::numeric_limits<int>::epsilon())
	{
		vec.x /= vector_length;
		vec.y /= vector_length;
	}

	return vec;
}

inline float Vec2DDistance(const Vecteur2D &v1, const Vecteur2D &v2)
{
	float ySeparation = v2.y - v1.y;
	float xSeparation = v2.x - v1.x;

	return sqrt((double)(ySeparation*ySeparation + xSeparation*xSeparation));
}

inline float Vec2DDistanceSq(const Vecteur2D &v1, const Vecteur2D &v2)
{
	float ySeparation = v2.y - v1.y;
	float xSeparation = v2.x - v1.x;

	return ySeparation*ySeparation + xSeparation*xSeparation;
}

inline float Vec2DLength(const Vecteur2D& v)
{
	return sqrt((double)(v.x*v.x + v.y*v.y));
}

inline float Vec2DLengthSq(const Vecteur2D& v)
{
	return (v.x*v.x + v.y*v.y);
}


inline Vecteur2D operator*(const Vecteur2D &lhs, float rhs)
{
	Vecteur2D result(lhs);
	result *= rhs;
	return result;
}

inline Vecteur2D operator*(float lhs, const Vecteur2D &rhs)
{
	Vecteur2D result(rhs);
	result *= lhs;
	return result;
}

inline Vecteur2D operator-(const Vecteur2D &lhs, const Vecteur2D &rhs)
{
	Vecteur2D result(lhs);
	result.x -= rhs.x;
	result.y -= rhs.y;

	return result;
}

inline Vecteur2D operator+(const Vecteur2D &lhs, const Vecteur2D &rhs)
{
	Vecteur2D result(lhs);
	result.x += rhs.x;
	result.y += rhs.y;

	return result;
}

inline Vecteur2D operator/(const Vecteur2D &lhs, float val)
{
	Vecteur2D result(lhs);
	result.x /= val;
	result.y /= val;

	return result;
}

