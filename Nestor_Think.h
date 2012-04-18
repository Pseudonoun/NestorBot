#ifndef RBGOAL_THINK_H
#define RBGOAL_THINK_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   RBGoal_Think .h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class to arbitrate between a collection of high level goals, and
//          to process those goals.
//			This is by far the portion of the bot that I have given the most
//			consideration.  I wanted the 
//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include "2d/Vector2D.h"
#include "../../Goals/Goal_Think.h"
#include "../../AbstRaven_Bot.h"
#include "../../Goals/Goal_Evaluator.h"



class NestorGoal_Think : public Goal_Think
{


public:

  NestorGoal_Think(AbstRaven_Bot* pBot);
  ~NestorGoal_Think();


    //this method iterates through each goal evaluator and selects the one
  //that has the highest score as the current goal
  virtual void Arbitrate();
  
  //top level goal types
  virtual void AddGoal_MoveToPosition(Vector2D pos);
  virtual void AddGoal_GetItem(unsigned int ItemType);
  virtual void AddGoal_Explore();
  virtual void AddGoal_AttackTarget();
    //top level goal types
//   virtual void AddGoal_GetItem(unsigned int ItemType);
//  virtual void AddGoal_Camp();  //Not used yet, rethinking approach
};


#endif