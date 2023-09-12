//Copyright 2023, Bradley Peterson, Weber State University, All rights reserved.
#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::out_of_range;

//These two base classes help the assignment compile and run without any changes.  
//Dot not modify these.  You will instead override the methods in the derived classes below.
template <typename T>
class BaseStack {
public:
  BaseStack() {}                                   // These methods just contain filler code to help the code compile on the initial run. 
  BaseStack(const unsigned int size) {}            // In the derived classes below, you will be overriding these with your own versions. 
  BaseStack(const BaseStack& objToClone) = delete;          // Disables copy constructor
  BaseStack operator=(const BaseStack& objToClone) = delete; // Disables copy assignment
  unsigned int size() const { return 0; }                   // This method will be overriden in the derived class
  void push(const T& item) {}                               // This method will be overriden in the derived class
  T top() const { T temp{}; return temp; }                  // This method will be overriden in the derived class
  void pop() { }                                            // This method will be overriden in the derived class
  void popThirdFromTop() { }                                // This method will be overriden in the derived class
  void pushTwoUnderTop(const T& item) { }                   // This method will be overriden in the derived class
  T topThirdFromTop() const { T temp{}; return temp; }      // This method will be overriden in the derived class

protected:
  T* arr{ nullptr };
};

//**********************************
//Write your code below here
//**********************************
template <typename T>
class StackForCS2420 : public BaseStack<T> {
public:
  StackForCS2420(const unsigned int capacity);
  // TODO: Put your destructor and other methods here
  delete[] this->arr;
  unsigned int size = index;



private:
  // TODO: Put your two data members here (the arr is in the base class)
	int index{ 0 };
	unsigned int capacity{ 0 };


};

template <typename T>
StackForCS2420<T>::StackForCS2420(const unsigned int capacity) {
  // TODO: Write this
	this->arr = new T[ capacity ];
}

//TODO: Write all other methods
template <typename T>
void StackForCS2420<T>::push(const int T& value) {
	if (index == capactiy) {
		cout << "Error, the stack is full.";
		return;
	}
	else {
		this->arr[index] = value;
		index++
	}
}

template <typename T>
void StackForCS2420<T>::pop() {
	if (index > 0) {
		this->index--;
	}
}

template <typename T>
T StackForCS2420<T>::top() {
	if (index == 0) {
		throw std::out_of_range("stack is empty");
	}
	else
	return T;
}

template <typename T>
void StackForCS2420<T>::popThirdFromTop() {
	this->index[1] = index[2];
	this->index[0] = this->index[1];
	index--;
}

template <typename T>
void StackForCS2420<T>::pushTwoUnderTop() {
	int spot;
	cout << "Where in the array do you want to push back 2."
	cin << spot;
	this->index[spot].push_back(2);
}


template <typename T>
T StackForCS2420<T>::topThirdFromTop() {
	if (index < 3) {
		throw out_of_range("Erros, not enough members in stack");
	}
	
	return arr[index - 3];
}



//**********************************
//Write your code above here
//**********************************



