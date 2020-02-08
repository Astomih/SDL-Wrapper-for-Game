#ifndef SWFG_MATH_HPP
#define SWFG_MATH_HPP

#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>
#include "Base.hpp"
namespace swfg
{
 namespace Math
 {
  namespace Collision
  {
   bool inline Detection(const SDL_Rect& rect1,const SDL_Rect& rect2,const double& detectLength)
   {
    double x = abs((rect1.x+rect1.w/2)-(rect2.x+rect2.w/2));
    double y = abs((rect1.y+rect1.h/2)-(rect2.y+rect2.h/2));
    double A = sqrt(pow(x,2)+pow(y,2));
    if(A<detectLength)
    {
     return true;
    }
    return false;
   }
  }
  double inline Sin0_1(const double periodSec,const double t=SDL_GetTicks()/1000.0)
  {
   const double x = std::fmod(t, periodSec) / (periodSec * (1.0 / (2.0*M_PI)));

   return std::sin(x) * 0.5 + 0.5;
  }
  double inline Cos0_1(double periodSec,double t=SDL_GetTicks()/1000.0)
  {
   const double x = std::fmod(t, periodSec) / (periodSec * (1.0 / (2.0*M_PI)));

   return std::cos(x) * 0.5 + 0.5;
  }

 }
}
#endif // SWFG_MATH_HPP
