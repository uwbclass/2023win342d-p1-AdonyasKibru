
#include "pokedex.h"
#include <iostream>
#include <string>

using namespace std;

// Your code goes here
// Constructor
Pokedex::Pokedex() {}

// The function returns the size of the pokedex
int Pokedex::size() const { return msize; }

// Retrun maximum size, capacity of Pokedex
int Pokedex::max_size() { return MAX; }

// returns true if the pokedex is empty
bool Pokedex::empty() const {
  if (msize == 0) {
    return true;
  }
  return false;
}

// return pokemon based of its index number
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "hte index you enterd is wrong!" << endl;
    return pokemons[0];
  } else {
    return pokemons[n];
  }
}

// returns the first pokemon
const string &Pokedex::front() const { return pokemons[0]; }

// returns the last pokemon
const string &Pokedex::back() const { return pokemons[msize - 1]; }

// this function adds a pokemon will keeping the list sorted
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
    return;
  }
  if (size == 0) {
    pokemons[0] = pokemon;
    msize++;
    return;
  }
  for (int i = 0; i < msize; i++) {
    if (pokemons[i] > pokemon) {
      for (int j = 0; j < msize - i; j++) {
        pokemons[msize - j] = pokemons[msize - j - 1];
      }
      pokemons[i] = pokemon;
    }
  }
  msize++;
  return;
}

// this function delete the last element
void Pokedex::pop_back() { msize--; }

// this function eases the pokemon on the given index value
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

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) { cout << pdx << endl; }
