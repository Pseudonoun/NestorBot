#include "Nestor_BotMaker.h"


const Nestor_BotMaker Nestor_BotMaker::registerThis;

Nestor_BotMaker::Nestor_BotMaker() : BotMaker("Nestor_Bot") {}

AbstRaven_Bot* Nestor_BotMaker::makeBot(Raven_Game* world, Vector2D pos) const
   { 
      return new Nestor_Bot(world, pos); 
   }