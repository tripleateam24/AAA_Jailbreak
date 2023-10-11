// AAA_Jailbreak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


void printBackstory() // backstory function. Can call it when the user inputs "story"
{
    //backstory
    string backStory;
    backStory =  "In the realm of tax consulting, you're a shining star, renowned for your prowess in deciphering the complex labyrinth of tax codes."
        " Your standing in the community is unblemished, but fate takes a dark turn when your neighbor, burdened by his ailing wife's medical bills,"
        "approaches you with a drastic proposal: to dance on the edge of legality and commit tax fraud. "
        "Brimming with integrity, you bravely decline, opting for the high road.Undeterred, your neighbor ventures forth, successfully securing the much" 
        "- needed loan.However, this triumph is short - lived as the IRS sniffs out irregularities and turns the spotlight on him. Cornered, he deflects attention,"
        "naming you as his trusted tax advisor, leaving you in the crosshairs. Soon, you're summoned for a gripping interrogation, the gravity of the situation "
        "hanging heavy in the air. The legal battle that ensues is nothing short of a high-stakes drama, where your attempts to set the record straight fall on deaf ears."
        "Against all odds, you find yourself on a rollercoaster ride through the justice system, ultimately facing a daunting 15-year sentence in a federal prison. "
        "The tale of your unwavering moral compass and the fight for justice paints a riveting portrait of an unexpected journey through the twists and turns of the law. \n";
    cout << backStory;
}

int main()
{
    //Displaying Game title
    cout << "-------Jailbreak-------\n";
    //displaying backstory
    printBackstory(); // need help with getting this to display - Nour
    //Displaying game objective
    cout << endl <<"Game Objective: Go through different tasks to escape the prison in the shortest amount of days possible."
        "You will have items and people to help you get out along the way.   \n";

    //Need a message letting the user know that if they type "story", they can get the backstory again

    // need to make a conditional statement to redisplay the backstory when user inputs "story"
    /* if user types == "story"
    *   printBackStory();
    */

}

