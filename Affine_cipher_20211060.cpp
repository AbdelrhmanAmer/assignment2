// FCAI – Programming 1 – 2022 - Assignment 2  
// Program Name:   Affine cipher .cpp 
// Program Description: this program for encrypt a messages.it encrypt the message using some equations.
// Last Modification Date: 19/3/2022 
// Author and ID and Group: Abdelrhman Amer Ali,  Id:20211060
// Teaching Assistant:  d/mohamed El Ramly 
// Purpose:encrypting messages


#include <iostream> // operator (<< and >>)
#include <string> // used functions --> (clear() , length(), end(), begin)
#include <algorithm> // used functions --> (transform() )

using namespace std;

// Creating my array of char
const char arr1[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

// this function to take choice (defesive input)
int getchoice()
{
    int nchoice;
    cout << "please Enter choice: ";
    cin >> nchoice;

    // check if the input is not good(invalid)
    while(cin.good() == false)
    {
        // report the problem
        cout << "ERROR, please Enter a valid input" << endl;

        // clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // set input again
        cout << "please Enter choice: ";
        cin >> nchoice;
    }

    return nchoice;
}
// this function to encrypt the message .
void encrypt()
{
    int x = 0;
    int newposition = 0;
    int a, b, c;
    string cipher = "", message = "";

    // taking the arrbitraries.
    cout << "Enter arbitrary (a, b , c) recommended(5, 8, 21): ";
    cin >> a >> b >> c;

    // if it's valid arbitraries, encrypt the message.
    if((a * c) % 26 == 1)
    {
        // to clear the the line from any extra spaces.
        if(cin.peek()== '\n')
            cin.ignore();

        // taking the message to cipher it
        cout << "Please Enter your message to cipher it: ";
        getline(cin , message);

        // first for loop for going to every letter in the message and work on it.
        for(int i = 0; i < message.length(); i++)
        {
            // check if it is an alphabetic .
            if(isalpha(message[i]))
            {
                //converting from lowercase to uppercase
                // because my array is upper case.
                message[i] = toupper(message[i]);

                // second for loop , we will use it to transport the letter i
                for(int j = 0; j < 26; j++)
                {
                    // find the position of letter i in the array.
                    if(message[i] == arr1[j])
                    {
                        // store this position in variable (x)
                        x = j;
                        // transform it to new position according this equation
                        newposition = ((a * x) + b) % 26;

                        // After taking new position for the letter i ,
                        // we will store it in cipher variable
                        cipher += arr1[newposition];
                    }
                }
            }else
            {   // if the letter isn't alphabetic, store it(don't encrypt it)
                cipher += message[i];
            }
        }// show ciphered message
        cout << "Ciphered message: " << cipher << endl;
    }else
    {   // IF the arbitraries is invalid .
        cout << "invalid arbitraries... " <<endl;
    }
    
}
// this function to decrypt the message .
void decrypt()
{
    int y = 0;
    int old_position = 0;
    int a, b, c;
    string decipher = "", message = "";

    // taking the arrbitraries.
    cout << "Enter arbitrary  (a, b , c) recommended(5, 8, 21): ";
    cin >> a >> b >> c;

    // if it's valid arbitraries, encrypt the message.
    if((a * c) % 26 == 1)
    {
        // to clear the the line from any extra spaces. 
        if(cin.peek()== '\n')
            cin.ignore();

        // taking the message to cipher it
        cout << "Please Enter your message to decipher it: ";
        getline(cin , message);

        // first for loop for going to every letter in the message and work on it.
        for(int i = 0; i < message.length(); i++)
        {   
            // check if it is an alphabetic
            if(isalpha(message[i]))
            {
                //converting from lowercase to uppercase
                // because my array is upper case.
                message[i] = toupper(message[i]);

                // second for loop , we will use it to transport the letter i
                for(int j = 0; j < 26; j++)
                {
                    // find the position of letter i in the array.
                    if(message[i] == arr1[j])
                    {
                        y = j;
                        old_position = (c * (y - b)) % 26;

                        // check if there is a negative number , to convert it to positive
                        if (old_position < 0)
                            old_position += 26;
                        
                        // After taking old position for the letter i ,
                        // we will store it in decipher variable
                        decipher += arr1[old_position];
                    }
                }
            }else
            {   // if the letter isn't alphabetic, store it(don't encrypt it)
                decipher += message[i];
            }
        }
        // this function to transform a uppercase string to lowercase.
        transform(decipher.begin(), decipher.end(), decipher.begin(), ::towlower);

        // then show it to user
        cout << "Deciphered message:  " <<  decipher << endl;
    }else
    {   // if the arbitraries is invalid.
        cout << "invalid arbitraries... " <<endl;
    }
    
}

int main()
{
    int nchoice;
    int a, b, c;
    bool isgoing = 1, isvalid = 1;

    while(isgoing){
        cout << endl;
        cout << "Ahlan ya user ya habibi." << endl;
        cout << "What do you like to do today" << endl;
        cout << "1 - Cipher a message" << endl;
        cout << "2 - Decipher a message" << endl;
        cout << "3 - End" << endl;

        // calling my function to get a correct input
        // that's kind of defensive programming
        nchoice = getchoice();

        
        if (nchoice == 1)
        {   // call encrypt function.
            encrypt() ; 
        }else if (nchoice == 2)
        {   // call decrypt function.
            decrypt();
        }
        // if the user want to quit .
        if (nchoice == 3){
            cout << "goodbye ya user ya hapipi o_o " << endl;
            // stop (while loop)
            isgoing = 0;
        }
    }
}