#include "Nestor_BotScriptor.h"

Nestor_BotScriptor* Nestor_BotScriptor::Instance()
{
  static Nestor_BotScriptor instance;

  return &instance;
}

/*********
* A simple change to this scrip allows for several lua loadouts depending on
* number of bots in the match.
*********/
Nestor_BotScriptor::Nestor_BotScriptor():Scriptor()
{
	//Pulling the number of bots parameter from the engine
	int enviro = script->GetInt("NumBots");
	if ( enviro < 3 ) //1 enemy means we have to me more direct
		RunScriptFile("Bots/NestorBot/Nestor_Aggro_Bot.lua");
	else if ( enviro > 4 ) //more than 3 enemies means we can't be as calculating.
		RunScriptFile("Bots/NestorBot/Nestor_Manic_Bot.lua");
	else 
		RunScriptFile("Bots/NestorBot/Nestor_Sneak_Bot.lua");	
}