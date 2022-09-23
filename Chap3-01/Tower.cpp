#include "Tower.h"

Tower::Tower() : Tower(1) {}
Tower::Tower(int height) { this->height = height; }
int Tower::getHeight() { return height; }