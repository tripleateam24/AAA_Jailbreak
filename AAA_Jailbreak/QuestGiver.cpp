#include "QuestGiver.h"

QuestGiver::QuestGiver() {}

QuestGiver::QuestGiver(string n, string desc, string id) {
    name = n;
    description = desc;
    ID = id;
    questPosition = 0;
    greetings = { "Hey man...how's it going?", "How are ya?", "What's going on?", "Hey dude, how's it hanging?", "How's life going?" };
}

void QuestGiver::IncrementQuestPosition() {
    questPosition++;
}

void QuestGiver::setQuestPosition(int x) {
    questPosition = x;
}

int QuestGiver::getQuestPosition() {
    return questPosition;
}


