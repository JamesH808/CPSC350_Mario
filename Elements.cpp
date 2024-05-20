#include "elements.h"

Elements::Elements() {
  srand(time(0));
}

Elements::~Elements() {}

int Elements::randomChance() {
  chance = 1 + (rand() % 100);
  return chance;
}

bool Elements::goomba() {

  /*for the goomba*/
  randomChance();

  /*if he beats the goomba, clear the tile and return that he WON*/
  if (chance <= 80) {
    outcome = true;
  } else {
    outcome = false;
  }

  return outcome;
}

bool Elements::koopa() {
  /*for the koopa*/
  randomChance();
  if (chance <= 65) {

    outcome = true;

  } else {

    outcome = false;
  }

  return outcome;
}

bool Elements::boss() {
  randomChance();
  if (chance <= 50) {

    outcome = true;

  } else {
    outcome = false;
  }

  return outcome;
}