#include "Nestor_BotScriptor.h"

Nestor_BotScriptor* Nestor_BotScriptor::Instance()
{
  static Nestor_BotScriptor instance;

  return &instance;
}

/*********
* A simple change to this scrip allows for two lua loadouts depending on
* number of bots in the match.  Origionally had three but two were too
* similar in play that there was no point.  No matter the density
* our bot will make a break for it if too much danger is sensed.
* The point of Aggro is to suppress that just a bit.
*********/
Nestor_BotScriptor::Nestor_BotScriptor():Scriptor()
{
	//Pulling the number of bots parameter from the engine
	int enviro = script->GetInt("NumBots");
	if ( enviro < 3 ) //2 or 1 enemy means we have to me more direct
		RunScriptFile("Bots/NestorBot/Nestor_Aggro_Bot.lua");
	else	//Normal bot density
		RunScriptFile("Bots/NestorBot/Nestor_Sneak_Bot.lua");	
}