#include "Osoba.hpp"
#include "Pojazd.hpp"

Pojazd::Pojazd (const Osoba& _wlasciciel, int _przebieg)
    :wlasciciel(_wlasciciel), przebieg(_przebieg) {}

Pojazd::~Pojazd() {}


