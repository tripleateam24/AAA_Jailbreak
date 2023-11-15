#pragma once
#define GUARD_H
#include "NPC.h"

class Guard : public NPC {
    //gaurds level of suspicion
    int suspicionLevel;

    //guard emotional status
    EmotionLevel emotionStatus;

    //guards response vectors
    vector<string> goodresponses;
    vector<string> badresponses;
    vector<string> neutralresponses;

public:
    //guards constructors
    Guard();
    Guard(string, string, string);


    void setSuspicionLevel(int);
    int getSuspicionLevel();

    void setEmotionStatus(EmotionLevel);
    EmotionLevel getEmotionStatus();

    int Confront(int, int);

    string getNeutralResponse();
    string getGoodResponse();
    string getBadResponse();
};