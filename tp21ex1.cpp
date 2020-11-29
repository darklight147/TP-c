/*
* Mohamed Belkamel
*/
#include <iostream>

using namespace std;

class Employer
{
	string nom;
	string prenom;
	int numAssuranceSocial;
	int age;
	int salaireHebdo;
	string poste;

public:
	void saisie(string nom, string prenom, int numAssuranceSocial, int age, int salaireHebdo, int n)
	{
		switch (n)
		{
		case 0:
			this->poste = "analyste";
			break;
		case 1:
			this->poste = "programeur";
			break;
		case 2:
			this->poste = "operateur";
			break;
		case 3:
			this->poste = "secretaire";
			break;
		default:
			break;
		}
		this->nom = nom;
		this->prenom = prenom;
		this->numAssuranceSocial = numAssuranceSocial;
		this->age = age;
		this->salaireHebdo = salaireHebdo;
	}

	void afficher()
	{
		cout << "Employer: \n  Nom: " << this->nom << endl;
		cout << "  Prenom: " << this->prenom << endl;
		cout << "  Numero d'assurance sociale: " << this->numAssuranceSocial << endl;
		cout << "  Age: " << this->age << endl;
		cout << "  Salaire Hebdomadaire: " << this->salaireHebdo << endl;
		cout << "  Poste: " << this->poste << endl;
	}

	float calculeSalaireMensuel()
	{
		return this->salaireHebdo * 4;
	}
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

int main()
{
	string nom;
	string prenom;
	int numAssuranceSocial, age, salaireHebdo, poste;

	cout << "donner le nom d'employer: ";
	fflush(stdin);
	cin >> nom;
	cout << "donner le prenom d'employer: ";
	fflush(stdin);
	cin >> prenom;

	do
	{
		cout << "donner le numero d'assurance sociale d'employer: ";
		numAssuranceSocial = valider(numAssuranceSocial);
	} while (numAssuranceSocial < 0);

	do
	{
		cout << "donner l'age d'employer: ";
		age = valider(age);
	} while (age < 18 || age > 150);

	do
	{
		cout << "donner le salaire hebdomadaire d'employer: ";
		salaireHebdo = valider(salaireHebdo);
	} while (salaireHebdo < 0);

	do
	{
		cout << "donner le poste d'employer (0:analyste, 1:programmeur, 2:operateur, 3:secretaire): ";
		poste = valider(poste);
	} while (poste < 0 || poste > 3);

	Employer unEmp;

	unEmp.saisie(nom, prenom, numAssuranceSocial, age, salaireHebdo, poste);
	unEmp.afficher();
	cout << "salaire mensuel: " << unEmp.calculeSalaireMensuel() << endl;

	return 0;
}
