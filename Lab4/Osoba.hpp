#ifndef LAB4_OSOBA_HPP
#define LAB4_OSOBA_HPP

#include <string>
#include <iostream>
#include <sstream>

class Osoba
{
private:
    std::string imie;
    std::string nazwisko;
    int	rok_ur;
public:
    Osoba () = delete;
    Osoba (const std::string& imie, const std::string& nazwisko, int _rok_ur);
    void ustawImie(const std::string& im);
    std::string pobierzImie() const;
    bool zapisz(std::ostream & os) const; /// zapisuje atrybuty do strumienia
    bool wczytaj(std::istream & is); /// wczytuje atrybuty ze strumienia
    friend std::ostream& operator <<(std::ostream& str, const Osoba &osoba);
};

#endif //LAB4_OSOBA_HPP
