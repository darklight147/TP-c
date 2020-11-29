/*
* Mohamed Belkamel
*/
#include <iostream>

using namespace std;

class Personne
{
	string nom;
	string prenom;
	int age;

public:
	void setNom(string nom) { this->nom = nom; }
	void setPrenom(string prenom) { this->prenom = prenom; }
	void setAge(int age) { this->age = age; }

	string getNom() { return this->nom; }
	string getPrenom() { return this->prenom; }
	int getAge() { return this->age; }
};

int valider(int n)
{
	fflush(stdin);
	while (!(cin >> n))
	{
		cin.clear();
		fflush(stdin);
	}
	return n;
}

void saisir(Personne *p)
{
	string nom, prenom;
	int age;

	cout << "donner nom: ";
	fflush(stdin);
	cin >> nom;
	p->setNom(nom);

	cout << "donner prenom: ";
	fflush(stdin);
	cin >> prenom;
	p->setPrenom(prenom);

	do
	{
		cout << "donner age: ";
		age = valider(age);
	} while (age < 0 || age > 150);
	p->setAge(age);
}

void afficher(Personne unePers)
{
	cout << "  Nom: " << unePers.getNom() << endl;
	cout << "  Prenom: " << unePers.getPrenom() << endl;
	cout << "  Age: " << unePers.getAge() << endl;
}

void permuter(Personne *p1, Personne *p2)
{
	Personne tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main()
{
	Personne p1;
	Personne *p2 = new Personne;

	saisir(&p1);
	cout << "Personne 1: " << endl;
	afficher(p1);

	saisir(p2);
	cout << "Personne 2: " << endl;
	afficher(*p2);

	permuter(&p1, p2);

	cout << "\n***********************************************************\n\n";
	cout << "Personne 1: " << endl;
	afficher(p1);
	cout << "Personne 2: " << endl;
	afficher(*p2);

	delete p2;
	return 0;
}
