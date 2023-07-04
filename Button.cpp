#include "olcSimpleEngine.h"
#include "Card.h"
#include "tile.h"
#include "Sunflower.h"
#include "peashooter.h"
#include "Game.h"
#include "Button.h"

using namespace std;

Button::Button(int X, int Y, int COST, olc::Sprite* IMG, game& PG)
    : x(X), y(Y), cost(COST), isSelected(false), pG(&PG)
{
    img = IMG;
    pG->addButton(this);
};

Button::~Button() {
    pG->removeButton(this);
}

bool Button::deSelect(bool anySelection) {

    anySelection = anySelection || isSelected;
    // Selecting-Deselecting Card

    if (pG->GetMouseX() > x && pG->GetMouseX() < x + 50 && pG->GetMouseY() > y && pG->GetMouseY() < y + 50)
    {
        if (isSelected)
            isSelected = false;
    }
    return anySelection;
};

void Button::select(bool anySelection) {
    if (!anySelection)
        if (pG->GetMouseX() > x && pG->GetMouseX() < x + 50 && pG->GetMouseY() > y && pG->GetMouseY() < y + 50)
            if (!isSelected)
                isSelected = true;
};


void Button::draw() {
    pG->FillRect(x, y, 49, 49, olc::WHITE);
    pG->DrawSprite(x, y, img, 1);
    pG->DrawString(x+2, y+3, to_string(cost), olc::DARK_RED);

    if (isSelected)
    {
        pG->DrawRect(x, y, 49, 49, olc::RED);
    }
    else
    {
        if (pG->GetMouseX() > x && pG->GetMouseX() < x + 50 && pG->GetMouseY() > y && pG->GetMouseY() < y + 50)
        {
            pG->DrawRect(x, y, 49, 49, olc::WHITE);
        }

        else
        {
            pG->DrawRect(x, y, 49, 49, olc::BLACK);
        }
    }
};