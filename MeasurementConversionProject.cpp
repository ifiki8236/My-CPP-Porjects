/*
Name            :   Ifiok Sunday Edemidiong
Date            :   12/05/2022
Description     :   A conversion program for miles, kilometers, centigrade, and
farenheit
*/

#include <iostream>

int displayMenuAndGetUserChoice();
double celsius2Fahren(int);
double far2Cels(int);
double miles2Km(int);
double km2Miles(int);
int checkUserDataIsValid();
void displayConversionResults(int, std::string, double, std::string);
const long double KILOS = 1.609344;
const long double MILES = 0.62137119;

int main() {
  int userChoice;
  int tempC;
  int tempF;
  int miles;
  int kilometers;

  do {

    userChoice = displayMenuAndGetUserChoice();
    switch (userChoice) {
    case 1:
      std::cout << "Enter temperature in degrees C: ";
      tempC = checkUserDataIsValid();

      displayConversionResults(tempC, "degrees Centigrade is",
                               celsius2Fahren(tempC), "degrees Fahrenheit");
      break;
    case 2:
      std::cout << "Enter temperature in degrees F: ";
      tempF = checkUserDataIsValid();

      displayConversionResults(tempF, "degrees Fahrenheit is", far2Cels(tempF),
                               "degrees Centigrade");
      break;
    case 3:
      std::cout << "Enter distance in miles: ";
      miles = checkUserDataIsValid();

      displayConversionResults(miles, "mph is", miles2Km(miles), "km/h");
      break;
    case 4:
      std::cout << "Enter distance in kilometers: ";
      kilometers = checkUserDataIsValid();

      displayConversionResults(kilometers, "km/h is", km2Miles(kilometers),
                               "mph");
      break;
    case 5:
      std::cout <<"Thanks for using COP 1334 Conversion Utilities!\n";
      break;
    // default:
    //   std::cout << "Only enter 1,2,3,4,5." << std::endl;
    }

  } while (userChoice != 5);
  return 0;
}
int displayMenuAndGetUserChoice() {
  int userChoice;
  std::cout << "\nWelcome to COP 1334 Conversion Utilities" << std::endl;
  std::cout << "Please choose from one of the following options(Note: Decimal numbers will round up in this program)" << std::endl;
  std::cout << "1. Celsius to Fahrenheit" << std::endl;
  std::cout << "2. Fahrenheit to Celsius" << std::endl;
  std::cout << "3. Miles to Kilometers" << std::endl;
  std::cout << "4. Kilometers to Miles" << std::endl;
  std::cout << "5. Exit" << std::endl;

  std::cout << "Your Choice: ";
  std::cin >> userChoice;

  while(std::cin.fail() || userChoice <= 0 || userChoice > 5) {
    std::cin.clear();
    char FAILURE;
    while (std::cin.get(FAILURE) && FAILURE != '\n');
      std::cout << "Your choices are only 1, 2, 3, 4, 5... Try again.\n";
      std::cout << "Your Choice: ";
      std::cin >> userChoice;
  }
  return userChoice;
}

double celsius2Fahren(int tempC) {
  double tempF;
  tempF = 9.0 / 5 * tempC + 32;
  return tempF;
}

double far2Cels(int tF) {
  double tC;
  tC = 5 / 9.0 * (tF - 32);
  return tC;
}

double miles2Km(int miles) { return miles * KILOS; }

double km2Miles(int kilometers) { return kilometers * MILES; }

void displayConversionResults(int originalVal, std::string msg1,
                              double calculatedVal, std::string msg2) {
  std::cout << originalVal << " " << msg1 << " " << calculatedVal << " " << msg2
            << std::endl;
}

int checkUserDataIsValid() {
  int userNum;
  std::cin >> userNum;
  while (std::cin.fail() || userNum < 0) {
    std::cin.clear();
    char FAILURE;
    while (std::cin.get(FAILURE) && FAILURE != '\n')
      ;
    std::cout << "That is not a valid entry. Try again: ";
    std::cin >> userNum;
  }
  return userNum;
}
