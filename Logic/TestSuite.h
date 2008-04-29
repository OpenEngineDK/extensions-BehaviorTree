// Test suite for testing the behavior tree extension
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _BEHAVIOR_TREE_TEST_SUITE_H_
#define _BEHAVIOR_TREE_TEST_SUITE_H_

#include <Logic/Task.h>
#include <Logic/FixedStatusTask.h>
#include <Logic/Sequence.h>
#include <Logic/Selector.h>
#include <Logic/Parallel.h>

#include <string>

namespace OpenEngine {
namespace Logic {

  class TestSuite {
  private:
  	int succeeded;
  	int failed;
  	
  	void resetStatus() {
  	    succeeded = 0;
    	failed = 0;
  	}
  	
  	void startTestCase(std::string testcase) {
  		resetStatus();
  		printf("\n");
  		printf("{ Starting test case '%s' }\n", testcase.c_str());
  	}
  	
  	void endTestCase() {
  		printf("\n");
  		printf("+ Test case %s!\n", (failed == 0 ? "succeeded" : "failed"));
  		printf("+ Result: %i tests succeeded, %i tests failed\n\n", succeeded, failed);
  	}
  	
  	void test(bool result, std::string error = "Output different from expected output") {
  		if (result) {
  			succeeded++;
  			printf(".");
  		} else {
  			failed++;
  			printf("\nTest #%i failed: %s\n", succeeded + failed, error.c_str());
  		}
  	}
  
  public:
    TestSuite() {
		resetStatus();
    }
    virtual ~TestSuite() {}
    
	void TestAll() {
		TestTask();
		TestSequence();
		TestSelector();
		TestParallel();
	}
	
	void TestTask() {
		startTestCase("FixedStatusTask");
	
		// Testing that all the primitives used for testing are correct
		FixedStatusTask* successTask = new FixedStatusTask(Task::TASK_SUCCESS);
		test(successTask->Execute() == Task::TASK_SUCCESS);
		
		FixedStatusTask* failTask = new FixedStatusTask(Task::TASK_FAIL);
		test(failTask->Execute() == Task::TASK_FAIL);
		
		FixedStatusTask* runningTask = new FixedStatusTask(Task::TASK_RUNNING);
		test(runningTask->Execute() == Task::TASK_RUNNING);
		
		FixedStatusTask* errorTask = new FixedStatusTask(Task::TASK_ERROR);
		test(errorTask->Execute() == Task::TASK_ERROR);

		endTestCase();
	}
	
	void TestSequence() {
		startTestCase("Sequence");
		
		// Testing that the empty sequence returns success
		Sequence* emptySequence = new Sequence();
		test(emptySequence->Execute() == Task::TASK_SUCCESS, "the empty sequence should terminate with success");
	
		// Testing that all tasks in the sequence terminate successfully
		Sequence* successSequence = new Sequence();
		successSequence->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		successSequence->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		successSequence->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(successSequence->Execute() == Task::TASK_SUCCESS, "the sequence should terminate successfully");

		// Testing that the sequence fails because of task #2
		Sequence* failSequence = new Sequence();
		failSequence->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		failSequence->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		failSequence->AppendTask(new FixedStatusTask(Task::TASK_ERROR));
		test(failSequence->Execute() == Task::TASK_FAIL, "the sequence should fail cleanly at task 2");
		
		endTestCase();
	}
	
	void TestSelector() {
		startTestCase("Selector");
				
		// Testing that the empty selector returns fail
		Selector* emptySelector = new Selector();
		test(emptySelector->Execute() == Task::TASK_FAIL, "the empty selector should terminate with fail");
	
		// Testing that all tasks in the sequence terminate successfully
		Selector* testSelector = new Selector();
		testSelector->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		testSelector->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testSelector->Execute() == Task::TASK_FAIL, "all tasks should fail, and the selector should fail");
		testSelector->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testSelector->Execute() == Task::TASK_SUCCESS, "the selector should terminate successfully from the last task");
		testSelector->AppendTask(new FixedStatusTask(Task::TASK_ERROR));
		test(testSelector->Execute() == Task::TASK_SUCCESS, "the selector should terminate successfully from the second-to-last task");
		
		endTestCase();
	}
	
	void TestParallel() {
		startTestCase("Parallel");
				
		// Testing that the empty parallel returns success
		Parallel* emptyParallel = new Parallel();
		test(emptyParallel->Execute() == Task::TASK_SUCCESS, "the empty (default) parallel should terminate with success");
		
		// Testing default setting, succeed-on-one = false, fail-on-one = true
		Parallel* testParallel = new Parallel();
		testParallel->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testParallel->Execute() == Task::TASK_SUCCESS, "all tasks succeed, and the parallel should succeed");
		testParallel->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testParallel->Execute() == Task::TASK_FAIL, "not all tasks succeed, and the parallel should fail");
		testParallel->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testParallel->Execute() == Task::TASK_FAIL, "not all tasks succeed, and the parallel should fail");
		
		// Testing setting, succeed-on-one = true, fail-on-one = false
		Parallel* testParallel2 = new Parallel(true, false);
		testParallel2->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testParallel2->Execute() == Task::TASK_FAIL, "all tasks fail, and the parallel should fail");
		testParallel2->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testParallel2->Execute() == Task::TASK_SUCCESS, "one task succeeds, and the parallel should succeed");
		testParallel2->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testParallel2->Execute() == Task::TASK_SUCCESS, "one task succeeds, and the parallel should succeed");
		
		/*
		  TEMPORARILY REMOVED, THIS TEST CASE HAS 
		  HARDNESS-TO-IMPLEMENT > BRAIN-CAPACITY-AT-PRESENT
		
		// Testing setting, succeed-on-one = true, fail-on-one = true
		Parallel* testParallel3 = new Parallel(true, true);
		testParallel3->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testParallel3->Execute() == Task::TASK_SUCCESS, "one task succeeds, and the parallel should succeed");
		testParallel3->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testParallel3->Execute() == Task::TASK_FAIL, "one task fails, and the parallel should fail");
		*/
		
		// Testing setting, succeed-on-one = false, fail-on-one = false
		Parallel* testParallel4 = new Parallel(false, false);
		testParallel4->AppendTask(new FixedStatusTask(Task::TASK_SUCCESS));
		test(testParallel4->Execute() == Task::TASK_SUCCESS, "all tasks succeed, and the parallel should succeed");
		testParallel4->AppendTask(new FixedStatusTask(Task::TASK_FAIL));
		test(testParallel4->Execute() == Task::TASK_FAIL, "not all tasks succeed, and the parallel should fail");

		endTestCase();
	}
  };

}
}

#endif // _BEHAVIOR_TREE_TEST_SUITE_H_
