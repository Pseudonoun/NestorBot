#include "Nestor_BotScriptor.h"

Nestor_BotScriptor* Nestor_BotScriptor::Instance()
{
  static Nestor_BotScriptor instance;

  return &instance;
}



Nestor_BotScriptor::Nestor_BotScriptor():Scriptor()
{
  RunScriptFile("Bots/NestorBot/Nestor_Bot.lua");
}