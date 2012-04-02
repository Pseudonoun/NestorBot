#ifndef RAVEN_BOTSTEERINGBEHAVIORS_H
#define STEERINGBEHAVIORS_H
#pragma warning (disable:4786)
//------------------------------------------------------------------------
//
//	Class: Nestor_BotSteeringBehavior.h
//		Based on Raven_BotSteeringBehavior.h
//
//  Desc:   class to encapsulate steering behaviors for a Raven_Bot
//
//	Author: Team Nestor
//  Base Class Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <vector>
#include <windows.h>
#include <string>
#include <list>
#include "2d/Vector2D.h"
#include "../../constants.h"
#include "../../AbstSteeringBehaviors.h"

class AbstRaven_Bot;
class Wall2D;
class BaseGameEntity;
class Raven_Game;

//------------------------------------------------------------------------

class Nestor_BotSteering : public AbstSteering
{
  
public:

  Nestor_BotSteering(Raven_Game* world, AbstRaven_Bot* agent);

  virtual ~Nestor_BotSteering();

};




#endif