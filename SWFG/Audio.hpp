#ifndef SWFG_AUDIO_HPP
#define SWFG_AUDIO_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Base.hpp"
#include <iostream>

namespace swfg
{
 class AudioAssets
 {
   std::map<String, Mix_Music*> cache_;
  public:
    Mix_Music* get_audio(const String file){
    std::map<String, Mix_Music*>::iterator i = cache_.find(file);
    if(i == cache_.end())
    {
     Mix_Music* surf = Mix_LoadMUS(file.c_str());
     i = cache_.insert(i, make_pair(file, surf));
    }
    return i->second;
   }
   void flush(){
    std::map<String, Mix_Music*>::iterator i = cache_.begin();
    for(;i != cache_.end();++i)
    {
     Mix_FreeMusic(i->second);
    }
    cache_.clear();
   }
   ~AudioAssets()
   {
    flush();
    Mix_Quit();
   }
 };
 static AudioAssets AudioAsset;
 class Audio
 {
  private:
   Mix_Music* music = nullptr;
  public:
   Audio()
   {
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
   }
   Audio(const String& filepath)
   {
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music = AudioAsset.get_audio(filepath);
   }
   ~Audio()
   {
    
   }
   void LoadMusic(const char* filepath)
   {
    music = nullptr;
    music = Mix_LoadMUS(filepath);
   }
   void PlayMusic()
   {
    Mix_PlayMusic(music,-1);
   }
   void StopMusic()
   {
     Mix_HaltMusic();
   }
 };
}
#endif //SWFG_AUDIO_HPP
