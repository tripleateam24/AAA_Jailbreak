#include "NPC.h"


class QuestGiver : public NPC {
    //quest position for each npc
    int questPosition = 0;

public:
    QuestGiver();
    QuestGiver(string, string, string);


    void IncrementQuestPosition();
    void setQuestPosition(int);
    int getQuestPosition();

};


