#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Function to read from a text file
void readFile(string fileName)
{
    ifstream file(fileName);
    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) 
        {
            cout << line << endl;
        }
        file.close();
    } else 
    {
        cout << "Error: Unable to open file " << fileName << " for reading.\n";
    }
}

// Function to write to a text file
void writeFile(string fileName)
{
    ofstream file;
    cout << "Choose operation: " << endl;
    cout << "1. Overwrite" << endl;
    cout << "2. Append" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) 
    {
        file.open(fileName);
    } 
    else if (choice == 2) 
    {
        file.open(fileName, ios::app);
    } 
    else 
    {
        cout << "Invalid choice" << endl;
        return;
    }
    if (file.is_open()) 
    {
        cout << "Enter text to write:\n";
        string text;
        cin.ignore(); // Ignore newline character left in the input buffer
        getline(cin, text); // Read entire line of text
        file << text << endl; // Write text to file
        cout << "Text has been written to " << fileName << "." << endl;
        file.close();
    } 
    else 
    {
        cout << "Error: Unable to open file " << fileName << " for writing." << endl;
    }
}

// Function to rename a file
void renameFile(string oldFileName, string newFileName)
{
    if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) 
    {
        cout << "Error: Failed to rename file " << oldFileName << " to " << newFileName << endl;
    } 
    else 
    {
        cout << "File " << oldFileName << " has been renamed to " << newFileName << "." << endl;
    }
}

// Function to copy contents of one file to another
void copyFile(string sourceFileName, string destFileName)
{
    ifstream sourceFile(sourceFileName); // Open source file for reading
    ofstream destFile(destFileName); // Open destination file for writing

    if (!sourceFile.is_open()) // Check if source file opened successfully
    {
        cout << "Error: Failed to open source file " << sourceFileName << endl;
        return;
    }

    if (!destFile.is_open()) // Check if destination file opened successfully
    {
        cout << "Error: Failed to create destination file " << destFileName << endl;
        return;
    }

    // Copy contents of source file to destination file
    destFile << sourceFile.rdbuf();

    if (!destFile) // Check if copying was successful
    {
        cout << "Error: Failed to copy data from " << sourceFileName << " to " << destFileName << endl;
    } 
    else 
    {
        cout << "File " << sourceFileName << " has been copied to " << destFileName << endl;
    }

    // Close files
    sourceFile.close();
    destFile.close();
}

// Function to delete a file
void deleteFile(string fileName)
{
    if (remove(fileName.c_str()) != 0) 
    {
        cout << "Error: Failed to delete file " << fileName << endl;
    } 
    else 
    {
        cout << "File " << fileName << " has been deleted." << endl;
    }
}

int main()
{
    int choice;
    string fileName, oldFileName, newFileName, destFileName;

    // Display menu and get user choice
    cout<<"-------------------------------------------------\n";
    cout<<"-------------------Menu--------------------------\n";
    cout<<"-------------------------------------------------\n";
    cout<<"1. Read from File\n2. Write to File\n3. Rename File\n4. Copy File\n5. Delete File\n6. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    while(choice!=6) // Loop until user chooses to exit
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter Filename: ";
                cin>>fileName;
                readFile(fileName);
                cout<<"File Read Successfully..."<<endl;
                break;
            case 2:
                cout<<"Enter Filename: ";
                cin>>fileName;
                writeFile(fileName);
                cout<<"File Written successfully..."<<endl;
                break;
            case 3:
                cout<<"Enter Filename: ";
                cin>>oldFileName;
                cout<<"Enter New Filename: ";
                cin>>newFileName;
                renameFile(oldFileName, newFileName);
                break;
            case 4:
                cout << "Enter Source Filename: ";
                cin >> fileName;
                cout << "Enter Destination Filename: ";
                cin >> destFileName;
                copyFile(fileName, destFileName);
                break;
            case 5:
                cout << "Enter Filename: ";
                cin >> fileName;
                deleteFile(fileName);
                break;
            default:
                cout<<"Enter Valid Choice!"<<endl;
                break;
        }
        cout<<"Enter Your Choice: ";
        cin>>choice;

    }
    cout<<"Exiting the Program..."<<endl;

    return 0;
}
