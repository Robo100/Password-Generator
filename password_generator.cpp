#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

int password_length() {
  int pwd_length;
  cout << "How long do you want the password to be? ";
  cin >> pwd_length;
  while (!cin || pwd_length <= 0 ) {
    cout << "Please enter a valid number above 0: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> pwd_length;
  }
  cout << "Your chosen password length is: ";
  return pwd_length;
}

int letters() {
  int require_letters;
  cout << "Do you want letters (0-no, 1-yes)? ";
  cin >> require_letters;
  while (!cin || require_letters < 0 || require_letters > 1) {
    cout << "Please enter 0 or 1: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> require_letters;
  }
  if (require_letters == 0) {
    cout << "You answered: NO!";
  } else if (require_letters == 1) {
    cout << "You answered: YES!";
  }
  return require_letters;
}

int uppercase_letters() {
  int require_uppercase_letters;
  cout << "Do you want uppercase letters (0-no, 1-yes)? ";
  cin >> require_uppercase_letters;
  while (!cin || require_uppercase_letters < 0 || require_uppercase_letters > 1) {
    cout << "Please enter 0 or 1: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> require_uppercase_letters;
  }
  if (require_uppercase_letters == 0) {
    cout << "You answered: NO!";
  } else if (require_uppercase_letters == 1) {
    cout << "You answered: YES!";
  }
  return require_uppercase_letters;
}

int uppercase_letters_length(int psswd_len) {
  int uppercase_length;
  cout << "How many characters of the password should be uppercase? ";
  cin >> uppercase_length;
  while (!cin || uppercase_length > psswd_len) {
    cout << "Please enter the number of uppercase letters you want in your password (not exceeding the total password length): ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> uppercase_length;
  }
  cout << "Your chosen number of uppercase letters: " << uppercase_length;
  return uppercase_length;
}

int lowercase_letters() {
  int require_lowercase_letters;
  cout << "Do you want lowercase letters (0-no, 1-yes)? ";
  cin >> require_lowercase_letters;
  while (!cin || require_lowercase_letters < 0 || require_lowercase_letters > 1) {
    cout << "Please enter 0 or 1: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> require_lowercase_letters;
  }
  if (require_lowercase_letters == 0) {
    cout << "You answered: NO!";
  } else if (require_lowercase_letters == 1) {
    cout << "You answered: YES!";
  }
  return require_lowercase_letters;
}

int lowercase_letters_length(int psswd_len) {
  int lowercase_length;
  cout << "How many characters of the password should be lowercase? ";
  cin >> lowercase_length;
  while (!cin || lowercase_length > psswd_len){
    cout << "Please enter the number of lowercase letters you want in your password (not exceeding the total password length): ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> lowercase_length;
  }
  cout << "Your chosen number of lowercase letters: " << lowercase_length;
  return lowercase_length;
}

int numbers() {
  int require_numbers;
  cout << "Do you want numbers (0-no, 1-yes)? ";
  cin >> require_numbers;
  while (!cin || require_numbers < 0 || require_numbers > 1) {
    cout << "Please enter 0 or 1: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> require_numbers;
  }
  if (require_numbers == 0) {
    cout << "You answered: NO!";
  } else if (require_numbers == 1) {
    cout << "You answered: YES!";
  }
  return require_numbers;
}

int numbers_length(int psswd_len) {
  int nums_length;
  cout << "How many characters of the password should be numbers? ";
  cin >> nums_length;
  while (!cin || nums_length > psswd_len) {
    cout << "Please enter the number of numbers you want in your password (not exceeding the total password length): ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> nums_length;
  }
  cout << "Your chosen length of numbers: " << nums_length;
  return nums_length;
}

int main() {
  while (true) {
    cout << "\n\n\nWelcome to the Random Password Generator!!!\n\n\n";

    srand(time(NULL));

    string random_password = "";
    
    int pw_length = password_length();
    cout << pw_length << "\n\n\n";

    int letter_characters = letters();
    if (letter_characters == 0) {
      for(int i = 0; i < pw_length; i++) {
        random_password += to_string(rand() % 10);
      }
      cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
    } else {
      cout << "\n\n\n";
      int ucase_letters = uppercase_letters();
      cout << "\n\n\n";
      if (ucase_letters == 0) {
        int lcase_letters = lowercase_letters();
        cout << "\n";
        if (lcase_letters == 0) {
          for(int i = 0; i < pw_length; i++) {
            random_password += to_string(rand() % 10);
          }
          cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
        } else {
          cout << "\n";
          int lcase_letters_length = lowercase_letters_length(pw_length);
          cout << "\n\n\n";
          int nums = numbers();
          if (nums == 0) {
            for(int i = 0; i < pw_length; i++) {
              random_password += 'a' + (rand() % 26);
            }
            cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
          } else {
            cout << "\n\n\n";
            int num_length = numbers_length(pw_length);
            cout << "\n";
            int diff = pw_length - lcase_letters_length;
            if (num_length > diff || num_length < diff) {
              cout << "\n\n\nERROR! The generated random password does not match your preferred password length. Please try again!\n\n\n";
            } else {
              for (int j = 0; j < lcase_letters_length; j++) {
                random_password += 'a' + (rand() % 26);
              }
              for (int k = 0; k < num_length; k++) {
                random_password += to_string(rand() % 10);
              }
              cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
            }
          }
        }
      } else {
        int ucase_letters_length = uppercase_letters_length(pw_length);
        for (int u = 0; u < ucase_letters_length; u++) {
          random_password += 'A' + (rand() % 26);
        }      
        cout << "\n\n\n";
        int lower_case = lowercase_letters();
        if (lower_case == 0) {
          cout << "\n\n\n";
          int numbs = numbers();
          if (numbs == 0) {
            if (ucase_letters_length < pw_length) {
              cout << "\n\n\nERROR! The generated random password is shorter than your preferred password length! Please try again!\n\n\n";
            } else {
              cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
            }
          } else {
            cout << "\n\n\n";
            int nm_len = numbers_length(pw_length);
            int difference = pw_length - ucase_letters_length;
            if (nm_len < difference || nm_len > difference) {
              cout << "\n\n\nERROR! The generated random password does not match your preferred password length. Please try again!\n\n\n";
            } else {
              for (int n = 0; n < nm_len; n++) {
                random_password += to_string(rand() % 10);
              }
              cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
            }
          }
        } else {
          cout << "\n\n\n";
          int case_difference = pw_length - ucase_letters_length;
          int lcase_len = lowercase_letters_length(pw_length);
          if (lcase_len > case_difference) {
            cout << "\n\n\nERROR! Your chosen number of lowercase letters exceeds the length of the password! Please try again!\n\n\n";
          } else {
            for (int l = 0; l < lcase_len; l++) {
              random_password += 'a' + (rand() % 26);
            }
            cout << "\n\n\n";
            int num = numbers();
            if (num == 0) {
              random_password = random_password;
              cout << "\n\n\nYour random password is: " << random_password << "\n\n\n";
            } else {
              cout << "\n\n\n";
              int nl = numbers_length(pw_length);
              for (int n = 0; n < nl; n++) {
                random_password += to_string(rand() % 10);
              }
              cout <<  "\n\n\nYour random password is: " << random_password << "\n\n\n";
            }
          }
        }
      }
    }

    int another_password;
    cout << "Would you like to create another password (0-no, 1-yes? ";
    cin >> another_password;
    while (!cin || another_password < 0 || another_password > 1) {
      cout << "Please enter 0 or 1: ";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> another_password;
    }
    if (another_password == 0) {
      cout << "\n\n\nExiting Program!!!\n";
      break;
    }
  }

  cout << "\n\n\n";

  return 0;
}