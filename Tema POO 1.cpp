#include <iostream>

using namespace std;

//Nume: Mihaila Andrei
//Domeniu: Monetarie
//Clase: Angajat, Moneda, Bijuterie

class Angajat {
	public:
		char* nume;
		int salariu;
		static float impozitSalariu;
		const string CNP;
		
		Angajat() : CNP("Undefined") //Valori default
		{
			this->nume = new char[strlen("Undefined") + 1];
			strcpy_s(this->nume, strlen("Undefined") + 1, "Undefined");
			this->salariu = 0;

		}

		Angajat(const char* numeNou, int salariu, string CNP_Nou) : CNP(CNP_Nou) //Actualizam datele
		{
			this->nume = new char[strlen(numeNou) + 1];
			strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
			this->salariu = salariu;
		}

		Angajat(const char* numeNou, string CNP_Nou) : CNP(CNP_Nou) // Internship (actualizam datele, dar nu exista salariu)
		{
			this->nume = new char[strlen(numeNou) + 1];
			strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
			this->salariu = 0;

		}

		~Angajat()
		{
			if (this->nume != "NULL")
			{
				delete[]this->nume;
				this->nume = NULL;
			}
		}

		void afisare()
		{
			cout << "Numele angajatului: " << nume << "\nSalariul angajatului: " << salariu
				<< "\nImpozitul pe salariu este: " << impozitSalariu << "\nCNP-ul angajatului este: " << CNP <<
				"\nSalariul dupa impozitare este: " << salariu * (1 - impozitSalariu) << "\n\n";
		}

		static void setImpozit(float impozitNou)
		{
			impozitSalariu = impozitNou;
		}
};
float Angajat::impozitSalariu = 0.45;

class Moneda {
	public:
		char* forma;
		float valoare;
		const string material;
		static string valuta;

		Moneda() : material("Aer") //Nu exista o moneda introdusa
		{
			this->forma = new char[strlen("Nu exista") + 1];
			strcpy_s(this->forma, strlen("Nu exista") + 1, "Nu exista");
			this->valoare = 0;
		}

		Moneda(const char* formaNoua, float valoareNoua, string materialNou) : material(materialNou) //Moneda cu material special
		{
			this->forma = new char[strlen(formaNoua) + 1];
			strcpy_s(this->forma, strlen(formaNoua) + 1, formaNoua);
			this->valoare = valoareNoua;

		}

		Moneda(const char* formaNoua, float valoareNoua) : material("Fier") //Moneda clasica din fier
		{
			this->forma = new char[strlen(formaNoua) + 1];
			strcpy_s(this->forma, strlen(formaNoua) + 1, formaNoua);
			this->valoare = valoareNoua;

		}

		~Moneda()
		{
			if (this->forma != NULL)
				delete[]this->forma;
		}

		void afisare()
		{
			cout << "Forma monedei este: " << forma << "\nValoarea este de: " << valoare << " " << valuta <<
				"\nMaterialul din care este realizata: " << material <<"\n\n";
		}

		static void setValuta(string valutaNoua)
		{
			valuta = valutaNoua;
		}
};
string Moneda::valuta = "RON";

class Bijuterie {
	public:
		string tipBijuterie;
		string tematica;
		int nrMateriale;
		char** denumireMateriale;
		const int anConfectionare;
		static float TVA;

		Bijuterie() : anConfectionare(0) //Bijuterie inexistenta
		{
			this->tipBijuterie = "Undefined";
			this->tematica = "Undefined";
			this->nrMateriale = 0;
		}

		//Bijuterie completa care poate contine mai multe materiale
		Bijuterie(string tipBijuterie, string tematica, int nrMateriale, char** denumireMateriale, int an) : anConfectionare(an)
		{
			this->tipBijuterie = tipBijuterie;
			this->tematica = tematica;
			this->nrMateriale = nrMateriale;
			if (nrMateriale > 0)
			{
				this->denumireMateriale = new char* [nrMateriale];
				for (int i = 0; i < nrMateriale; i++)
				{
					this->denumireMateriale[i] = new char[strlen(denumireMateriale[i]) + 1];
					strcpy_s(this->denumireMateriale[i], strlen(denumireMateriale[i]) + 1, denumireMateriale[i]);
				}
			}
		}
		//Bijuterie simpla, ieftina din Inox
		Bijuterie(string tipBijuterie, string tematica, int an) : anConfectionare(an)
		{
			this->tipBijuterie = tipBijuterie;
			this->tematica = tematica;
			this->nrMateriale = 1;

			this->denumireMateriale = new char* [1];
			this->denumireMateriale[0] = new char[strlen("Inox") + 1];
				strcpy_s(this->denumireMateriale[0], strlen("Inox") + 1, "Inox");
		}

		~Bijuterie()
		{
			if (this->denumireMateriale != NULL)
			{
				for (int i = 0; i < this->nrMateriale; i++)
				{
					if (this->denumireMateriale[i] != NULL)
						delete[]this->denumireMateriale[i];
				}
			}
			delete[]this->denumireMateriale;
		}

		void afisare()
		{
			cout << "Tipul Bijuteriei este: " << tipBijuterie << "\nTematica Bijuteriei este: " << tematica <<
				"\nAnul Confectionarii a fost: " << anConfectionare << "\nTVA-ul este de: " << TVA;
			if (nrMateriale != 0)
			{
				cout <<"\nNr materiale folosite: " <<
					nrMateriale << "\nMaterialele folosite sunt: ";
				for (int i = 0; i < nrMateriale; i++)
					cout << denumireMateriale[i] << " ";
			}
			else cout << "\nNu exista materiale folosite!";
			cout << "\n\n";
		}

		static void setTVA(float tvaNou)
		{
			TVA = tvaNou;
		}


};
float Bijuterie::TVA = 0.19;

void afisareClasaAngajat()
{
	Angajat Marcel;
	Angajat Adrian("Adrian", 2000, "1234");
	Angajat Andrei("Andrei", "2341");
	Marcel.afisare();
	Adrian.afisare();
	Andrei.afisare();
}

void afisareClasaMoneda()
{
	Moneda doiBani;
	Moneda cinciBani("Rotunda", 0.5, "Bronz");
	Moneda zeceBani("Patrata", 10);
	doiBani.afisare();
	cinciBani.afisare();
	zeceBani.afisare();
}

void afisareClasaBijuterie()
{
	//Initializare variabila materiale pentru a o putea transmite prin parametru
	char** materiale;
	materiale = new char* [2];
	materiale[0] = new char[10];
	materiale[1] = new char[10];
	strcpy_s(materiale[0], strlen("Argint") + 1, "Argint");
	strcpy_s(materiale[1], strlen("Aur") + 1, "Aur");


	Bijuterie lant;
	lant.afisare();
	Bijuterie inel("Inel", "Logodna", 2, materiale, 2023);
	inel.afisare();
	Bijuterie cercelObor("Cercel", "Copii", 2015);
	cercelObor.afisare();
}

int main()
{
	afisareClasaAngajat();
	afisareClasaMoneda();
	afisareClasaBijuterie();

}