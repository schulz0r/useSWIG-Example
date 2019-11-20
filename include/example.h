#pragma once

struct Coordinate {
  double latitude, longitude;
};

/* Coordinate system for tile map server. */
struct TileGrid {
  TileGrid(unsigned zoom_level): zoom_level(zoom_level) {};
  
  unsigned numberOfTilesX();
  unsigned numberOfTilesY();
  double sizeX();
  double sizeY();
  Coordinate getOriginOfTile(unsigned int X, unsigned Y);
  unsigned tileIndexX(double longitude);
  unsigned tileIndexY(double latitude);
  unsigned zoom_level;
};

/* Some example class which uses a TileGrid. Methods are implemented in .cpp files. */
class ExampleClass {
public:
  ~ExampleClass();
  ExampleClass(unsigned level);
  Coordinate exampleStuff();
private:
  TileGrid CoordSystem;
};
