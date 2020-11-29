/*
* Mohamed Belkamel
*/

#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

class Etudiant
{
	string nomPre;
	int numIns;
	float *notes;
	string code;

public:
	const static int MAX_NOTE = 7;

	Etudiant()
	{
		notes = new float[this->MAX_NOTE];
	}

	~Etudiant()
	{
		delete notes;
	}

	string getNomPre() { return this->nomPre; }
	int getNumIns() { return this->numIns; }
	string getCode() { return this->code; }
	float *getNotes() { return this->notes; }

	static bool validerCode(string code)
	{
		if (!isupper(code[0]))
			code[0] = toupper(code[0]);

		if (code.length() == 0 || code.length() > 2)
			return false;
		else if (code[0] < 'A' || code[0] > 'Z')
			return false;
		else if (code[1] != '+' && code[1] != '-')
			return false;
		return true;
	}

	void saisir(string nomPre, int numIns, string code, float *notes)
	{
		this->nomPre = nomPre;
		this->numIns = numIns;
		this->code = code;
		for (int i = 0; i < this->MAX_NOTE; i++)
		{
			this->notes[i] = notes[i];
		}
	}

	void affiche()
	{
		//cout << "Etudiant : \n";
		cout << "  Nom et prenom: " << this->nomPre << endl;
		cout << "  NumIns: " << this->numIns << endl;
		cout << "  Code: " << this->code << endl;
		cout << "  Notes : " << endl;
		for (int i = 0; i < this->MAX_NOTE; i++)
		{
			cout << "    note " << i + 1 << ": " << this->notes[i] << endl;
		}
		cout << "    Moyenne: " << this->getMoyenneNotes() << endl;
		cout << endl;
	}

	bool aValider()
	{
		for (int i = 0; i < this->MAX_NOTE; i++)
			if (notes[i] < 10)
				return false;
		return true;
	}

	float getMoyenneNotes()
	{
		float som;

		for (int i = 0; i < this->MAX_NOTE; i++)
			som += notes[i];
		return som / this->MAX_NOTE;
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

float valider(float n)
{
	fflush(stdin);
	while (!(cin >> n))
	{
		cin.clear();
		fflush(stdin);
	}
	return n;
};

int main()
{
	int n = 1;

	do
	{
		cout << "donner nombre d'etudiant: ";
		n = valider(n);
	} while (n < 0);

	Etudiant etudiants[n];
	char nomPre[100];
	int numIns;
	float notes[Etudiant::MAX_NOTE];
	string code;

	for (int i = 0; i < n; i++)
	{
		cout << "donner nom et prenom: ";
		fflush(stdin);
		gets(nomPre);

		do
		{
			cout << "donner NumIns: ";
			numIns = valider(numIns);
		} while (numIns < 0);

		do
		{
			cout << "donner code (lettre+/-, exp:A+):  ";
			fflush(stdin);
			cin >> code;
		} while (!Etudiant::validerCode(code));

		cout << "donner les notes d'etudiant:" << endl;
		for (int j = 0; j < Etudiant::MAX_NOTE; j++)
		{
			do
			{
				cout << "  note " << j + 1 << ": ";
				notes[j] = valider(notes[j]);
			} while (notes[j] < 0 || notes[j] > 20);
		}

		code[0] = toupper(code[0]);
		etudiants[i].saisir(nomPre, numIns, code, notes);
	}

	cout << "les etudiants qui ont valide: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (etudiants[i].aValider())
		{
			cout << "Etudiant " << i + 1 << ": " << endl;
			etudiants[i].affiche();
		}
	}

	cout << "les noms des etudiant commmencant par 'N': " << endl;
	for (int i = 0; i < n; i++)
	{
		if (etudiants[i].getNomPre()[0] == 'N')
		{
			cout << "Etudiant " << i + 1 << ": " << endl;
			etudiants[i].affiche();
		}
	}

	cout << endl
		 << "tableau d'etudiants: " << endl;
	cout << setw(15) << "Nom/prenom"
		 << " | ";
	for (int j = 0; j < Etudiant::MAX_NOTE; j++)
		cout << setw(6) << "Note" << j + 1 << " | ";
	cout << setw(9) << "Moyenne"
		 << " | " << setw(9) << "Valide" << endl;

	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << setw(15) << etudiants[i].getNomPre() << " | ";
		for (j = 0; j < Etudiant::MAX_NOTE; j++)
			cout << setw(7) << etudiants[i].getNotes()[j] << " | ";
		cout << setw(9) << etudiants[i].getMoyenneNotes() << " | " << setw(9) << (etudiants[i].aValider() ? "valide" : "non valide") << endl;
	}

	return 0;
}
