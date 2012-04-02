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
