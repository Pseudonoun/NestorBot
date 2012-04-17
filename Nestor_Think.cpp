#include "Nestor_Think.h"
#include <list>
#include "misc/Cgdi.h"
#include "../../Raven_ObjectEnumerations.h"
#include "misc/utils.h"
#include "Nestor_BotScriptor.h"

#include "../../goals/Goal_MoveToPosition.h"
#include "../../goals/Goal_Explore.h"
#include "../../goals/Goal_GetItem.h"
#include "../../goals/Goal_Wander.h"
#include "../../goals/Raven_Goal_Types.h"
#include "../../goals/Goal_AttackTarget.h"


#include "../../goals/GetWeaponGoal_Evaluator.h"
#include "../../goals/GetHealthGoal_Evaluator.h"
#include "../../goals/ExploreGoal_Evaluator.h"
#include "../../goals/AttackTargetGoal_Evaluator.h"


NestorGoal_Think::NestorGoal_Think(AbstRaven_Bot* pBot):Goal_Think (pBot)
{
	//Spot for "Run the Hell Away!"


	
	// load priorities from script
	Nestor_BotScriptor* pMyScript = Nestor_BotScriptor::Instance();
  double HealthBias = pMyScript->GetDouble("Bot_HealthGoalTweaker");
  double ShotgunBias = pMyScript->GetDouble("Bot_ShotgunGoalTweaker");
  double RocketLauncherBias = pMyScript->GetDouble("Bot_RocketLauncherTweaker");
  double RailgunBias = pMyScript->GetDouble("Bot_RailgunGoalTweaker");
  double ExploreBias = pMyScript->GetDouble("Bot_ExploreTweaker");
  double AttackBias = pMyScript->GetDouble("Bot_AggroGoalTweaker");

  // get rid of the evaluators added by the superclass
  m_Evaluators.clear();

  //create the evaluator objects
  m_Evaluators.push_back(new GetHealthGoal_Evaluator(HealthBias));
  m_Evaluators.push_back(new ExploreGoal_Evaluator(ExploreBias));
  m_Evaluators.push_back(new AttackTargetGoal_Evaluator(AttackBias));
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(ShotgunBias,
                                                     type_shotgun));
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(RailgunBias,
                                                     type_rail_gun));
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(RocketLauncherBias,
                                                     type_rocket_launcher));
 
}
//----------------------------- dtor ------------------------------------------
//-----------------------------------------------------------------------------
NestorGoal_Think::~NestorGoal_Think()
{

}
/*
void Goal_Think::AddGoal_GetItem(unsigned int ItemType)
{
  if (notPresent(ItemTypeToGoalType(ItemType)))
  {
    RemoveAllSubgoals();
    AddSubgoal( new Goal_GetItem(m_pOwner, ItemType));
	//The camping style should be determined by what type of item
	//was just picked up.
	//AddSubgoal( new Goal_Camp(m_pOwner, ItemType));



//Several states that will need defining
//Sniper Mode: Stationary attack of a long distance target that will change states when
//	foe enters a determined range.  With a fixed focus on the weakest enemy in sight.
//RocketSpam Mode: Much like Sniper Mode but shorter wait time and a focus on whomever
//	is closest to a wall with looser targeting the further away they are.


switch(ItemType){
	case type_health:
		*If under attack, pick up meds regardless of health level, and do not camp.
		**If health level is above a threshold stop, if not take health and stop
		**Wait 10 to 20 seconds while watching for an enemy to enter range.
			***If health was taken attack outright with interception movement.
			***If health pack remains, take it when the enemy enters range, start 
				attack then resume normal exploration.
	case type_shotgun:
		*If under attack take Shotgun without camping.
		**Stop before taking shotgun, switch weapon to rail or rockets if available.
		**Enter Sniper Mode for 10 seconds, break if crit shotty range is entered by foe
			**If enemy triggers this condition grab shotgun and attack with mild evade
			**If 10 seconds pass take shotgun and resume exploring.
	case type_rail_gun:
		*If under attack only grab railgun if it is really close and do not camp.
		**Grab Railgun and Enter Sniper Mode until the railgun spawns again, 
			or enemy enters close range.
		**Once either condition is met resume exploration or full-on attacking.
	case type_rocket_launcher:
		*Same "under attack" behavior as railgun.
		**Grab rockets and Enter RocketSpam Mode for 10 seconds or close enemy.
		**Resume exploring or attacking on break.
   
  default: throw std::runtime_error("Goal_GetItem cannot determine item type");
  
		
  }
} */