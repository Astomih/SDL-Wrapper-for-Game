#ifndef SWFG_TIMER_HPP
#define SWFG_TIMER_HPP
#include "Base.hpp"

class Timer
{
 private:
  double buffer=0.0;
  bool isStop=false;
 public:
  Timer(){}
  ///タイマー開始
  void Start()
  {
   buffer = SDL_GetTicks();
  }
  ///タイマー経過時間をミリ秒で返す
  double GetTimeAsMilliSeconds()
  {
   if(isStop)return buffer;
   else
    return SDL_GetTicks()-buffer;
  }
  ///タイマー経過時間を秒で返す
  double GetTimeAsSeconds()
  {
   if(isStop)return buffer/1000.0;
   else return (SDL_GetTicks()-buffer)/1000.0;
  }
  ///タイマー停止
  void Stop()
  {
   buffer=SDL_GetTicks()-buffer;
   isStop=true;
  }
};

#endif // SWFG_TIMER_HPP
