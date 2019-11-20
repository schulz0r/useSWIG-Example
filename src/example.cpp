#include "example.h"

#include <cmath>
#include <string>

ExampleClass::ExampleClass(unsigned level): CoordSystem(level)  {};

Coordinate ExampleClass::exampleStuff() {
  return this->CoordSystem.getOriginOfTile(8, 8);
}

ExampleClass::~ExampleClass() {}

unsigned TileGrid::numberOfTilesX() {
    return 2 << zoom_level; // at level 0, world is divided in to halfs at meridian
}
unsigned TileGrid::numberOfTilesY() {
  return 1 << zoom_level;  // at level 0, world is not divided at latitudes
}
double TileGrid::sizeX(){
  return 360.d / double(numberOfTilesX());
}
double TileGrid::sizeY(){
  return 180.d / double(numberOfTilesY());
}
// origin is the south western corner
Coordinate TileGrid::getOriginOfTile(unsigned int X, unsigned Y) {
  return Coordinate{-1 * ((Y + 1) * sizeY()) - 90.d, (X * sizeX()) - 180.d}; // Y + 1 because south of tile is origin
}
unsigned TileGrid::tileIndexX(double longitude) {
  return unsigned( std::floor((longitude + 180.d) / sizeX()) );
}
unsigned TileGrid::tileIndexY(double latitude) {
  return unsigned( std::floor((90.d - latitude) / sizeY()) );
}
