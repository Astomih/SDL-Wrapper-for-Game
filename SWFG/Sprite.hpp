#ifndef SWFG_SPRITE_HPP
#define SWFG_SPRITE_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "Base.hpp"

namespace swfg
{
 static SDL_Rect camera;
 class ImageAssets
 {
   std::map<String, SDL_Surface*> cache_;
  public:
   SDL_Surface* get_image(String file){
    std::map<String, SDL_Surface*>::iterator i = cache_.find(file);
    if(i == cache_.end())
    {
     SDL_Surface* surf = IMG_Load(file.c_str());
     if(!surf)std::cout<<IMG_GetError()<<std::endl;
     i = cache_.insert(i, make_pair(file, surf));
    }
    return i->second;
   }
   void Flush(){
    std::map<String, SDL_Surface*>::iterator i = cache_.begin();
    for(;i != cache_.end();++i)
     SDL_FreeSurface(i->second);
    cache_.clear();
   }
   ~ImageAssets()
   {
    Flush();
    IMG_Quit();
   }
 };

 static ImageAssets ImageAsset;


 class Sprite
 {
  private:
   SDL_Surface* image = nullptr;
   SDL_Texture* localTex = nullptr;
   SDL_Rect rect;
   SDL_Rect trim;
   bool isCreatedTexture = false;

   void CreateSurface()
   {    
    if(isCreatedTexture == false)
    {
     localTex = SDL_CreateTextureFromSurface(SwfgRenderer,image);
     isCreatedTexture = true;
    }
   }
   void InitRects()
   {
    rect.x = 0;
    rect.y = 0;
    rect.w = 80;
    rect.h = 80;
    trim.x = 0;
    trim.y = 0;
    trim.w = rect.w;
    trim.h = rect.h;
   }
  public:
   Sprite()
   {
    InitRects();
   }
   Sprite(const Vec2& size)
   {
    InitRects();
    rect.w = size.x;
    rect.h = size.y;
   }
   Sprite(const String FilePath)
   {
    image = ImageAsset.get_image(FilePath);
    InitRects();
   }
   ~Sprite()
   {
    SDL_DestroyTexture(localTex);
   }
   void LoadImage(const String FilePath)
   {
    image = ImageAsset.get_image(FilePath);
   }
   void SetPosition(int x,int y)
   {
    rect.x = x;
    rect.y = y;
   }
   ///画像の大きさを設定(デフォルトは80x80)
   void SetScale(int w,int h)
   {
    rect.w = w;
    rect.h = h;
   }
   ///画像の真ん中の座標を設定
   void SetCenter(int x,int y)
   {
    rect.x = x-rect.w/2;
    rect.y = y-rect.h/2;
   }
   ///画像をstartからendまでの範囲でトリミング
   void Trimming(const Vec2& start,const Vec2& end)
   {
    trim.x = start.x;
    trim.y = start.y;
    trim.w = end.x;
    trim.h = end.y;
   }
   ///画像がx,yの量だけ移動
   void Move(int x,int y)
   {
    rect.x += x;
    rect.y += y;
   }
   ///画像がposの量だけ移動
   void Move(Vec2 pos)
   {
    rect.x += pos.x;
    rect.y += pos.y;
   }
   ///x,y,w,hの情報を取得
   SDL_Rect GetRect()
   {
    return rect;
   }
   ///画像左上の位置を取得
   Vec2 GetPosition()
   {
    Vec2 pos;
    pos.x = rect.x;
    pos.y = rect.y;
    return pos;
   }
   ///画像の大きさを取得
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
    CreateSurface();
    SDL_SetTextureColorMod(localTex,255,255,255);
    SDL_SetTextureAlphaMod(localTex,255);
    SDL_RenderCopy(SwfgRenderer,localTex,&trim,&rect);
   }
   ///Draw Sprite with Color
   void Draw(Uint8 r,Uint8 g,Uint8 b,Uint8 a)
   {
    CreateSurface();
    SDL_SetTextureColorMod(localTex,r,g,b);
    SDL_SetTextureAlphaMod(localTex,a);
    SDL_RenderCopy(SwfgRenderer,localTex,&trim,&rect);
   }
 };
}
#endif
