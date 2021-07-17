CPSC 223 - Linked List Big Five / Rule of Five

For this assignment, you must implement the "big five" class methods for the supplied LinkedList class:

    Copy constructor
    Move constructor
    Copy operator=
    Move operator=
    Destructor (~)

Bonus: Also need to do the initializer_list constructor (it’s required for the move operations)

These interfaces are in the public: section and clearly marked in the LinkedList.h file. I have included an implementation of an ADT array in Array.h that implements these methods as an example. No, you can’t copy/paste between the two and have it work. The Big Five methods are documented in various places on the Internet. Here’s a couple of examples trying to show general solutions:

    http://en.cppreference.com/w/cpp/language/rule_of_three
    http://www.cppsamples.com/common-tasks/rule-of-five.html
    https://www.feabhas.com/sites/default/files/2016-06/Rule%20of%20the%20Big%20Five.pdf

Each of the Big Five (or Rule of Five) interfaces, plus the initializer list interface, are noted with the comment string “MA TODO” in LinkedList.h. Each of the interfaces should take no more than 8-10 lines of code (and a couple can be done in 2), especially if you read the rest of the class methods and ponder how to use them.

Included in this project is a test_main.cpp program. This program uses the Google C++ test framework called google test (gtest) and their object mocking library, gmock. The tests included are in the tests/ directory. If you want to run these tests locally, you’ll need to install the gtest and google mock packages. I’ll send out some more information about this, but it’s really straightforward to install in your system. These tests will be run by the GitHub CI when you check your code into Git. You should NOT have to edit the tests, but if you find a bug, please let me know and I’ll issue an update.

The Makefile has targets for ‘build’, ‘run’, ‘test’. It also can just do ‘starter-tests’ and ‘hw-tests’ to be more specific. To build your program, run ‘make build’ and to test it run ‘make test’. There's a 'make run' but all it does is print out an ASCII cat.

The final text file you upload to blackboard can be anything you like, but it should be a relatively small file. The upload to blackboard should be done once you’ve completed your work and pushed it to Git. The official turn in time will be the timestamp on your Git commit. The only things that files on Blackboard do is to let the graders know you’ve completed the assignment and you’d like it graded. The grader can then clone your repo and check your work.
Project dependencies:

Required (make build)

    g++
    make

For make test (make test)

    cmake
    google test (libgtest-dev)

Building HTML documentation (make documentation && make view-doc)

    doxygen
    graphviz

Running memory leak checks (make memcheck)

    valgrind
