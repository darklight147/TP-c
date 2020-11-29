#include <iostream>
#include <cstdlib>

using namespace std;

float getMax(float *note)
{
    float max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (note[i] > max)
        {
            max = note[i];
        }
    }
    return max;
}

float getMin(float *note)
{
    float min = 20;
    for (int i = 0; i < 5; i++)
    {
        if (note[i] < min)
        {
            min = note[i];
        }
    }
    return min;
}
float getMoy(float *note)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += note[i];
    }
    return sum / 5;
}

class Etud
{
private:
    string nom;
    string prenom;
    int CNE;

    float *note = new float[5];

public:
    Etud(/* args */);
    void creer(string nom, string prenom, int cne, float *note)
    {
        this->nom = nom;
        this->prenom = prenom;
        this->CNE = cne;
        this->note = note;
    }
    float getMaxNote()
    {
        return getMax(this->note);
    }
    float getMinNote()
    {
        return getMin(this->note);
    }
    float getMoyenneNote()
    {
        return getMoy(this->note);
    }
    void describe()
    {
        cout << "Nom: " << nom << "\t"
             << "Prenom: " << prenom << endl;
        cout << "Note maximal " << this->getMaxNote() << endl;
        cout << "Note minimal " << this->getMinNote() << endl;
        cout << "Note moyenne " << this->getMoyenneNote() << endl;
    }

    void getQuota()
    {
        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (this->note[i] > 10)
                count++;
        }
        cout << "Quota: " << ((float)count / (float)5) * 100 << "%" << endl;
    }
    ~Etud();
};

Etud::Etud(/* args */)
{
}

Etud::~Etud()
{
    delete this->note;
}

int main()
{
    Etud etudiant;
    float *note = new float[5];

    for (int i = 0; i < 5; i++)
    {
        note[i] = rand() % 20;
    }

    etudiant.creer("Mohamed", "Belkamel", 555631, note);
    cout << etudiant.getMaxNote() << endl;
    cout << etudiant.getMinNote() << endl;
    etudiant.getQuota();
    etudiant.getMaxNote();
    etudiant.getMinNote();
    etudiant.describe();
    etudiant.~Etud();

    cout << "Donner le nombre d'etudiant" << endl;
    int etudCount;
    cin >> etudCount;

    Etud *p = new Etud[etudCount];

    for (int i = 0; i < etudCount; i++)
    {
        string nom;
        string prenom;
        int CNE;

        float *note = new float[5];
        cout << "Donner le nom de l'etudiant " << i + 1;
        cin >> nom;
        cout << "Donner le prenom de l'etudiant " << i + 1;
        cin >> prenom;
        cout << "Donner le CNE de l'etudiant " << i + 1;
        cin >> CNE;
        for (int y = 0; y < 5; y++)
        {
            cout << "Donner la note " << y << " de l'etudiant " << i + 1;
            cin >> note[y];
        }

        p[i].creer(nom, prenom, CNE, note);
    }

    return 0;
}
