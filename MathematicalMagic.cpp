/*
Name            :   Ifiok Sunday Edemidiong
Date            :   11/7/2022
Description     :   An extra credit program that takes user input, tells user what individual numbers are in the input, and adds each number individially
*/
#include <cmath>
#include <iostream>

int main() {
  
  // variables and constants
  const int negativeToPositive = -1;
  double i = 0;
  int userInput, sum = 0, amountOfDigits = 0, digitCountMain = 0;
  int holdUserAmount1 = 0, holdUserLeftover1 = 0;
  int sumOfUser = 0;
  int counterForSum;
  int userSum;

//INPUT 
  // prompt user
  std::cout << "Enter an integer: ";
  std::cin >> userInput;
  std::cin.ignore();
  std::cout << std::endl;

  // converts negative numbers to positive
  if (userInput < 0) {
    userInput *= negativeToPositive;
  }
  // loop that catches incorrect data types
  while (std::cin.fail()) {
    std::cin.clear();
    // custom cin.ignore function to clear the buffer
    char FAILURE;
    while (std::cin.get(FAILURE) && FAILURE != '\n');
    std::cout << "Wrong data type!\nPlease enter whole (integer) numbers only: ";
    std::cin >> userInput;
    std::cin.ignore();
    std::cout << std::endl;
  }
  
//PROCESSING & OUTPUT COMBINED
  std::cout << "You entered: " << userInput << std::endl;
  // stores value of user input into a separate variable in order to keep the validity of original user input
  holdUserAmount1 = userInput;
  // calculates proper number to set 10 to a power of
  for (i = 0; holdUserAmount1 > 0; i++) {
    holdUserAmount1 /= 10;
    if (holdUserAmount1 == 0) {
      i--;
    }
  }
    // stores value in a variable to help regulate amount of the times the program is to run
    counterForSum = i;
    counterForSum++;
  // prepares power function and stores it in a variable
  int tenToAPower = pow(10.0, i);
  // counter to regulate how many times numbers are added
  int passThisAfter = 0;
  // resets variable to user's input to be manipulated while the original one stays the same
  holdUserAmount1 = userInput;
  std::cout << "Individual digits are: ";
  
  // loop that prints out individual numbers
  while (holdUserAmount1 > 0) {
    if (passThisAfter > 0 && i >= 0) {
      // decrements the nth power by 1 in order to divide the user input by the proper power of 10
      if (i > 0) {
        i--;
      }
      tenToAPower = pow(10.0, i);
    }
    // variable set to changing user input in order to keep the sequence consistent
    holdUserLeftover1 = holdUserAmount1;
    holdUserAmount1 %= tenToAPower;
    // quotient is passed on to different variable in order to store each quotient
    holdUserLeftover1 /= tenToAPower;
    userSum = holdUserLeftover1;
    passThisAfter++;
    // takes the current quotient and adds it to the past quotient
    if (holdUserAmount1 >= 0 && passThisAfter <= counterForSum) {
      sumOfUser += userSum;
    }
    // prints individual numbers received from the division problem
    std::cout << holdUserLeftover1 << ' ';
  }
  std::cout << "\nThe sum of the digits = " << sumOfUser << std::endl;

  return 0;
}