#ifndef NESTOR_WEAPONSYSTEM
#define NESTOR_WEAPONSYSTEM
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//	Name:	Nestor_WeaponSystems.h
//  Base Class Name:   Raven_WeaponSystem.h
//
//	Author: Team Nestor
//  Base Class Author: Mat Buckland (ai-junkie.com)
//
//  Desc:   class to manage all operations specific to weapons and their
//          deployment
//
//-----------------------------------------------------------------------------
#include <map>
#include "2d/vector2d.h"
#include "../../AbstWeaponSystem.h"

class AbstRaven_Bot;
class Raven_Weapon;



class Nestor_WeaponSystem : public AbstWeaponSystem
{

public:

  Nestor_WeaponSystem(AbstRaven_Bot* owner,
                     double      ReactionTime,
                     double      AimAccuracy,
                     double      AimPersistance);

  void          SelectWeapon();
};

#endif