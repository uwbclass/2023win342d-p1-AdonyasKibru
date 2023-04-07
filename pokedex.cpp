
#include "pokedex.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Pokedex::Pokedex() {}

// The function returns the size of the pokedex
int Pokedex::size() const { return msize; }

// Retrun maximum size, capacity of Pokedex
int Pokedex::max_size() { return MAX; }

// returns true if the pokedex is empty
bool Pokedex::empty() const { return msize == 0; }

// return pokemon based of its index number
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "The index you entered is wrong!";
    n = 0;
  }
  return pokemons[n];
}

// returns the first pokemon
const string &Pokedex::front() const { return pokemons[0]; }

// returns the last pokemon
const string &Pokedex::back() const { return Pokedex::pokemons[msize - 1]; }

// this function adds a pokemon will keeping the list sorted
void Pokedex::insert(const string &pokemon) {
  if (Pokedex::msize == Pokedex::MAX) {
    return;
  }
  if (msize == 0) {
    pokemons[0] = pokemon;
  } else if (pokemon < pokemons[0]) {
    for (int j = 0; j < msize; j++) {
      pokemons[msize - j] = pokemons[msize - 1 - j];
    }
    pokemons[0] = pokemon;
  } else {
    int value = 1;
    while (pokemons[value] > pokemon) {
      value++;
    }
    for (int j = 0; j < msize - value; j++) {
      pokemons[msize - j] = pokemons[msize - 1 - j];
    }
    pokemons[value] = pokemon;
  }
  msize++;
}

// this function delete the last element
void Pokedex::pop_back() {
  if (msize == 0) {
    cerr << "their are no elements in the pokedex";
  } else {
    msize--;
  }
}

// this function eases the pokemon on the given index value
void Pokedex::erase(int n) {
  if (n < 0 || n >= msize) {
    cerr << "the index value you entered is wrong!" << endl;
  } else {
    for (int i = 0; i < msize - n - 1; i++) {
      pokemons[n + i] = pokemons[n + 1 + i];
    }
    msize--;
  }
}

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  if (pdx.empty()) {
    out << "[]";
  } else {
    out << "[" << pdx.at(0);
    for (int i = 1; i < pdx.size(); i++) {
      out << ", " << pdx.at(i);
    }
    out << "]";
  }

  return out;
}
