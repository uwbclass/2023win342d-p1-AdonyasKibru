
#include "pokedex.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Pokedex::Pokedex() {}

// The function returns the size of the pokedex
int Pokedex::size() const { return Pokedex::msize; }

// Retrun maximum size, capacity of Pokedex
int Pokedex::max_size() { return Pokedex::MAX; }

// returns true if the pokedex is empty
bool Pokedex::empty() const {
  if (Pokedex::msize == 0) {
    return true;
  }
  return false;
}

// return pokemon based of its index number
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= Pokedex::msize) {
    cerr << "the index you enterd is wrong!";
    return Pokedex::pokemons[0];
  } else {
    return Pokedex::pokemons[n];
  }
}

// returns the first pokemon
const string &Pokedex::front() const { return Pokedex::pokemons[0]; }

// returns the last pokemon
const string &Pokedex::back() const {
  return Pokedex::pokemons[Pokedex::msize - 1];
}

// this function adds a pokemon will keeping the list sorted
void Pokedex::insert(const string &pokemon) {
  if (Pokedex::msize == Pokedex::MAX) {
    return;
  }
  if (Pokedex::msize == 0) {
    Pokedex::pokemons[0] = pokemon;
    msize++;
    return;
  }
  for (int i = 0; i < Pokedex::msize; i++) {
    if (Pokedex::pokemons[i] > pokemon) {
      for (int j = 0; j < msize - i; j++) {
        Pokedex::pokemons[Pokedex::msize - j] =
            Pokedex::pokemons[Pokedex::msize - j - 1];
      }
      Pokedex::pokemons[i] = pokemon;
    }
  }
  Pokedex::msize++;
  return;
}

// this function delete the last element
void Pokedex::pop_back() { Pokedex::msize--; }

// this function eases the pokemon on the given index value
void Pokedex::erase(int n) {
  if (n < 0 || n >= Pokedex::msize) {
    cerr << "the index value you entered is wrong!" << endl;
    return;
  }

  for (int i = 0; i < Pokedex::msize - n - 1; i++) {
    Pokedex::pokemons[n + i] = Pokedex::pokemons[n + 1 + i];
  }
  Pokedex::msize--;
}

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  if (pdx.size() == 0) {
    out << "[]";
  } else if (pdx.size() == 1) {
    out << "[" << pdx.at(0) << "]";
  } else {
    out << "[" << pdx.at(0);
    for (int i = 1; i < pdx.size(); i++) {
      out << ", " << pdx.at(i);
    }
    out << "]";
  }

  return out;
}
