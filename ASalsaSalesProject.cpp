/*
Programmer Name    :   Ifiok Sunday Edemidiong
Date               :   12/7/2022
Description        :   A program that outputs data about salsa by using user
input
*/
#include <iomanip>
#include <iostream>
void getNumberOfJarz(const std::string[], int[], int);
void displayMenu_getUserChoice(int &);
void computeAllSales(const int[], int[], int[], int);
void displaySales(const std::string[], const int[], const int[], const int[],
                  int);
void displaySalsa(const std::string[], const int[], const int[], const int[],
                  int);
int getBestSalsa(int[], int, int &);
int getWorstSalsa(const int[], int, int &);
int getBestSales(int[], int, int &);
int getLeastSales(int[], int, int &);
void catchInvalidInput(int &);
const int MAX_SIZE = 5;

int main() {

  const std::string salsaNames[MAX_SIZE] = {"MILD", "MEDIUM", "SWEET", "HOT",
                                            "ZESTY"};
  const int prices[MAX_SIZE] = {1, 2, 5, 7, 4};
  int numJars[MAX_SIZE];
  int total[MAX_SIZE];
  int userChoice;
  int index;

  // user prompt
  std::cout << "Bienvenidos a Las Papas y Salsa de Miami!\nNote: This program "
               "will round all decimal numbers."
            << std::endl;
  getNumberOfJarz(salsaNames, numJars, MAX_SIZE);

  do {
    // cases that lists options and functions for each option
    displayMenu_getUserChoice(userChoice);
    catchInvalidInput(userChoice);
    computeAllSales(prices, numJars, total, MAX_SIZE);
    switch (userChoice) {
    case 1:

      displaySales(salsaNames, prices, numJars, total, MAX_SIZE);
      break;
    case 2:
      // computeAllSales(prices, numJars, total, MAX_SIZE);
      getBestSalsa(numJars, MAX_SIZE, index);
      displaySalsa(salsaNames, prices, numJars, total, index);
      break;
    case 3:
      // computeAllSales(prices, numJars, total, MAX_SIZE);
      getWorstSalsa(numJars, MAX_SIZE, index);
      displaySalsa(salsaNames, prices, numJars, total, index);
      break;
    case 4:
      // computeAllSales(prices, numJars, total, MAX_SIZE);
      getBestSales(total, MAX_SIZE, index);
      displaySalsa(salsaNames, prices, numJars, total, index);
      break;
    case 5:
      // computeAllSales(prices, numJars, total, MAX_SIZE);
      getLeastSales(total, MAX_SIZE, index);
      displaySalsa(salsaNames, prices, numJars, total, index);
      break;
    case 6:
      getNumberOfJarz(salsaNames, numJars, MAX_SIZE);
      break;
    case 7:
      std::cout << "Thank you for visiting Las Papas y Salsa de Miami! ";
      break;
    }
    // checks if loop must be exited
  } while (userChoice != 7);

  return 0;
}

// catches invalid data
void catchInvalidInput(int &userChoice) {
  char FAILURE;
  while (std::cin.fail() || userChoice < 1 || userChoice > 7) {
    std::cin.clear();
    while (std::cin.get(FAILURE) && FAILURE != '\n')
      ;
    std::cin.sync();
    std::cout << "Invalid input; try again...\n";
    std::cout << "Your choice: ";
    std::cin >> userChoice;
  }
}

// displays salsa info in corresponding to which option chosen
void displaySalsa(const std::string name[], const int price[], const int jars[],
                  const int total[], int index) {
  std::cout << std::setw(10) << "Salsa" << std::setw(10) << "Price"
            << std::setw(10) << "# of Jars" << std::setw(10) << "Sales\n";
  std::cout << std::setfill(' ') << std::setw(4) << " " << std::endl;
  std::cout << std::setfill('_') << std::setw(40) << " " << std::endl;
  std::cout << std::setfill(' ') << std::endl;

  std::cout << std::setw(10) << name[index] << std::setw(10) << price[index]
            << std::setw(10) << jars[index] << std::setw(7) << "$"
            << total[index] << std::endl;
}

// displays all info for all salsas
void displaySales(const std::string name[], const int price[], const int jars[],
                  const int total[], int arraySize) {

  std::cout << std::setw(10) << "Salsa" << std::setw(10) << "Price"
            << std::setw(10) << "# of Jars" << std::setw(10) << "Sales\n";
  std::cout << std::setfill(' ') << std::setw(4) << " " << std::endl;
  std::cout << std::setfill('_') << std::setw(40) << " " << std::endl;
  std::cout << std::setfill(' ') << std::endl;

  for (int i = 0; i < arraySize; i++) {
    std::cout << std::setw(10) << name[i] << std::setw(10) << price[i]
              << std::setw(10) << jars[i] << std::setw(7) << "$" << total[i]
              << std::endl;
  }
}

// function to grab the best salsa by most jars requested
int getBestSalsa(int salsaInfo[], int arraySize, int &index) {
  int largest = salsaInfo[0];
  for (int i = 0; i < arraySize; i++) {
    if (salsaInfo[i] > largest) {
      largest = salsaInfo[i];
      index = i;
    }
  }
  return index;
}

// function to grab salsa that made the most money
int getBestSales(int total[], int arraySize, int &index) {
  int mostSold = total[0];
  for (int i = 0; i < arraySize; i++) {
    if (total[i] > mostSold) {
      mostSold = total[i];
      index = i;
    }
  }
  return index;
}
// function to grab salsa that made the least money
int getLeastSales(int total[], int arraySize, int &index) {
  int leastSold = total[0];
  for (int i = 0; i < arraySize; i++) {
    if (total[i] < leastSold) {
      leastSold = total[i];
      index = i;
    }
  }
  return index;
}
// function to grab salsa based upon the least jars requested
int getWorstSalsa(const int salsaInfo[], int arraySize, int &index) {
  int smallest = salsaInfo[0];
  for (int i = 0; i < arraySize; i++) {
    if (salsaInfo[i] < smallest) {
      smallest = salsaInfo[i];
      index = i;
    }
  }
  return index;
}
// computes the sales of each salsa based on amount requested
void computeAllSales(const int prices[], int jars[], int total[],
                     int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    total[i] = jars[i] * prices[i];
  }
}

// display menu
void displayMenu_getUserChoice(int &userChoice) {
  std::cout << "Select from one of the following choices:\n";
  std::cout << "1. Display all salsa sales\n";
  std::cout << "2. Display the best selling salsas(# of jars sold)\n";
  std::cout << "3. Display the worst selling salsas(# of jars sold)\n";
  std::cout << "4. Display the most profitable sales ($ amt)\n";
  std::cout << "5. Display the least profitable sales ($ amt)\n";
  std::cout << "6. New salsa data\n";
  std::cout << "7. EXIT\n";
  std::cout << "Your Choice: ";
  std::cin >> userChoice;
}

// gets number of jars and checks if user inout is valid data type
void getNumberOfJarz(const std::string names[], int numJars[],
                     const int arraySize) {
  char FAILURE;
  for (int i = 0; i < arraySize; i++) {
    std::cout << "\nHow many jars of " << names[i]
              << " salsa would you like?: ";
    std::cin >> numJars[i];
    std::cout << std::endl;
    while (std::cin.fail() || numJars[i] < 0) {

      std::cin.clear();
      while (std::cin.get(FAILURE) && FAILURE != '\n')
        ;
      std::cin.sync();
      std::cout << "Invalid entry... Positive numbers only...\n";
      std::cout << "How many jars of " << names[i]
                << " salsa would you like?: ";
      std::cin >> numJars[i];
    }
    while (std::cin.get(FAILURE) && FAILURE != '\n')
      ;
    std::cin.clear();
    std::cin.sync();
  }
}
