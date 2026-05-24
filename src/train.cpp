// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), ft(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car{light, nullptr, nullptr};
  if (ft == nullptr) {
    ft = newCar;
    ft->next = ft;
    ft->prev = ft;
  } else {
    newCar->next = ft;
    newCar->prev = ft->prev;
    ft->prev->next = newCar;
    ft->prev = newCar;
  }
}

int Train::getLength() {
  if (ft == nullptr) return 0;

  countOp = 0;
  ft->light = true;
  Car *current = ft;

  while (true) {
    int stepsToNextLight = 0;

    do {
      current = current->next;
      countOp++;
      stepsToNextLight++;
    } while (!current->light);

    current->light = false;

    Car *temp = current;
    for (int i = 0; i < stepsToNextLight; i++) {
      temp = temp->prev;
      countOp++;
    }

    if (!temp->light) {
      return stepsToNextLight;
    }
    current = temp;
  }
}

int Train::getOpCount() {
  return countOp;
}
