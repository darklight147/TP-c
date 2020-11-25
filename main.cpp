#include <iostream>

using namespace std;

class Personne
{
private:
public:
    string nom, prenom;
    Personne();
};

Personne::Personne()
{
}

void saisir(Personne *P)
{
    cin >> P->nom;

    cin >> P->prenom;
}

int main()
{
    Personne personne;

    saisir(&personne);
    cout << personne.nom << " " << personne.prenom << endl;
}