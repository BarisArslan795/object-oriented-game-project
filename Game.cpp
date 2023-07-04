#include "Game.h"
#include "Pea.h"
#include "plant.h"
#include "tile.h"
#include "Card.h"
#include "UpgradeButton.h"
#include "RemoveButton.h"
#include "Sun.h"
#include "sunFlowerCard.h"
#include "peaShooterCard.h"
#include "nutCard.h"


bool game::OnUserCreate() {
    gameTime = 0;
    CurrentSun = 100;
    gameEnd = false;
    gamePause = false;
    //Create Buttons
    new UpgradeButton(200, 0, 150, new olc::Sprite("Sprites/upgrade1.png"), *this);
    new RemoveButton(150, 0, -25, new olc::Sprite("Sprites/remove1.png"), *this);
    new sunFlowerCard(0, 0, 50, new olc::Sprite("Sprites/sunflower1.png"), *this); 
    new peaShooterCard(50, 0, 100, new olc::Sprite("Sprites/peashooter1.png"), *this);
    new nutCard(100, 0, 50, new olc::Sprite("Sprites/nut1.png"), *this);
    //Create Cards

    //Create Tiles
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            new tile((i - 1) * 50, j * 50, *this);
        }
    }
    //Create Tiles
    return true;
}

bool game::OnUserUpdate(float fElapsedTime) {
    gameTime += fElapsedTime;

    if (gameEnd)
        return gameEndScreen();
    
    if (GetKey(olc::Key::P).bPressed) {
        gamePause = true;
    }

    if (gamePause)
        return gamePauseScreen();
    if (finalCountDown > 0)
        return countDownScreen(fElapsedTime);

    createBackground();
    
    //Zombie Spawns
    if (spawnCD < 0) {
        int s = rand() % tiles.size();
        tiles[s]->zombieSpawn();
        spawnCD = spawnRate;
    }
    if (gameTime < 5) { spawnCD -= fElapsedTime; }
    else if (gameTime < 10) { spawnCD -= fElapsedTime * 3; }
    else if (gameTime < 15) { spawnCD -= fElapsedTime * 4; }
    else { spawnCD -= fElapsedTime * 4; }
    //Zombie Spawns
    
    //Zombie Move & Attack
    for (auto z : zombies){
        z->zombieMove(fElapsedTime);
        if (z->ZombieWin())
            gameEnd = true; 
        for (auto t : tiles)
            z->zombieAttack(fElapsedTime, t);
    }
    //Zombie Move & Attack

    //Plant ability (Sunflower and Pea Creation) and Plants death
    for (auto t : tiles){
        t->abilityPowerOfPlant(fElapsedTime);
    }
    //Plant ability (Sunflower and Pea Creation) and Plants death


    //Seeds Move & Attack & Disappear
    for (auto pea : peas){
        pea->peaMove(fElapsedTime);
        for (auto z : zombies)
            pea->peaAttack(fElapsedTime, z);
    }
    //Seeds Move & Attack & Disappear
 


    //Mouse Operations.

    if (GetMouse(0).bPressed) {

        // Selecting-Deselecting Card
        anySelection = false;

        //Deselect
        for (auto a : buttons)
            anySelection = a->deSelect(anySelection);
        //Deselect

        //Select
        for (auto a : buttons)
            a->select(anySelection);
        //Select
        // Selecting-Deselecting Card

        //Planting/Removing/Upgrading(ACTIONS)
        for (auto t : tiles)
            for (auto b : buttons)
                t->chooseActionsTile(GetMouseX(), GetMouseY(), CurrentSun, b);
        //Planting

        //Collecting Sun /*
        for (int i = 0; i < suns.size(); i++) {
            if (suns[i]->collectSun()) {
                delete suns[i];
                i--;
            }
        }
        //Collecting Sun
    }
    //Mouse Operations.

    //Exit game if pressed E or any zombie passes the left line
    if (GetKey(olc::E).bPressed) {
        gameEnd = true;
    }

    if (gameEnd)
        return gameExit();
    //Exit game if pressed E or any zombie passes the left line

    //Draw what is everything.
    drawEverything();

    return true;
}

    
    

void game::drawEverything(){
    drawRemainingSun();
    //Drawing the tiles.
    for (auto a : tiles)
        a->draw();
    //Drawing the cards.
    for (auto a : buttons)
        a->draw();

    //Peashooter and Sunflower Draw
    for (auto i : tiles)
        i->drawThePlant();

    //Sun Draw
    for (auto i : suns) 
        i->draw();
    
    //Seed Draw
    for (auto i : peas) 
        i->draw();

    //Zombie Draw
    for (auto i : zombies)
        i->draw();
}
 
bool game::gameExit() {
    for (int i = 0; i < zombies.size(); i++){
        delete zombies[i];
        i--;
    }
    for (int i = 0; i < suns.size(); i++) {
        delete suns[i];
        i--;
    }
       
    for (int i = 0; i < peas.size(); i++) {
        delete peas[i];
        i--;
    }

    for (int i = 0; i < tiles.size(); i++) {
        delete tiles[i];
        i--;
    }
    for (int i = 0; i < buttons.size(); i++) {
        delete buttons[i];
        i--;
    }
        

    return true;
}

bool game::gameEndScreen() {
    //GAME END SCREEN
    Clear(olc::BLACK);
    DrawString(110, 10, "GAME OVER", olc::WHITE);

    FillRect(100, 90, 100, 50, olc::DARK_GREEN);
    DrawString(110, 110, "PLAY AGAIN", olc::WHITE);
    FillRect(100, 150, 100, 50, olc::DARK_RED);
    DrawString(135, 170, "EXIT", olc::WHITE);
    SetPixelMode(olc::Pixel::ALPHA);
    if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 90 && GetMouseY() <= 140)
    {
        FillRect(100, 90, 100, 50, olc::WHITE);
        DrawString(110, 110, "PLAY AGAIN", olc::DARK_GREEN);

        if (GetMouse(0).bReleased)
        {
            OnUserCreate();
        }
    }
    if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 150 && GetMouseY() <= 200)
    {
        FillRect(100, 150, 100, 50, olc::WHITE);
        DrawString(135, 170, "EXIT", olc::DARK_RED);

        if (GetMouse(0).bReleased)
        {
            return false; 
        }
    }

    return true;

    //GAME END SCREEN
}
bool game::countDownScreen(float fElapsedTime) {
    createBackground();
    drawEverything();
    finalCountDown -= fElapsedTime;
    if (finalCountDown > 2)
        DrawString(90, ScreenHeight() / 2, " 3 Seconds Remaining");
    else if (finalCountDown > 1)
        DrawString(90, ScreenHeight() / 2, " 2 Seconds Remaining");
    else if (finalCountDown > 0)
        DrawString(90, ScreenHeight() / 2, " 1 Second Remaining");
    return true;
}

bool game::gamePauseScreen() {

    //GAME PAUSE

    Clear(olc::BLACK);
    FillRect(100, 100, 100, 50, olc::DARK_GREEN);
    DrawString(90, 10, "PLANTS & ZOMBIES PAUSED", olc::WHITE);
    DrawString(120, 120, "CONTINUE", olc::WHITE);
    SetPixelMode(olc::Pixel::ALPHA);
    if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 100 && GetMouseY() <= 150)
    {
        FillRect(100, 100, 100, 50, olc::WHITE);
        DrawString(120, 120, "CONTINUE", olc::DARK_GREEN);

        if (GetMouse(0).bReleased)
        {
            finalCountDown = 3;
            gamePause = false; 
        }
    }
    return true;

    
    //GAME PAUSE
}

void game::createBackground() {
    //Drawing the background
    Clear(olc::DARK_GREEN);
    FillRect(0, 0, 300, 50, olc::BLACK);
    SetPixelMode(olc::Pixel::ALPHA);
    //Drawing the background
}


void game::drawRemainingSun() {
    //Drawing the remaining sun 
    DrawSprite(ScreenWidth() - 50, 0, new olc::Sprite("Sprites/sun1.png"), 1);
    DrawString(ScreenWidth() - 35, 40, to_string(CurrentSun), olc::WHITE);
    //Drawing the remaining sun

}


void game::addButton(Button* pB) {
    buttons.push_back(pB);
};

void game::removeButton(Button* pC) {
    for (int i = 0; i < buttons.size(); i++) {
        if (buttons[i] == pC) {
            buttons.erase(buttons.begin() + i);
            break;
        }
    }
}

void game::addTile(tile* pT) {
    tiles.push_back(pT);
};

void game::removeTile(tile* pT) {
    for (int i = 0; i < tiles.size(); i++) {
        if (tiles[i] == pT) {
            tiles.erase(tiles.begin() + i);
            break;
        }
    }
}


void game::addSun(Sun* pS) {
    suns.push_back(pS);
};

void game::removeSun(Sun* pS) {
    for (int i = 0; i < suns.size(); i++) {
        if (suns[i] == pS) {
            suns.erase(suns.begin() + i);
            break;
        }
    }
}

void game::addZombie(Zombie* pZ) {
    zombies.push_back(pZ);
};

void game::removeZombie(Zombie* pZ) {
    for (int i = 0; i < zombies.size(); i++) {
        if (zombies[i] == pZ) {
            zombies.erase(zombies.begin() + i);
            break;
        }
    }
}

void game::addPea(Pea* pP) {
    peas.push_back(pP);
};

void game::removePea(Pea* pPea) {
    for (int i = 0; i < peas.size(); i++) {
        if (peas[i] == pPea) {
            peas.erase(peas.begin() + i);
            break;
        }
    }
}

void game::changeSunPoints(int cost) {
    CurrentSun -= cost;
}

void game::zombieCanAttack(int xPlant, int yPlant) {
    for (auto z : zombies)
        z->zombieCanAttackUpdate(xPlant, yPlant);
}

void game::createZombie(int y) {
    new Zombie(ScreenWidth(), y, *this);
}