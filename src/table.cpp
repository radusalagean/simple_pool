#include "table.h"
#include "mainwindow.h"
#include "collisionobserver.h"

#include <limits>

Table::Table(CollisionObserver* c)
    : posX{}, posY{}, background{}
{
    background.loadFromFile("./pool_assets/table.png");
    posX = static_cast<int>((mainwindow->getWidth() - background.getWidth()) / 2);
    posY = static_cast<int>((mainwindow->getHeight() - background.getHeight()) / 2);

    /* Lots of hardcoded offsets to match colliders to table image */

    // Left and right colliders
    r[0].setShape(posX-3, posY+60, 40, 252);
    r[1].setShape(posX + static_cast<int>(background.getWidth()) - 37, posY+62, 40, 249);
    r[0].addObserver(c);
    r[1].addObserver(c);

    // Up and down 1
    r[2].setShape(posX + 61, posY-5, 268, 40);
    r[3].setShape(posX+59, posY + static_cast<int>(background.getHeight()) - 37, 268, 40);
    r[2].addObserver(c);
    r[3].addObserver(c);

    // Up and down 2
    r[4].setShape(posX + 371, posY-5, 269, 40);
    r[5].setShape(posX + 371, posY + static_cast<int>(background.getHeight()) - 37, 269, 40);
    r[4].addObserver(c);
    r[5].addObserver(c);

    // Ball colliders
    for (auto& elem: b)
    {
        elem.setTex("./pool_assets/ball0.png");
        elem.mass = std::numeric_limits<long>::max();
        elem.is_movable = false;
        elem.id = 999;
        elem.addObserver(c);
    }

    // Place 2 ball-colliders at each pocket
    b[0].setPos(posX + 27, posY + 58); // Top Left
    b[1].setPos(posX + 58, posY + 25);
    b[2].setPos(posX + 325, posY + 25); // Top Middle
    b[3].setPos(posX + 375, posY + 25);
    b[4].setPos(posX + background.getWidth() - 58, posY + 24); // Top Right
    b[5].setPos(posX + background.getWidth() - 27, posY + 57);
    b[6].setPos(posX + 27, posY + background.getHeight() - 58); // Bottom Left
    b[7].setPos(posX + 58, posY + background.getHeight() - 25);
    b[8].setPos(posX + 325, posY + background.getHeight() - 26); // Bottom middle
    b[9].setPos(posX + 375, posY + background.getHeight() - 26);
    b[10].setPos(posX + background.getWidth() - 58, posY + background.getHeight() - 25); // Bottom Right
    b[11].setPos(posX + background.getWidth() - 26, posY + background.getHeight() - 58);
}

void Table::render()
{
    background.render(posX, posY);

    /*
    for (auto& elem : r)
        elem.render();
    for (auto& elem : b)
        elem.render();*/
}