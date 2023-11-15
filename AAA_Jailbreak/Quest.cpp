#include "Quest.h"

Quest::Quest() {
    condition = false;
}

Quest::Quest(string qD, string qIPD, string qFD) {
    QuestDialogue = qD;
    QuestInProgressDialogue = qIPD;
    QuestFinishedDialogue = qFD;
    condition = false;

    finished = false;
}

void Quest::setQuestDialogue(string d) {
    QuestDialogue = d;

}
void Quest::setQuestFinishedDialogue(string fD) {
    QuestFinishedDialogue = fD;
}
void Quest::setQuestInProgressDialogue(string iPD) {
    QuestInProgressDialogue = iPD;
}

string Quest::getQuestDialogue() {
    string dialogueSep = "\n============================================\n";
    return QuestDialogue + dialogueSep;
}

string Quest::getQuestFinishedDialogue() {
    string dialogueSep = "\n============================================\n";
    return dialogueSep + QuestFinishedDialogue + dialogueSep;
}
string Quest::getInProgressDialogue() {
    string dialogueSep = "\n============================================\n";
    return QuestInProgressDialogue + dialogueSep;
}

Item Quest::getItem(string itemName) {
    if (!itemsToGive.empty())
        for (auto item : itemsToGive) {
            if (item.getName() == itemName) {
                return item;
            }
        }

    return Item();
}

int Quest::CheckCondition() {
    return condition;
}

void Quest::setCondition(int x) {
    if (x >= 3) {
        condition = 3;
    }
    else if (x <= 0) {
        condition = 0;
    }
    else {
        condition = x;
    }


}


