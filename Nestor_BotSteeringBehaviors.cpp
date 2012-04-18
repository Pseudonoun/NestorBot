#include "Nestor_BotSteeringBehaviors.h"
#include "../../AbstRaven_Bot.h"
#include "2d/Wall2D.h"
#include "2d/Transformations.h"
#include "misc/utils.h"
#include "misc/Cgdi.h"
#include "../../Raven_Game.h"
#include "2d/geometry.h"
#include "Nestor_BotScriptor.h"
#include "../../Raven_Map.h"

#include <cassert>
#include "../../goals/Raven_Goal_Types.h"
#include "../../goals/Goal_AttackTarget.h"


#include "../../goals/GetWeaponGoal_Evaluator.h"
#include "../../goals/GetHealthGoal_Evaluator.h"
#include "../../goals/ExploreGoal_Evaluator.h"
#include "../../goals/AttackTargetGoal_Evaluator.h"
using std::string;
using std::vector;


//------------------------- ctor -----------------------------------------
//
//------------------------------------------------------------------------
Nestor_BotSteering::Nestor_BotSteering(Raven_Game* world, AbstRaven_Bot* agent): 
	AbstSteering(world, agent)
{
	Nestor_BotScriptor* myScript = Nestor_BotScriptor::Instance();
	m_dWeightSeparation = myScript->GetDouble("SeparationWeight");
    m_dWeightWander = myScript->GetDouble("WanderWeight");
    m_dWeightWallAvoidance = myScript->GetDouble("WallAvoidanceWeight");
    m_dViewDistance = myScript->GetDouble("ViewDistance");
	m_dWallDetectionFeelerLength = myScript->GetDouble("WallDetectionFeelerLength");
	m_Deceleration = normal;
    m_dWanderDistance = myScript->GetDouble("WanderDist");
    m_dWanderJitter = myScript->GetDouble("WanderJitterPerSec");
	m_dWanderRadius = myScript->GetDouble("WanderRad");
    m_dWeightSeek = myScript->GetDouble("SeekWeight");
    m_dWeightArrive = myScript->GetDouble("ArriveWeight");
	m_bCellSpaceOn = false;
    m_SummingMethod = prioritized;
	
	//stuff for the wander behavior
 // double theta = RandFloat() * TwoPi;

  //create a vector to a target position on the wander circle
 // m_vWanderTarget = Vector2D(m_dWanderRadius * cos(theta),
 //                             m_dWanderRadius * sin(theta));

}

//---------------------------------dtor ----------------------------------
Nestor_BotSteering::~Nestor_BotSteering(){}

//---------------------------- Separation --------------------------------
//
// this calculates a force repelling from the other neighbors
//------------------------------------------------------------------------
Vector2D Nestor_BotSteering::Separation(const std::list<AbstRaven_Bot*>& neighbors)
{  
  //iterate through all the neighbors and calculate the vector from the
  Vector2D SteeringForce;

  std::list<AbstRaven_Bot*>::const_iterator it = neighbors.begin();
  for (it; it != neighbors.end(); ++it)
  {
    //make sure this agent isn't included in the calculations and that
    //the agent being examined is close enough. ***also make sure it doesn't
    //include the evade target ***
    if((*it != m_pRaven_Bot) && (*it)->IsTagged() &&
      (*it != m_pTargetAgent1))
    {
      Vector2D ToAgent = m_pRaven_Bot->Pos() - (*it)->Pos();

      //scale the force inversely proportional to the agents distance  
      //from its neighbor.
	  //I changed this to reflect health but got worse results in general
	  SteeringForce += Vec2DNormalize(ToAgent)/ToAgent.Length();
    }
  }

  return SteeringForce;
}