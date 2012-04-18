#include "Nestor_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "../../Raven_SensoryMemory.h"
#include "Nestor_WeaponSystem.h"
#include "../../armory/Weapon_RocketLauncher.h"
#include "../../armory/Weapon_RailGun.h"
#include "../../armory/Weapon_ShotGun.h"
#include "../../armory/Weapon_Blaster.h"
#include "misc/utils.h"
#include "../../lua/Raven_Scriptor.h"
#include "../../Raven_Game.h"
#include "../../Raven_UserOptions.h"
#include "2D/transformations.h"



//-------------------------------- ctor ---------------------------------------
//-----------------------------------------------------------------------------
Nestor_TargetingSystem::Nestor_TargetingSystem(AbstRaven_Bot* owner):
	AbstTargetingSystem(owner)
{}



//----------------------------- Update ----------------------------------------

//-----------------------------------------------------------------------------
void Nestor_TargetingSystem::Update()
{
  double ClosestDistSoFar = MaxDouble;
  double weakestLink = 100;
  m_pCurrentTarget       = 0;

  //grab a list of all the opponents the owner can sense
  std::list<AbstRaven_Bot*> SensedBots;
  SensedBots = m_pOwner->GetSensoryMem()->GetListOfRecentlySensedOpponents();
  
  std::list<AbstRaven_Bot*>::const_iterator curBot = SensedBots.begin();
  for (curBot; curBot != SensedBots.end(); ++curBot)
  {
    //make sure the bot is alive and that it is not the owner
    if ((*curBot)->isAlive() && (*curBot != m_pOwner) )
    {
      double dist = Vec2DDistanceSq((*curBot)->Pos(), m_pOwner->Pos());
	  double dam = (*curBot)->Health();

		// This one took a lot of experementation.  The idea is to pick targets if they meet one
		// of two profiles.  Closest and weakest or within weapons range and at 50 or less health
		// and it will only go for the further target current target if their health is half of 
		// our current one.  This way we can start firing immedately and possibly not have to 
		// run through enemies to get to our new target.
	  if ((dist < ClosestDistSoFar && dam < weakestLink) || (dist < m_pOwner->GetWeaponSys()->GetCurrentWeapon()->GetIdealRange()
				&& dam < (weakestLink / 2)))
	 {
        ClosestDistSoFar = dist;
		weakestLink = dam;
        m_pCurrentTarget = *curBot;
      }
    }
  }
}
