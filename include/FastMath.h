#ifndef FASTMATH_H
#define FASTMATH_H

#define _USE_MATH_DEFINES
#include <math.h>   
#include <cmath>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

const double PI = M_PI;
const double SQUARED_PI = PI * PI;
const double HALF_PI = 0.5 * PI;
const double TWO_PI = 2.0 * PI;
const double THREE_PI_HALVES = TWO_PI - HALF_PI;

const double _sin_a = -4 / SQUARED_PI;
const double _sin_b = 4 / PI;
const double _sin_p = 9 / 40;
const float RADRATIO = 180.0 / M_PI;

static double _asin_a = -0.0481295276831013447;
static double _asin_b = -0.343835993947915197;
static double _asin_c = 0.962761848425913169;
static double _asin_d = 1.00138940860107040;

static double _atan_a = 0.280872;

template <class T>
class FastMath
{
public:
   const static T rad2deg ( const T x)
   {
      return (T) x * RADRATIO;
   }
   const static T deg2rad ( const T x )
   {
      return (T) x / RADRATIO;
   }
   const static T signum (const T x)
   {
      return (x > 0) - (x < 0);
   }

   const static T cos(const T x) 
   {
      return sin(x + ((x > HALF_PI) ? -THREE_PI_HALVES : HALF_PI));
   }

   const static T sin(T x) 
   {
      x = _sin_a * x * std::abs(x) + _sin_b * x;
      return _sin_p * (x * std::abs(x) - x) + x;
   }
 
   const static T tan(const T x) 
   {
      return sin(x) / cos(x);
   }

   const static T asin(const T x) 
   {
      return x * (std::abs(x) * (std::abs(x) * _asin_a + _asin_b) + _asin_c) + signum(x) * (_asin_d - std::sqrt(1 - x * x));
   }

   const static T acos(const T x) 
   {
      return HALF_PI - asin(x);
   }

   const static T atan(const T x) 
   {
      return (std::abs(x) < 1) ? x / (1 + _atan_a * x * x) : signum(x) * HALF_PI - x / (x * x + _atan_a);
   }
 
   const static T inverseSqrt (const T x )
   {
      uint32_t i = 0x5F1F1412 - (*(uint32_t*)&x >> 1);
      T tmp = *(T*)&i;
      return tmp * (1.69000231f - 0.714158168f * x * tmp * tmp);
   }

   const static T sqrt(const T x) 
   {
      return x * inverseSqrt(x);
   }
};

#endif
