#include <iostream>
#include<iomanip>
#include <conio.h>
#include <cstdlib> 
using namespace std;
void clearScreen()
{
    system("cls"); 
}
int playerOne, playerTwo;
//base class - character
class Warrior;
class Mage;
class Rogue;
class Character
{
    
    string name;
    int level;
    int health_points;
    public:

    Character(string n, int l)
    {
        name = n;
        level = l;
        health_points = 3;
    }

    void displayInfo()
    {
        cout<<"\nTHE NAME OF YOUR CHARACTER:  "<<name;
        cout<<"\nTHE LEVEL OF CHARACTER IS:  "<<level;
        cout<<"\nTHE INITIAL HEALTH POINTS OF CHARACTER ARE:  "<<health_points;
        
    }

    friend void battle(Warrior& , Mage&);
    friend void battle(Warrior&, Rogue&);
    friend void battle(Rogue&, Mage&);

};

class Warrior : public Character
{
    int strength;
    int armour;
    public:
    Warrior(string n, int l, int s, int a) : Character(n, l)
    {
        strength = s;
        armour = a;
    }
    friend void battle(Warrior& , Mage&);
    friend void battle(Warrior&, Rogue&);
};

class Mage : public Character
{
    
    int intelligence;
    int mana;
    public:
    Mage(string n, int l, int i, int m) : Character(n, l)
    {
        intelligence = i;
        mana = m;
    }
    friend void battle(Warrior& , Mage&);
    friend void battle(Rogue&, Mage&);

};

class Rogue : public Character
{
    int agility;
    int evasion;
    public:
    Rogue(string n, int l,  int g, int e) : Character(n, l)
    {
        agility = g;
        evasion = e;

    }
    friend void battle(Warrior&, Rogue&);
    friend void battle(Rogue&, Mage&);

};

void battle(Warrior& p1, Mage& p2)
{
    clearScreen(); 
    cout<<"\n-----------BATTLE BEGINS----------"<<endl;
    cout<<"----WARRIOR-----VS------MAGE------"<<endl;
    cout<<"S "<<p1.strength<<setw(7)<<"I "<<p2.intelligence<<endl;
    cout<<"A "<<p1.armour<<setw(7)<<"M "<<p2.mana<<endl;
    cout<<"PRESSING 'S' WILL HELP THE WARRIOR USE THEIR STRENGTH\nPRESSING 'A' WILL HELP THE WARRIOR USE THEIR ARMOUR\nPRESSING 'I' WILL HELP THE MAGE USE THEIR INTELLIGENCE\nPRESSING 'M' WILL HELP THE MAGE USE THEIR MANA\n";
    cout<<"Starting..."<<endl;
    while(p1.health_points !=0 && p2.health_points !=0)
    {
            if(_kbhit()){
                char ch;
                cout<<"\nINPUT MOVE:  ";ch = _getch();
                clearScreen();
                if(ch == 'S' || ch == 's')
                {
                    cout<<"WARRIOR GOES IN FOR THE ATTACK..."<<endl;
                    p1.strength = p1.strength - 300;
                    p2.intelligence = p2.intelligence - 100;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                    
                }
                else if(ch == 'M' || ch == 'm')
                {
                    cout<<"MAGE CHOOSES TO FIGHT BACK HASTILIY..."<<endl;
                    p2.mana = p2.mana - 300;
                    p1.armour = p1.armour - 200;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'A' || ch == 'a')
                {
                    cout<<"WARRIOR SHIELDS..."<<endl;
                    p1.armour = p1.armour - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'I' || ch =='i')
                {
                    cout<<"MAGE EVADES DAMAGE CLEVERLY..."<<endl;
                    p2.intelligence = p2.intelligence - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                if(p1.strength <= 0 || p1.armour <= 0 )
                {
                    p1.health_points--;
                    p2.level++;
                    cout<<"\nWARRIOR LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.strength = 1000;
                    p1.armour = 1000;
                    p2.intelligence = 800;
                    p2.mana = 1200;
                    cout<<"\nMAGE LEVEL UP++";
                }
                else if(p2.intelligence <= 0 || p2.mana <= 0)
                {
                    p2.health_points--;
                    p1.level++;
                    cout<<"\nMAGE LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.strength = 1000;
                    p1.armour = 1000;
                    p2.intelligence = 800;
                    p2.mana = 1200;
                    cout<<"\nWARRIOR LEVEL UP++";
                }
            }    
        
    }

    if(p1.health_points == 0)
    {
        cout<<"\nMAGE WINS THIS ROUND"<<endl;
        p2.displayInfo();
    }
    else
    {
        cout<<"\nWARRIOR WINS THIS ROUND"<<endl;
        p1.displayInfo();
    }
}

void battle(Warrior& p1, Rogue& p2)
{
    clearScreen();
    cout<<"\n-----------BATTLE BEGINS----------"<<endl;
    cout<<"----WARRIOR-----VS------ROGUE------"<<endl;
    cout<<"S "<<p1.strength<<setw(7)<<"G "<<p2.agility<<endl;
    cout<<"A "<<p1.armour<<setw(7)<<"E "<<p2.evasion<<endl;
    cout<<"PRESSING 'S' WILL HELP THE WARRIOR USE THEIR STRENGTH\nPRESSING 'A' WILL HELP THE WARRIOR USE THEIR ARMOUR\nPRESSING 'G' WILL HELP THE ROGUE USE THEIR AGILITY\nPRESSING 'E' WILL HELP THE ROGUE USE THEIR EVASION\n";
    cout<<"Starting..."<<endl;
    while(p1.health_points!=0 && p2.health_points!=0)
    {
                if(_kbhit()){
                char ch;
                cout<<"\nINPUT MOVE:  ";ch = _getch();
                clearScreen();
                if(ch == 'S' || ch == 's')
                {
                    cout<<"WARRIOR GOES IN FOR THE ATTACK..."<<endl;
                    p1.strength = p1.strength - 300;
                    p2.evasion = p2.evasion - 150;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"G "<<p2.agility<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"E "<<p2.evasion<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                    
                }
                else if(ch == 'G' || ch == 'g')
                {
                    cout<<"ROGUE TAKES CONTROL OF THE FIGHT..."<<endl;
                    p2.agility = p2.agility - 300;
                    p1.armour  = p1.armour - 200;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"G "<<p2.agility<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"E "<<p2.evasion<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'A' || ch == 'a')
                {
                    cout<<"WARRIOR SHIELDS..."<<endl;
                    p1.armour = p1.armour - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"G "<<p2.agility<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"E "<<p2.evasion<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'E' || ch =='e')
                {
                    cout<<"ROGUE EVADES DAMAGE CLEVERLY..."<<endl;
                    p2.evasion = p2.evasion - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"S "<<p1.strength<<setw(7)<<"G "<<p2.agility<<endl;
                    cout<<"A "<<p1.armour<<setw(7)<<"E "<<p2.evasion<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                if(p1.strength <= 0 || p1.armour <= 0 )
                {
                    p1.health_points--;
                    p2.level++;
                    cout<<"\nWARRIOR LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.strength = 1000;
                    p1.armour = 1000;
                    p2.agility = 900;
                    p2.evasion = 1150;
                    cout<<"\nROGUE LEVEL UP++";
                }
                else if(p2.evasion <= 0 || p2.agility <= 0)
                {

                    p2.health_points--;
                    p1.level++;
                    cout<<"\nROGUE LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.strength = 1000;
                    p1.armour = 1000;
                    p2.agility = 900;
                    p2.evasion = 1150;
                    cout<<"\nWARRIOR LEVEL UP++";
                }

    }   }

    if(p1.health_points == 0)
    {
        cout<<"\nROGUE WINS THIS ROUND"<<endl;
        p2.displayInfo();
    }
    else
    {
        cout<<"\nWARRIOR WINS THIS ROUND"<<endl;
        p1.displayInfo();
    }
}
void battle(Rogue& p1, Mage& p2)
{
    clearScreen();
    cout<<"\n-----------BATTLE BEGINS----------"<<endl;
    cout<<"----MAGE-----VS------ROGUE------"<<endl;
    cout<<"G "<<p1.agility<<setw(7)<<"I "<<p2.intelligence<<endl;
    cout<<"E "<<p1.evasion<<setw(7)<<"M "<<p2.mana<<endl;
    cout<<"PRESSING 'G' WILL HELP THE ROGUE USE THEIR AGILITY\nPRESSING 'E' WILL HELP THE ROGUE USE THEIR EVASION\nPRESSING 'I' WILL HELP THE MAGE USE THEIR INTELLIGENCE\nPRESSING 'M' WILL HELP THE MAGE USE THEIR MANA\n";
    cout<<"Starting..."<<endl;
    while(p1.health_points!=0 && p2.health_points!=0)
    {
                if(_kbhit()){
                char ch;
                cout<<"\nINPUT MOVE:  ";ch = _getch();
                clearScreen();
                if(ch == 'M' || ch == 'm')
                {
                    cout<<"MAGE CHOOSES TO ATTACK..."<<endl;
                    p2.mana = p2.mana - 300;
                    p1.evasion = p1.evasion - 150;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"G "<<p1.agility<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"E "<<p1.evasion<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'G' || ch == 'g')
                {
                    cout<<"ROGUE TAKES CONTROL OF THE FIGHT..."<<endl;
                    p1.agility = p1.agility - 300;
                    p2.intelligence  = p2.intelligence - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"G "<<p1.agility<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"E "<<p1.evasion<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'I' || ch =='i')
                {
                    cout<<"MAGE EVADES DAMAGE CLEVERLY..."<<endl;
                    p2.intelligence = p2.intelligence - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"G "<<p1.agility<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"E "<<p1.evasion<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                else if(ch == 'E' || ch =='e')
                {
                    cout<<"ROGUE EVADES DAMAGE CLEVERLY..."<<endl;
                    p1.evasion = p1.evasion - 300;
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"G "<<p1.agility<<setw(7)<<"I "<<p2.intelligence<<endl;
                    cout<<"E "<<p1.evasion<<setw(7)<<"M "<<p2.mana<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
                if(p1.agility <= 0 || p1.evasion <= 0 )
                {
                    p1.health_points--;
                    p2.level++;
                    cout<<"\nROGUE LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.agility = 900;
                    p1.evasion = 1150;
                    p2.intelligence = 800;
                    p2.mana = 1200;
                    cout<<"\nMAGE LEVEL UP++";
                }
                else if(p2.intelligence <= 0 || p2.mana <= 0)
                {

                    p2.health_points--;
                    p1.level++;
                    cout<<"\nMAGE LOSES HEALTH --- STATS REPLENISHED\n";
                    p1.agility = 900;
                    p1.evasion = 1150;
                    p2.intelligence = 800;
                    p2.mana = 1200;
                    cout<<"\nROGUE LEVEL UP++";
                }}

    }

    if(p1.health_points == 0)
    {
        cout<<"\nMAGE WINS THIS ROUND"<<endl;
        p2.displayInfo();
    }
    else
    {
        cout<<"\nROGUE WINS THIS ROUND"<<endl;
        p1.displayInfo();
    }
}

 void displayRules()
    {
        char choice;
        cout<<"\nTO ACCESS THE RULEBOOK, PRESS 6\n";
        cin>>choice;
        if(choice == '6')
        {
            cout<<"Rules of the Realm:\n1. Character Selection: Choose your hero wisely from the noble Warrior, mystical Mage, or cunning Rogue.\n2. Commencement of Battle: Press 'T' to embark upon the clash of champions.\n3. Battle Tactics:\n- Engage in turn-based combat, where each move affects the fate of the realm.\n- Utilize attacks, defenses, and unique abilities tailored to your chosen class.\n- Strategize to exploit your opponent's weaknesses while protecting your own strengths.\n4. Outcome:\n- Vanquish your foe by depleting their health points to zero.\n- Claim victory and ascend in power as your character levels up with each triumph.\n'AS THE ECHOES OF BATTLE FADE, THE VICTOR EMERGES, THEIR PATH ILLUMINATED BY THE GLOW OF TRIUMPH'.\n";
        }
    }

void gameMain()
{
    string name_one, name_two;
    
    cout<<"-------------------------------------"<<endl;
    cout<<"WELCOME TO THE ROLE-PLAYING GAME MENU"<<endl;
    cout<<"-------------------------------------"<<endl;
    displayRules();
    cout<<"  PLAYER 1 SELECT YOUR CHARACTER"<<endl;
    cout<<"1.WARRIOR --- STRENGTH     1000 ARMOUR  1000"<<endl;
    cout<<"2.MAGE    --- INTELLIGENCE 800  MANA    1200"<<endl;
    cout<<"3.ROGUE   --- AGILITY      900  EVASION 1150"<<endl;
    cin>>playerOne;
    cout<<"  PLAYER 2 SELECT YOUR CHARACTER"<<endl;
    if(playerOne == 1)
    {
        cout<<"2.MAGE    --- INTELLIGENCE 800  MANA    1200"<<endl;
        cout<<"3.ROGUE   --- AGILITY      900  EVASION 1150"<<endl;
        cin>>playerTwo;
        if(playerTwo == 2)
        {
            cout<<"WELCOME WARRIOR PLAYER 1 AND MAGE PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Warrior player1(name_one, 1, 1000, 1000);
            Mage player2(name_two, 1, 800, 1200);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player1, player2);
        }
        else
        {
            cout<<"WELCOME WARRIOR PLAYER 1 AND ROGUE PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Warrior player1(name_one, 1, 1000, 1000);
            Rogue player2(name_two, 1, 900, 1150);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player1, player2);
            
        }
    }
    else if(playerOne == 2)
    {
        cout<<"1.WARRIOR --- STRENGTH     1000 ARMOUR  1000"<<endl;
        cout<<"3.ROGUE   --- AGILITY      900  EVASION 1150"<<endl;
        cin>>playerTwo;
        if(playerTwo == 1)
        {
            cout<<"WELCOME MAGE PLAYER 1 AND WARRIOR PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Mage player1(name_one, 1, 800, 1200);
            Warrior player2(name_two, 1, 1000, 1000);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player2, player1);
        
        }
        else
        {
            cout<<"WELCOME MAGE PLAYER 1 AND ROGUE PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Mage player1(name_one, 1, 800, 1200);
            Rogue player2(name_two, 1, 900, 1150);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player2, player1);
            
        }
    }
    else
    {
        cout<<"1.WARRIOR --- STRENGTH     1000 ARMOUR  1000"<<endl;
        cout<<"2.MAGE    --- INTELLIGENCE 800  MANA    1200"<<endl;
        cin>>playerTwo;
        if(playerTwo == 1)
        {
            cout<<"WELCOME ROGUE PLAYER 1 AND WARRIOR PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Rogue player1(name_one, 1, 900, 1150);
            Warrior player2(name_two, 1, 1000, 1000);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player2, player1);
            
        }
        else
        {
            cout<<"WELCOME ROGUE PLAYER 1 AND MAGE PLAYER 2 "<<endl;
            cout<<"ENTER NAME PLAYER 1 : ";cin>>name_one;
            cout<<"\nENTER NAME PLAYER 2 : ";cin>>name_two;
            Rogue player1(name_one, 1, 900, 1150);
            Mage player2(name_two, 1, 800, 1200);
            cout<<"\nPLAYER 1:\n";
            player1.displayInfo();
            cout<<"\nPLAYER 2:\n";
            player2.displayInfo();
            cout<<"\nARE YOU READY TO BATTLE?\n(PRESS 'T' TO START)";
            while(true)
            {
                if(_kbhit())
                {
                    char ch = _getch();
                    if(ch == 't' || ch == 'T')
                    {
                        break;
                    }
                }
            }
            battle(player1, player2);
        }
    }


}


int main()
{
    gameMain();
    
}