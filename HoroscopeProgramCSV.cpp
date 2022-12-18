/*
Name            :   Ifiok Sunday Edemidiong
Date            :   11/23/2022
Description     :   A horoscope program that accesses CSV files only and allows a user to
write to it
*/
#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
  std::string fileName;
  char ch, goAgain;
  int i = 0;
  int dateOfBirth = 0, yearOfBirth = 0, monthOfBirth = 0, userChoice = 0,
      numOfFiles;
  int aries = 0, taurus = 0, gemini = 0, cancer = 0, leo = 0, virgo = 0,
      libra = 0, scorpio = 0, sag = 0, cap = 0, aqua = 0, pisces = 0;

  std::cout
      << "Welcome to COP 1334 Horoscope App\n"
         "Please choose one of the following menu options(enter 1, 2 or 3)\n"
         "1. Process all records from a file\n"
         "2. Process specific number of records\n"
         "3. Enter data into a file\n";
  std::cout << "Your choice: ";
  std::cin >> userChoice;
  // catches incorrect data
  while (userChoice < 1 || userChoice > 3 || std::cin.fail()) {
    std::cin.clear();
    // custom cin.ignore function to clear the buffer
    char FAILURE;
    while (std::cin.get(FAILURE) && FAILURE != '\n')
      ;
    std::cout << "Nice try trying to break my program.\n";
    std::cout << "Your choices are only 1, 2 or 3. Choose an option:\n";
    std::cout << "1. Process all records from a file\n"
                 "2. Process specific number of records\n"
                 "3. Enter data into a file\n";
    std::cout << "Your choice: ";
    std::cin >> userChoice;
  }

  std::ifstream readFile;
  std::ofstream writeFile;

  // option 1
  if (userChoice == 1) {
    while (userChoice == 1 || goAgain == 'y' || goAgain == 'Y') {
      userChoice = 0;
      std::cout << "Enter your file name: ";
      std::cin >> fileName;
      readFile.open(fileName);
      // checks if file is existent
      if (!readFile) {
        std::cerr << "File unable to be located. Restart the program...\n";
        return (EXIT_FAILURE);
      }
      std::cout << std::setw(12) << std::left << "\nHoroscope Sign"
                << std::setw(9) << std::right << "Count\n";
      std::cout << "------------------------" << std::endl;

      while (!readFile.eof()) {
        i++;
        readFile >> dateOfBirth;
        // std::cout<<dateOfBirth;
        readFile >> ch;
        // std::cout<<ch;
        readFile >> monthOfBirth;
        // std::cout<<monthOfBirth;
        readFile >> ch;
        //  std::cout<<ch;
        readFile >> yearOfBirth;
        // std::cout<<yearOfBirth<<std::endl;

        // counts records and which one is in which sign
        if (monthOfBirth == 3 && dateOfBirth >= 21 ||
            monthOfBirth == 4 && dateOfBirth <= 19) {
          aries++;
        } else if (monthOfBirth == 4 && dateOfBirth >= 20 ||
                   monthOfBirth == 5 && dateOfBirth <= 20) {
          taurus++;
        } else if (monthOfBirth == 5 && dateOfBirth >= 21 ||
                   monthOfBirth == 6 && dateOfBirth <= 20) {
          gemini++;
        } else if (monthOfBirth == 6 && dateOfBirth >= 21 ||
                   monthOfBirth == 7 && dateOfBirth <= 22) {
          cancer++;
        } else if (monthOfBirth == 7 && dateOfBirth >= 23 ||
                   monthOfBirth == 8 && dateOfBirth <= 22) {
          leo++;
        } else if (monthOfBirth == 8 && dateOfBirth >= 23 ||
                   monthOfBirth == 9 && dateOfBirth <= 22) {
          virgo++;
        } else if (monthOfBirth == 9 && dateOfBirth >= 23 ||
                   monthOfBirth == 10 && dateOfBirth <= 22) {
          libra++;
        } else if (monthOfBirth == 10 && dateOfBirth >= 23 ||
                   monthOfBirth == 11 && dateOfBirth <= 21) {
          scorpio++;
        } else if (monthOfBirth == 11 && dateOfBirth >= 22 ||
                   monthOfBirth == 12 && dateOfBirth <= 21) {
          sag++;
        } else if (monthOfBirth == 12 && dateOfBirth >= 22 ||
                   monthOfBirth == 1 && dateOfBirth <= 19) {
          cap++;
        } else if (monthOfBirth == 1 && dateOfBirth >= 20 ||
                   monthOfBirth == 2 && dateOfBirth <= 18) {
          aqua++;
        } else if (monthOfBirth == 2 && dateOfBirth >= 19 ||
                   monthOfBirth == 3 && dateOfBirth <= 20) {
          pisces++;
        }
      }
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Aries: " << std::setfill(' ') << std::setw(8) << std::right
                << aries << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Taurus: " << std::setw(8) << std::right << taurus
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Gemini: " << std::setw(8) << std::right << gemini
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Cancer: " << std::setw(8) << std::right << cancer
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Leo: " << std::setw(8) << std::right << leo << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Virgo: " << std::setw(8) << std::right << virgo
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Libra:  " << std::setw(8) << std::right << libra
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Scorpio: " << std::setw(8) << std::right << scorpio
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Saggitarius: " << std::setw(8) << std::right << sag
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Capricorn: " << std::setw(8) << std::right << cap
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Aquarius: " << std::setw(8) << std::right << aqua
                << std::endl;
      std::cout << std::setfill(' ') << std::setw(12) << std::left
                << "Pisces: " << std::setw(8) << std::right << pisces
                << std::endl;
      // std::cout << "Iterations: " << i;
      readFile.close();
      std::cout
          << "\nProcess a different file(recently opened files cannot be "
             "reopened at the moment)?('y' to continue, or press any other "
             "letter to end: ";
      std::cin >> goAgain;
    }
    std::cout << "\nThanks for visiting my horoscope! Goodbye! Run the program "
                 "again if you want to view more options.";
  }

  // option 2
  else if (userChoice == 2) {
    std::cout
        << "*******************\nNOTE: If the number entered is higher than "
           "the total amount of records in the file then only the max amount "
           "of records in the file wil be shown.\n*******************";
    while (goAgain == 'y' || goAgain == 'Y' || userChoice == 2) {
      userChoice = 0;
      std::cout << "\nEnter your file name: ";
      std::cin >> fileName;
      readFile.open(fileName);
      // checks fot file validity
      if (!readFile) {
        std::cerr << "File unable to be located. Restart the program...\n";
        return (EXIT_FAILURE);
      }

      std::cout << "How many records do you want to see?: ";
      std::cin >> numOfFiles;
      // checks validity of file amount
      while (numOfFiles < 1 || std::cin.fail()) {
        std::cin.clear();
        // custom cin.ignore function to clear the buffer
        char FAILURE;
        while (std::cin.get(FAILURE) && FAILURE != '\n')
          ;
        std::cout << "Invalid Entry.\n";
        std::cout << "How many files you want to see?: ";
        std::cin >> numOfFiles;
      }

      std::cout << std::setw(7) << std::left << "\nBorn On" << std::setw(22)
                << std::right << "Horoscope Sign\n"
                << std::left << "-----------------------------" << std::endl;
      while (i < numOfFiles && !readFile.eof()) {
        i++;
        readFile >> dateOfBirth;
        // std::cout<<dateOfBirth;
        readFile >> ch;
        // std::cout<<ch;
        readFile >> monthOfBirth;
        // std::cout<<monthOfBirth;
        readFile >> ch;
        //  std::cout<<ch;
        readFile >> yearOfBirth;
        // std::cout<<yearOfBirth<<std::endl;

        // prints out data
        std::cout << std::setw(3) << std::right << monthOfBirth << "/"
                  << dateOfBirth;

        if (monthOfBirth == 3 && dateOfBirth >= 21 ||
            monthOfBirth == 4 && dateOfBirth <= 19) {
          std::cout << std::setw(20) << std::right << "Aries" << std::endl;
        } else if (monthOfBirth == 4 && dateOfBirth >= 20 ||
                   monthOfBirth == 5 && dateOfBirth <= 20) {
          std::cout << std::setw(20) << std::right << "Taurus" << std::endl;
        } else if (monthOfBirth == 5 && dateOfBirth >= 21 ||
                   monthOfBirth == 6 && dateOfBirth <= 20) {
          std::cout << std::setw(20) << std::right << "Gemini" << std::endl;
        } else if (monthOfBirth == 6 && dateOfBirth >= 21 ||
                   monthOfBirth == 7 && dateOfBirth <= 22) {
          std::cout << std::setw(20) << std::right << "Cancer" << std::endl;
        } else if (monthOfBirth == 7 && dateOfBirth >= 23 ||
                   monthOfBirth == 8 && dateOfBirth <= 22) {
          std::cout << std::setw(20) << std::right << "Leo" << std::endl;
        } else if (monthOfBirth == 8 && dateOfBirth >= 23 ||
                   monthOfBirth == 9 && dateOfBirth <= 22) {
          std::cout << std::setw(20) << std::right << "Virgo" << std::endl;
        } else if (monthOfBirth == 9 && dateOfBirth >= 23 ||
                   monthOfBirth == 10 && dateOfBirth <= 22) {
          std::cout << std::setw(20) << std::right << "Libra" << std::endl;
        } else if (monthOfBirth == 10 && dateOfBirth >= 23 ||
                   monthOfBirth == 11 && dateOfBirth <= 21) {
          std::cout << std::setw(20) << std::right << "Scorpio" << std::endl;
        } else if (monthOfBirth == 11 && dateOfBirth >= 22 ||
                   monthOfBirth == 12 && dateOfBirth <= 21) {
          std::cout << std::setw(20) << std::right << "Saggitarius"
                    << std::endl;
        } else if (monthOfBirth == 12 && dateOfBirth >= 22 ||
                   monthOfBirth == 1 && dateOfBirth <= 19) {
          std::cout << std::setw(20) << std::right << "Capricorn" << std::endl;
        } else if (monthOfBirth == 1 && dateOfBirth >= 20 ||
                   monthOfBirth == 2 && dateOfBirth <= 18) {
          std::cout << std::setw(20) << std::right << "Aquarius" << std::endl;
        } else if (monthOfBirth == 2 && dateOfBirth >= 19 ||
                   monthOfBirth == 3 && dateOfBirth <= 20) {
          std::cout << std::setw(20) << std::right << "Pisces" << std::endl;
        }
      }
      readFile.close();
      std::cout
          << "\nProcess a different file(recently opened files cannot be "
             "reopened at the moment)?('y' to continue, or press any other "
             "letter to end: ";
      std::cin >> goAgain;
    }

    std::cout << "\nThanks for visiting and using my horoscope! Goodbye! Run "
                 "the program again if you want to view more options.";
  }

  // option 3
  else if (userChoice == 3) {

    std::cout << "Enter a file name: ";
    std::cin >> fileName;
    writeFile.open(fileName, std::ios::app);
    if (!writeFile) {
      std::cerr << "I don't think I was able to create that file... Restart "
                   "the program...";
      exit(EXIT_FAILURE);
    }
    // loop to allow user to write to an existent file or new file
    do {
      std::cout << "Enter the month of birth: ";
      std::cin >> monthOfBirth;

      while (monthOfBirth < 1 || monthOfBirth > 12 || std::cin.fail()) {
        std::cin.clear();
        // custom cin.ignore function to clear the buffer
        char FAILURE;
        while (std::cin.get(FAILURE) && FAILURE != '\n')
          ;
        std::cout << "Months are between 1-12; try again.\n";
        std::cout << "Enter the month of birth: ";
        std::cin >> monthOfBirth;
      }
      writeFile << "\n" << monthOfBirth << ",";

      std::cout << "Enter the day of birth: ";
      std::cin >> dateOfBirth;
      while (dateOfBirth < 1 || monthOfBirth > 31 ||
             monthOfBirth == 2 && dateOfBirth > 29 ||
             monthOfBirth == 4 && dateOfBirth > 30 ||
             monthOfBirth == 6 && dateOfBirth > 30 ||
             monthOfBirth == 9 && dateOfBirth > 30 ||
             monthOfBirth == 11 && dateOfBirth > 30 || std::cin.fail()) {
        std::cin.clear();
        // custom cin.ignore function to clear the buffer
        char FAILURE;
        while (std::cin.get(FAILURE) && FAILURE != '\n')
          ;
        std::cout << "Remember, acceptable dates are between 1-31, February "
                     "has only 29 days, and April, June, Spetember, and "
                     "November only have 30 days... try again.\n";
        std::cout << "Enter the date of birth: ";
        std::cin >> dateOfBirth;
      }

      writeFile << dateOfBirth << ",";
      writeFile << "2022";
      std::cout << "Want to enter more data(recently opened files cannot be "
                   "reopened at the moment)?(press 'y' to continue) If not, "
                   "press any other letter.";
      std::cin >> goAgain;

    } while (goAgain == 'Y' || goAgain == 'y');
    writeFile.close();
    std::cout << "Thanks for using the horoscope! If you want to try "
                 "other options, run the program again!";
  }
  return 0;
}