
# Create the extension library
ADD_LIBRARY(Extensions_BehaviorTree
  Logic/BehaviorTree.cpp
  Logic/CompositeTask.cpp
  Logic/Sequence.cpp
  Logic/Selector.cpp
  Logic/Parallel.cpp
  Logic/LoopDecorator.cpp
  Logic/DebugDecorator.cpp
  Logic/RandomSelector.cpp
  Logic/ProbabilitySelector.cpp
  Logic/LoopOnSuccessDecorator.cpp
)
