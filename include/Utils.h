#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <cmath>	
#include <stdlib.h>
#include <iostream>
#include "FastMath.h"

template <class T>
class Utils {
public:
	T cubicInterpolation(T v0, T v1, T v2, T v3, T t) 
	{
		float t2 = t * t;
		float a0 = v3 - v2 - v0 + v1;
		float a1 = v0 - v1 - a0;
		float a2 = v2 - v0;
		float a3 = v1;

		return (a0 * (t * t2)) + (a1 * t2) + (a2 * t) + a3;
	}

	T quadraticBezierInterpolation(T a, T b, T c, T t) 
	{
		return (((1.0f - t) * (1.0f - t)) * a) + (((2.0f * t) * (1.0f - t)) * b) + ((t * t) * c);
	}

	T lengthOfQuadraticBezierCurve(T x0, T y0, T x1, T y1, T x2, T y2) 
	{
		if ((x0 == x1 && y0 == y1) || (x1 == x2 && y1 == y2)) 
		{
			return distance(x0, y0, x2, y2);
		}

		T ax, ay, bx, by;
		ax = x0 - 2 * x1 + x2;
		ay = y0 - 2 * y1 + y2;
		bx = 2 * x1 - 2 * x0;
		by = 2 * y1 - 2 * y0;
		T A = 4 * (ax * ax + ay * ay);
		T B = 4 * (ax * bx + ay * by);
		T C = bx * bx + by * by;

		T Sabc = 2.0f * (float) std::sqrt(A + B + C);
		T A_2 = (float) std::sqrt(A);
		T A_32 = 2.0f * A * A_2;
		T C_2 = 2.0f * (float) std::sqrt(C);
		T BA = B / A_2;

		return (A_32 * Sabc + A_2 * B * (Sabc - C_2) + (4.0f * C * A - B * B) * (float) std::log((2 * A_2 + BA + Sabc) / (BA + C_2))) / (4 * A_32);
	}

	T lerp(float a, float b, float t) 
	{
		if (t < 0)
			return a;
		return a + t * (b - a);
	}

	T doCirclesCollide(T x1, T y1, T radius1, T x2, T y2, T radius2) 
	{
		T dx = x2 - x1;
		T dy = y2 - y1;
		T d = radius1 + radius2;
		return (dx * dx + dy * dy) < (d * d);
	}

	static T distance(T x1, T y1, T x2, T y2) 
	{
		T a = x1 - x2;
		T b = y1 - y2;

		return (float) std::sqrt(a * a + b * b);
	}

	static T euclideanDistanceSq2D(T x1, T y1, T x2, T y2) 
	{
		T dx = x1 - x2;
		T dy = y1 - y2;
		return dx * dx + dy * dy;
	}

	T manhattanDistance(T x1, T y1, T x2, T y2) 
	{
		return std::abs(x1 - x2) + std::abs(y1 - y2);
	}

	T euclideanDistance(T x1, T y1, T x2, T y2) 
	{
		T a = x1 - x2;
		T b = y1 - y2;

		return (float) std::sqrt(a * a + b * b);
	}

	T angleInDegrees(T ownerRotation, T x1, T y1, T x2, T y2) 
	{
		return std::abs(ownerRotation - angleInDegrees(x1, y1, x2, y2)) % 360;
	}

	T angleInDegrees(T originX, T originY, T targetX, T targetY) 
	{
		return (float) FastMath<T>::rad2deg(std::atan2(targetY - originY, targetX - originX));
	}

	T angleInRadians(T originX, T originY, T targetX, T targetY) 
	{
		return (float) std::atan2(targetY - originY, targetX - originX);
	}

	T shouldRotateCounterClockwise(T angleFrom, T angleTo) 
	{
		T diff = (angleFrom - angleTo) % 360;
		return diff > 0 ? diff < 180 : diff < -180;
	}

	T getRotatedX(T currentX, T currentY, T pivotX, T pivotY, T angleDegrees) {
		float x = currentX - pivotX;
		float y = currentY - pivotY;
		float xr = (x * std::cos(angleDegrees)) - (y * std::sin(angleDegrees));
		return xr + pivotX;
	}

	T getRotatedY(T currentX, T currentY, T pivotX, T pivotY, T angleDegrees) {
		T x = currentX - pivotX;
		T y = currentY - pivotY;
		T yr = (x * std::sin(angleDegrees)) + (y * std::cos(angleDegrees));
		return yr + pivotY;
	}

	T getXAtEndOfRotatedLineByOrigin(T x, T lineLength, T angleDegrees) 
	{
		return x + std::cos(angleDegrees) * lineLength;
	}

	 T getYAtEndOfRotatedLineByOrigin(T y, T lineLength, T angleDegrees) 
	 {
		return y + std::sin(angleDegrees) * lineLength;
	}

	T collides(T x1, T y1, T radius1, T x2, T y2, T radius2) 
	{
		T d = distance(x1, y1, x2, y2);

		d -= radius1 + radius2;

		return d < 0;
	}
};



#endif
