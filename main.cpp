#include <time.h>
#include<cstdlib>
#include<limits>
#include<string>
#include <iostream>
using namespace std;

class OutOfRange
{
private:
    int num;
public:
    OutOfRange(int number){ num = number;}
    string getMsg(){return to_string(num) + " is out of range";}
};

int GetNum();

int main() {
    char playMore = 'y';
    int guessingNum = 0;
    bool guessed = false;
    int secretNum;

    srand (time(NULL));
    cout<< "*** WELCOME TO CS301 GUESSING GAME ***"<<endl<<endl;

    while (playMore == 'y')
    {
        secretNum = rand()  % 30 + 1; // get a random number from 1 to 30
        guessingNum =0;
        guessed = false;
        cout<<"The game will randomly select a secret number from 1-30"<<endl;
        cout<<"You have maximum of 5 chances to guess the secret number"<<endl;
        cout<<"After each wrong guess, the game will tell you if your number is less or greater than the secret number"<<endl<<endl;
        cout<<"Let's start a new round"<<endl;

        for (int i = 0 ; i<5;i++)
        {
           // cout<<"Guess a number from 1-30:"<<endl;
           // cin>>guessingNum;
            guessingNum = GetNum();

            if(guessingNum == secretNum)
            {
                guessed = true;
                cout<<"Congratulation!!!\nYour answer is correct. ";//The secret number is "<< secretNum<<endl;
                break;
            }
            else
            {
                cout<<"Your answer is incorrect. ";
                if (guessingNum < secretNum)
                    cout<<"Your number is less than the secret number"<<endl;
                else
                    cout<<"Your number is greater than the secret number"<<endl;
            }
        }
        if (guessed == false)
            cout<<"Sorry, you are out of guess. ";

        cout<< "The secret number is " << secretNum<<endl<<endl;

        cout<<"Do you want to play another game? (y/n) "<<endl;
        cin>>playMore;
        playMore = tolower(playMore);
        cout<<endl;
    }

    cout<<"Good bye. See you next time ^-^"<<endl;
    return 0;
}

int GetNum()
{
    int guessingNum;
    bool requestingInput = true;

    while (requestingInput)
    {
        try
        {
            cout<<"Guess a number from 1-30:"<<endl;
            cin>>guessingNum;
            if (cin.fail()) //Validate data type
                throw "Invalid input";
            if (guessingNum < 1 || guessingNum > 30) //validate range of input
                throw OutOfRange(guessingNum);
            requestingInput = false;
        }
        //handle wrong type
        catch (const char* str) {
            cout << str << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //handle out of range number
        catch (OutOfRange invalid) {
            cout<<invalid.getMsg()<<endl;
        }
    }
    return guessingNum;

}
