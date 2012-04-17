#include "Nestor_WeaponSystem.h"
#include "../../armory/Weapon_RocketLauncher.h"
#include "../../armory/Weapon_RailGun.h"
#include "../../armory/Weapon_ShotGun.h"
#include "../../armory/Weapon_Blaster.h"
#include "../../AbstRaven_Bot.h"
#include "misc/utils.h"
#include "../../lua/Raven_Scriptor.h"
#include "../../Raven_Game.h"
#include "../../Raven_UserOptions.h"
#include "2D/transformations.h"



//------------------------- ctor ----------------------------------------------
//-----------------------------------------------------------------------------
Nestor_WeaponSystem::Nestor_WeaponSystem(AbstRaven_Bot* owner,
                                       double ReactionTime,
                                       double AimAccuracy,
                                       double AimPersistance): 
	AbstWeaponSystem(owner, ReactionTime, AimAccuracy, AimPersistance)

{

}


//-------------------------------- SelectWeapon -------------------------------
// This is the Burke Select Weapon routine, as of yet unmodified.  I believe I want
// to alter this at the think level but might return to make changes later.
//-----------------------------------------------------------------------------
void Nestor_WeaponSystem::SelectWeapon()
{ 
  //if a target is present use fuzzy logic to determine the most desirable 
  //weapon.
  if (m_pOwner->GetTargetSys()->isTargetPresent() && m_pOwner->GetTargetSys()->isTargetWithinFOV())
  {
    //calculate the distance to the target
    double DistToTarget = Vec2DDistance(m_pOwner->Pos(), m_pOwner->GetTargetSys()->GetTarget()->Pos());

    //for each weapon in the inventory calculate its desirability given the 
    //current situation. The most desirable weapon is selected
    double BestSoFar = MinDouble;

    WeaponMap::const_iterator curWeap;
    for (curWeap=m_WeaponMap.begin(); curWeap != m_WeaponMap.end(); ++curWeap)
    {
      //grab the desirability of this weapon (desirability is based upon
      //distance to target and ammo remaining)
      if (curWeap->second)
      {
        double score = curWeap->second->GetDesirability(DistToTarget);

        //if it is the most desirable so far select it
        if (score > BestSoFar)
        {
          BestSoFar = score;

          //place the weapon in the bot's hand.
          m_pCurrentWeapon = curWeap->second;
        }
      }
    }
  }

  else
  {
    m_pCurrentWeapon = m_WeaponMap[type_blaster];
  }
}