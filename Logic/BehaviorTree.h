// Task that encapsulates an behavior tree of tasks.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _BEHAVIOR_TREE_H_
#define _BEHAVIOR_TREE_H_

#include <Logic/TaskDecorator.h>

namespace OpenEngine {
namespace Logic {

  /**
   * Task that encapsulates an behavior tree of tasks.
   *
   * @see http://aigamedev.com/questions/popular-behavior-tree-design
   */
  class BehaviorTree : public TaskDecorator {
  public:
	/**
	 * @param task Root of the tree
	 */
    BehaviorTree(Task* task);
    virtual ~BehaviorTree();
    virtual TaskStatus Execute();
  };

}
}

#endif // _BEHAVIOR_TREE_H_
