#ifndef SWFG_BASE_HPP
#define SWFG_BASE_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <mutex>
#include <streambuf>
#include <tuple>
namespace swfg
{
 class Vec2
 {
  public:
   int x{};
   int y{};
   Vec2()=default;
   Vec2(int X,int Y)
   {
    x=X;y=Y;
   }
   Vec2 operator + (const Vec2& obj)
   {
    Vec2 calc;
    calc.x = this->x += obj.x;
    calc.y = this->y += obj.y;
    return calc;
   }
   Vec2 operator - (Vec2& obj)
   {
    Vec2 calc;
    calc.x = this->x -= obj.x;
    calc.y = this->y -= obj.y;
    return calc;
   }
   Vec2 operator * (Vec2& obj)
   {
    Vec2 calc;
    calc.x = this->x *= obj.x;
    calc.y = this->y *= obj.y;
    return calc;
   }
   Vec2 operator / (Vec2& obj)
   {
    Vec2 calc;
    calc.x = this->x /= obj.x;
    calc.y = this->y /= obj.y;
    return calc;
   }

 };
 class Vec4
 {
  public:
   int x,y,w,h;
   Vec4()
   {
    x=0;y=0;w=0;h=0;
   }
   Vec4(int X,int Y,int W,int H)
   {
    x=X;y=Y;w=W;h=H;
   }
   Vec4 operator * (int obj)
   {
    Vec4 calc;
    calc.x=this->x*obj;
    calc.y=this->y*obj;
    calc.w=this->w*obj;
    calc.h=this->h*obj;
    return calc;
   }
   Vec4 operator + (Vec4& obj)
   {
    Vec4 calc;
    calc.x = this->x += obj.x;
    calc.y = this->y += obj.y;
    calc.w = this->w += obj.w;
    calc.h = this->h += obj.w;
    return calc;
   }
   Vec4 operator += (Vec4& obj)
   {
    Vec4 calc;
    calc.x = this->x += obj.x;
    calc.y = this->y += obj.y;
    calc.w = this->w += obj.w;
    calc.h = this->h += obj.w;
    return calc;
   }
   Vec4 operator - (Vec4& obj)
   {
    Vec4 calc;
    calc.x = this->x -= obj.x;
    calc.y = this->y -= obj.y;
    calc.w = this->w -= obj.w;
    calc.h = this->h -= obj.h;
    return calc;
   }
   Vec4 operator * (Vec4& obj)
   {
    Vec4 calc;
    calc.x = this->x *= obj.x;
    calc.y = this->y *= obj.y;
    calc.w = this->w *= obj.w;
    calc.h = this->h *= obj.h;
    return calc;
   }
   Vec4 operator / (Vec4& obj)
   {
    Vec4 calc;
    calc.x = this->x /= obj.x;
    calc.y = this->y /= obj.y;
    calc.w = this->w /= obj.w;
    calc.h = this->h /= obj.h;
    return calc;
   }

 };

 using String = std::string;
 static const char* DefaultFont = "mplus-1p-medium.ttf";
 //static const char* DefaultFont = "GenShinGothic-Monospace-Regular.ttf";
 static SDL_Renderer* SwfgRenderer = nullptr;
 static SDL_Window*   SwfgWindow   = nullptr;


}
#endif //SWFG_BASE_HPP
