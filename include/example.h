#pragma once

#include <cmath>
#include <string>

struct Coordinate {
  double latitude, longitude;
};

/* Coordinate system for tile map server. */
struct TileGrid {
  TileGrid(unsigned zoom_level): zoom_level(zoom_level) {};
  
  unsigned numberOfTilesX() {
    return 2 << zoom_level; // at level 0, world is divided in to halfs at meridian
  }
  unsigned numberOfTilesY() {
    return 1 << zoom_level;  // at level 0, world is not divided at latitudes
  }
  double sizeX(){
    return 360.d / double(numberOfTilesX());
  }
  double sizeY(){
    return 180.d / double(numberOfTilesY());
  }
  // origin is the south western corner
  Coordinate getOriginOfTile(unsigned int X, unsigned Y) {
    return Coordinate{-1 * ((Y + 1) * sizeY()) - 90.d, (X * sizeX()) - 180.d}; // Y + 1 because south of tile is origin
  }
  unsigned tileIndexX(double longitude) {
    return unsigned( std::floor((longitude + 180.d) / sizeX()) );
  }
  unsigned tileIndexY(double latitude) {
    return unsigned( std::floor((90.d - latitude) / sizeY()) );
  }
  unsigned zoom_level;
};

/* Some example class which uses a TileGrid. Methods are implemented in .cpp files. */
class ExampleClass {
public:
  ExampleClass(unsigned level): CoordSystem(level)  {};
  Coordinate exampleStuff();
private:
  TileGrid CoordSystem;
};
