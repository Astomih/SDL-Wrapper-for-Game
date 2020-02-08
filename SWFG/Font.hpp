#ifndef SWFG_FONT_HPP
#define SWFG_FONT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <tuple>
#include <iostream>
#include "Base.hpp"
namespace swfg
{
 class FontAssets
 {
   std::map<std::tuple<String,int>, TTF_Font*> cache_;
  public:
   TTF_Font* get_font(const String file,const int size){
    auto i = cache_.find({file,size});
    if(i == cache_.end())
    {

     TTF_Font* surf = TTF_OpenFont(file.c_str(),size);

     cache_[std::make_tuple(file,size)]=surf;
     //return surf;
    }
    return cache_[std::make_tuple(file,size)];
   }
   void flush(){
    auto i = cache_.begin();
    for(;i != cache_.end();++i)
    {
     TTF_CloseFont(i->second);
    }
    cache_.clear();

   }
   ~FontAssets()
   {
    flush();
    TTF_Quit();
   }
 };

 static FontAssets FontAsset;
 class Font {
  private:
   TTF_Font *mFont = nullptr;
   SDL_Surface* font;
   SDL_Rect rect;
   SDL_Texture* tex = nullptr;
   SDL_Renderer* renderer = SwfgRenderer;
   SDL_Color color;
   std::string string;
   Vec2 size;
   bool createdtex = false;
   bool isSetCenter = false;

  public:
   Font()
   {
    rect.x=0;rect.y=0;
   }
   Font(const String &FilePath, int fontSize)
   {
    rect.x=0;rect.y=0;
    mFont = FontAsset.get_font(FilePath,fontSize);
   }
   ~Font()
   {
    //font = nullptr;
    //SDL_FreeSurface(font);
    SDL_DestroyTexture(tex);
   }
   void LoadFont(const String FilePath, int fontSize)
   {
    mFont = FontAsset.get_font(FilePath,fontSize);
    createdtex = false;
   }
   void SetString(const std::string& m_string)
   {
    string = m_string;
    createdtex = false;
   }
   void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
   {

    color.a = a;
    color.r = r;
    color.g = g;
    color.b = b;


    createdtex = false;

   }

   void SetPosition(int x,int y)
   {
    rect.x = x;
    rect.y = y;
   }

   void SetCenter(int x,int y)
   {
    size.x = x;
    size.y = y;
    isSetCenter = true;
   }

   Vec2 GetPosition()
   {
    Vec2 pos;
    pos.x = rect.x;
    pos.y = rect.y;
    return pos;
   }
   Vec2 GetScale()
   {
    Vec2 scale;
    scale.x = rect.w;
    scale.y = rect.h;
    return scale;
   }
   Vec2 GetCenter()
   {
    Vec2 center;
    center.x = rect.x+(rect.w/2);
    center.y = rect.y+(rect.h/2);
    return center;
   }
   void Draw()
   {
    if(createdtex == false)
    {
     if(tex)
      SDL_DestroyTexture(tex);
     tex=nullptr;
     font = TTF_RenderUTF8_Solid(mFont,string.c_str(),color);
     tex = SDL_CreateTextureFromSurface(renderer,font);

     SDL_FreeSurface(font);
     //font=nullptr;

     createdtex = true;
    }
    SDL_QueryTexture(tex,nullptr,nullptr,&rect.w,&rect.h);
    if(isSetCenter)SetPosition(size.x-(rect.w/2),size.y-(rect.h/2));
    SDL_RenderCopy(renderer,tex,nullptr,&rect);
   }
 };


}
#endif /** __MYSDL_FONT_H */
