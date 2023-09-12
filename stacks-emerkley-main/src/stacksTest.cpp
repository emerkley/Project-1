#include "stacks.cpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::out_of_range;
using std::strcmp;
using std::ostringstream;
using std::stoi;
using std::string;

//This helps with testing, do not modify.
bool checkTest(int testNum, int& correct, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    correct++;
    cout << "Passed " << testNum << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
    cout << "The unit test checker is closing down the program now due to a failed test" << endl;
    exit(1);
    return false;
  }
}


//This helps with testing, comment it in when ready, but do not modify the code.
bool checkTest(int testNum, int& correct, string whatItShouldBe, string whatItIs) {

  if (whatItShouldBe == whatItIs) {
    correct++;
    cout << "Passed " << testNum << endl;
    return true;
  }
  else {
    if (whatItShouldBe == "") {
      cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been blank. " << endl;
    }
    else {
      cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
    }
    cout << "The unit test checker is closing down the program now due to a failed test" << endl;
    exit(1);
    return false;
  }
}

//This helps with testing, do not modify.
bool checkTestMemory(int testNum, int& correct, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    correct++;
    cout << "Passed " << testNum << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testNum << " *** " << endl << ".  ";
    cout << "You are manually managing " << whatItIs << " bytes in memory, but it should be " << whatItShouldBe << " bytes." << endl;
    cout << "The unit test checker is closing down the program now due to a failed test" << endl;
    exit(1);
    return false;
  }
}



//This helps with testing, do not modify.
bool testStackForCS2420() {

  int testNum = 1;
  int correct = 0;
  cout << "--------testStackForCS2420 Tests--------" << endl;

  // Last in, first out data structure (LIFO)

  string result;
  string caughtError;
  {
    StackForCS2420<int> stack(5);

    checkTest(testNum++, correct, 0, stack.size());

    stack.push(10);

    int data = stack.top();
    checkTest(testNum++, correct, 10, data);

    checkTest(testNum++, correct, 1, stack.size());

    stack.pop();

    stack.push(11);
    stack.push(12);
    stack.push(13);
    stack.push(14);
    stack.push(15);

    checkTest(testNum++, correct, 5, stack.size());


    checkTest(testNum++, correct, 15, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 14, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 13, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 12, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 11, stack.top());
    stack.pop();

    checkTest(testNum++, correct, 0, stack.size());

    // Now cover error handling
    try {
      result = stack.top();
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);

    // Try to pop an empty stack (this isn't really a test, but it shouldn't crash or affect upcoming tests)
    stack.pop();

    try {
      result = stack.top();
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);

    // Check currentSize
    checkTest(testNum++, correct, 0, stack.size());
    stack.push(12);
    stack.push(32);
    checkTest(testNum++, correct, 2, stack.size());

    // Now test filling it up
    stack.push(14);
    stack.push(53);
    stack.push(47);
    checkTest(testNum++, correct, 5, stack.size());

    // This should simply not let the 20 go in, as it is out of room.
    stack.push(20);

    // Peek at what is at the top
    checkTest(testNum++, correct, 47, stack.top());

    // Grab all the items again.
    checkTest(testNum++, correct, 47, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 53, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 14, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 32, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 12, stack.top());
    stack.pop();

    // Now do error handling again
    try {
      result = stack.top();
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);
  }
  {
    // Test some strings
    StackForCS2420<string> sstack(10);

    sstack.push("pencil");
    sstack.push("pen");
    sstack.push("marker");

    checkTest(testNum++, correct, 3, sstack.size());

    // Remove pen from the stack.
    string temp = sstack.top(); // Get marker
    sstack.pop();               // Remove marker
    sstack.pop();               // Remove pen
    sstack.push(temp);          // Push marker back in

    // See if it worked 
    checkTest(testNum++, correct, "marker", sstack.top());
    sstack.pop();
    checkTest(testNum++, correct, "pencil", sstack.top());
    sstack.pop();

    checkTest(testNum++, correct, 0, sstack.size());
  }

  return testNum - 1 == correct;

}


//This helps with testing, do not modify.
bool testStackAdditional() {

  // Last in, first out data structure (LIFO)
  int testNum = 1;
  int correct = 0;
  cout << "--------testStackAdditional Tests--------" << endl;

  int result;
  string caughtError;
  {
    // Now try popThirdFromTop()
    StackForCS2420<int> stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.popThirdFromTop();  // pops the 3
    checkTest(testNum++, correct, 5, stack.top());
    stack.pop();  // pops the 5
    stack.pop();  // pops the 4
    checkTest(testNum++, correct, 2, stack.top());
    stack.pop();  // pops the 2
    stack.pop();  // pops the 1

    // This shouldn't crash.
    stack.push(1);
    stack.push(2);
    stack.popThirdFromTop();  // There is no third item, so the method should not need to perform any action
    checkTest(testNum++, correct, 2, stack.top());  // 2 was still on the top

    // This also shouldn't crash.
    stack.pop();  // pops the 2
    stack.pop();  // pops the 1
    stack.popThirdFromTop();  // The stack is empty, so the method should not need to perform any action

    int result;
    try {
      result = stack.top();  // The top() method should either return something if it can, but here it can't, so it should throw an integer.
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);

  }
  {
    // Now try pushTwoUnderTop()
    StackForCS2420<int> stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pushTwoUnderTop(8); // the stack should now have 1 2 3 8 4 5
    checkTest(testNum++, correct, 5, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 4, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 8, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 3, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 2, stack.top());
    stack.pop();
    checkTest(testNum++, correct, 1, stack.top());
    try {
      result = stack.top();
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);

    // The stack is completely empty, however, this shouldn't crash
    stack.pushTwoUnderTop(10);  // The stack is empty, so the method should not need to perform any action
    try {
      result = stack.top();  // The top() method should either return something if it can, but here it can't, so it should throw an integer.
    }
    catch (std::out_of_range&) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);
  }
  {
    // Now try topThirdFromTop()
    StackForCS2420<int> stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    checkTest(testNum++, correct, 3, stack.topThirdFromTop());
    stack.pop();
    checkTest(testNum++, correct, 2, stack.topThirdFromTop());
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    // This shouldn't crash
    stack.push(1);
    string caught = "";
    try {
      result = stack.topThirdFromTop();  // The topThirdFromTop() method should either return something if it can, but here it can't, so it should throw an integer.
    }
    catch (std::out_of_range& ) {
      caughtError = "caught";
    }
    checkTest(testNum++, correct, "caught", caughtError);
  }
  
  return testNum - 1 == correct;

}

void pressAnyKeyToContinue() {
  cout << "Press enter to continue...";

  //Linux and Mac users with g++ don't need this
  //But everyone else will see this message.
  cin.get();

}

int main(int argc, char** argv) {

  int test = 0;
  int count = 0;

  if (argc > 1) {
    test = stoi(argv[1]);
  }
  switch (test) {
  case 0:
    if (testStackForCS2420()) count++;
    if (testStackAdditional()) count++;
    cout << "Passed " << count << " out of 2 tests";
    return count != 2;
  case 1:
    return !testStackForCS2420();
  case 2:
    return !testStackAdditional();
  }

}



