#include "example.h"

Coordinate ExampleClass::exampleStuff() {
  return this->CoordSystem.getOriginOfTile(8, 8);
}
