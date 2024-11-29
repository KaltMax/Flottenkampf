#include "VisualsAndUtility.h"

VisualsAndUtility::VisualsAndUtility() {
    //ctor
}

VisualsAndUtility::~VisualsAndUtility() {
    //dtor
}

void VisualsAndUtility::printTitle() {
cout << "______ _       _   _             _                          __ \n"
                     "|  ___| |     | | | |           | |                        / _|\n"
                     "| |_  | | ___ | |_| |_ ___ _ __ | | ____ _ _ __ ___  _ __ | |_ \n"
                     "|  _| | |/ _ \\| __| __/ _ \\ '_ \\| |/ / _` | '_ ` _ \\| '_ \\|  _|\n"
                     "| |   | | (_) | |_| ||  __/ | | |   < (_| | | | | | | |_) | |  \n"
                     "\\_|   |_|\\___/ \\__|\\__\\___|_| |_|_|\\_\\__,_|_| |_| |_| .__/|_|  \n"
                     "                                                    | |        \n"
                     "                                                    |_|        \n";
}

void VisualsAndUtility::clearScreen(){
    #ifdef _WIN32
            system("cls");
    #else
            // Assume POSIX
            system("clear");
    #endif
}

void VisualsAndUtility::enterToContinue() {
    cout << "\nPress ENTER to continue!" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Warten auf die Eingabetaste
}

void VisualsAndUtility::enterToContinue2() {
    cout << "\nPress ENTER to continue!" << endl;
    cin.get(); // Warten auf die Eingabetaste
}
