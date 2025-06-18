#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function to read and display the contents of a text file
void readfile()
{
    fstream myfile;
    string filename;
    cout << "Enter the filename you want to read : ";
    cin >> filename;
    myfile.open(filename, ios::in); // Open file in read mode

    if (myfile.is_open())
    {
        cout << "This is the content of the file : " << endl;
        string line;
        while (getline(myfile, line)) // Read file line by line
        {
            cout << line << endl;
        }
        myfile.close();
        cout << "\n\n\n\nexiting now...." << endl;
        return;
    }
    else
    {
        cerr << "Error : File not found" << endl;
    }
}

// Function to overwrite the entire content of a file
void writefile()
{
    fstream myfile;
    string filename;
    cout << "Enter the filename you want to write : ";
    cin >> filename;
    myfile.open(filename, ios::out); // Open file in write mode (overwrite)

    if (myfile.is_open())
    {
        string text;
        cout << "Enter the content you want to overwrite with (Press Ctrl+Z+Enter to exit) : " << endl;
        getline(cin, text, '\0'); // Take multiline input until Ctrl+Z
        myfile << text;           // Write input to file
        myfile.close();
        cout << "\n\n\n\nexiting now...." << endl;
        cin.clear(); // Clear input stream in case Ctrl+Z causes issues
        return;
    }
    else
    {
        cerr << "Error : File not found" << endl;
    }
}

// Function to append content to the end of a file
void appendfile()
{
    fstream myfile;
    string filename;
    cout << "Enter the filename you want to append : ";
    cin >> filename;
    myfile.open(filename, ios::app); // Open file in append mode

    if (myfile.is_open())
    {
        string line;
        cout << "Enter the text you want to append (Press Ctrl+Z+Enter to exit) : " << endl;
        getline(cin, line, '\0'); // Take multiline input until Ctrl+Z
        myfile << line;           // Append to the file
        myfile.close();
        cout << "\n\n\n\nexiting now...." << endl;
        cin.clear();
        return;
    }
    else
    {
        cerr << "Error : File not found" << endl;
    }
}

// Main menu-driven function to interact with the user
int main()
{
    int num;
    while (true)
    {
        cout << "Heyy, this is the program to handle files :" << endl
             << "1. Read file " << endl
             << "2. Append text file " << endl
             << "3. Overwrite text in file " << endl
             << "4. Exit\n";
        cout << "Enter the operation digit (1-4) : ";
        cin >> num;

        switch (num)
        {
        case 1:
        {
            readfile();
            break;
        }
        case 2:
        {
            appendfile();
            break;
        }
        case 3:
        {
            writefile();
            break;
        }
        case 4:
        {
            return 0; // Exit program
        }
        default:
        {
            cout << "Enter appropriate number" << endl;
        }
        }
    }
    return 0;
}
