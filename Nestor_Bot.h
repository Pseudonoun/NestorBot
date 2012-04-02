#ifndef NESTOR_BOT_H
#define NESTOR_BOT_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Nestor_Bot.h
//			A port of Raven_Bot.h
//
//	Author: Team Nestor
//  Author of Raven: Mat Buckland (www.ai-junkie.com)
//
//  Desc:
//-----------------------------------------------------------------------------
#include <vector>
#include <iosfwd>
#include <map>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "Nestor_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "Nestor_BotScriptor.h"


class Raven_PathPlanner;
class Raven_Steering;
class Raven_Game;
class Regulator;
class Raven_Weapon;
struct Telegram;
class Raven_Bot;
class Goal_Think;
class Nestor_WeaponSystem;
class Raven_SensoryMemory;




class Nestor_Bot : public AbstRaven_Bot
{

protected:
	//bots shouldn't be copied, only created or respawned
  Nestor_Bot(const Nestor_Bot&);
  Nestor_Bot& operator=(const Nestor_Bot&);

  Nestor_BotScriptor* m_pScript;

public:
  
	Nestor_Bot(Raven_Game* world, Vector2D pos);
  virtual ~Nestor_Bot();

  //the usual suspects
  std::string  const GetName() const;
  void         DoUpdate();
  bool         HandleMessage(const Telegram& msg);
  virtual void			SelectBodyPen();
  virtual void			SelectHeadPen();
};




#endif