
#include "pokedex.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Pokedex::Pokedex() {}

// The function returns the current size of the pokemons
int Pokedex::size() const { return msize; }

// Retrun maximum size, capacity of Pokemons
int Pokedex::max_size() { return MAX; }

// returns true if pokemons is empty
bool Pokedex::empty() const { return msize == 0; }

// return pokemon based of its index number from the pokemons
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "The index you entered is wrong!" << endl;
    n = 0;
  }
  return pokemons[n];
}

// returns the first pokemon
const string &Pokedex::front() const { return pokemons[0]; }

// returns the last pokemon
const string &Pokedex::back() const {
  if (msize == 0) {
    return pokemons[0];
  }
  return pokemons[msize - 1];
}

// this function adds a pokemon while also keeping the list sorted
// alphabetically
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
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
    for (int j = 0; j < msize - 1; j++) {
      pokemons[msize - j] = pokemons[msize - 1 - j];
    }
    pokemons[1] = pokemon;
  }
  msize++;
}

// this function delete the last element
void Pokedex::pop_back() {
  if (msize == 0) {
    cerr << "their are no elements in the pokedex" << endl;
    return;
  }
  msize--;
}

// this function erases the pokemon on the given index value
// while keeping the order intacted
void Pokedex::erase(int n) {
  if (n < 0 || n >= msize) {
    cerr << "the index value you entered is wrong!" << endl;
    return;
  }
  for (int i = 0; i < msize - n - 1; i++) {
    pokemons[n + i] = pokemons[n + 1 + i];
  }
  msize--;
}

// This function is used to print out the pokemons
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  if (!pdx.empty()) {
    out << pdx.at(0);
    for (int i = 1; i < pdx.size(); i++) {
      out << ", " << pdx.at(i);
    }
  }
  out << "]";
  return out;
}
