

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

const int MAX_ARR_SIZE = 500;
bool populateArrays(std::string[], std::string[], int &);
void displayArrays(const std::string[], const std::string[], int);
void bubbleSort(std::string[], const int);
void swapElements(std::string &, std::string &);
int binarySearch(const std::string[], const int, std::string);

int main() {
  std::string countryCode[MAX_ARR_SIZE] = {""};
  std::string nameOfCountry[MAX_ARR_SIZE] = {""};
  int counter = -1;
  std::string cCode;
  int result;

  //outouts if file is not found
  if (!populateArrays(countryCode, nameOfCountry, counter)) {
    std::cout << "Error in finding file...\n";
    return EXIT_FAILURE;
  } else { //displays arrays if file is found
    
    displayArrays(countryCode, nameOfCountry, counter);
    bubbleSort(countryCode, counter);
    std::cout << "------------------------------------------\n";
    //prompts user for input and data
    do {
      std::cout << "Enter country code. Use only capital letters(type 'EXIT' to end program): ";
      getline(std::cin, cCode);
      result = binarySearch(countryCode, counter, cCode);
      if (result == -1) {
        std::cout << cCode << " is not in the data set\n";
      } else {
        std::cout << cCode << " exists as " << nameOfCountry[result] << std::endl;
      }
    } while(cCode != "EXIT");
  }
  return 0;
}
//searches for user input 
int binarySearch(const std::string arr[], const int arrSize,
                 std::string target) {
  int first = 0;
  int last = arrSize - 1;
  int middle;
  int targetPosition = -1;
  bool found = false;

  while (!found && (first <= last)) {
    middle = (first + last) / 2;
    if (arr[middle] == target) {
      found = true;
      targetPosition = middle;
    } else if (arr[middle] > target) {
      last = middle - 1;
    } else {
      first = middle + 1;
    }
  }
  return targetPosition;
}

//swaps elements in file
void swapElements(std::string &a, std::string &b) {
  std::string temp;
  temp = a;
  a = b;
  b = temp;
}

//sorts data properly
void bubbleSort(std::string arr[], const int arraySize) {
  for (int maxElement = arraySize - 1; maxElement > 0; maxElement--) {
    for (int i = 0; i < maxElement; i++) {
      if (arr[i] > arr[i + 1]) {
        swapElements(arr[i], arr[i + 1]);
      }
    }
  }
}
//displays countries and codes
void displayArrays(const std::string countryCode[],
                   const std::string nameOfCountry[], int arraySize) {
  std::cout << std::left << std::setw(5) << "Code" << std::setw(30) << "Country"
            << std::endl;
  for (int i = 0; i < arraySize; i++) {
    std::cout << std::left << std::setw(5) << countryCode[i] << std::setw(30)
              << nameOfCountry[i] << std::endl;
  }
}
//checks validity of file
bool populateArrays(std::string countryCode[], std::string nameOfCountry[],
                    int &numOfRecord) {
  std::ifstream readFile;
  bool fileValid = true;
  int index = 0;
  readFile.open("Countries.txt");
  if (!readFile) {
    fileValid = false;
  } else {
    while (!readFile.eof()) {
      getline(readFile, countryCode[index], '|');
      getline(readFile, nameOfCountry[index], '\n');
      index++;
    }
    numOfRecord = index;
  }
  readFile.close();
  return fileValid;
}