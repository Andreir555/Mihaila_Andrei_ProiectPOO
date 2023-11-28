#include <iostream>

using namespace std;

//Nume: Mihaila Andrei
//Domeniu: Monetarie
//Clase: Angajat, Moneda, Bijuterie

class Angajat {
private:
	char* nume;
	int salariu;
	static float impozitSalariu;
	const string CNP;
public:
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

	Angajat(const Angajat& angajat) {
		this->nume = new char[strlen(angajat.nume) + 1];
		strcpy_s(this->nume, strlen(angajat.nume) + 1, angajat.nume);
		this->salariu = angajat.salariu;
	}

	void operator=(const Angajat& angajat) {
		if (this != &angajat) {
			if (this->nume != NULL) delete[]this->nume;
			this->nume = new char[strlen(angajat.nume) + 1];
			strcpy_s(this->nume, strlen(angajat.nume) + 1, angajat.nume);
			this->salariu = angajat.salariu;
		}
	}
	Angajat operator+(const Angajat& angajat)
	{
		this->salariu += angajat.salariu;
		return (*this);
	}
	Angajat operator++() {
		this->salariu += 10;
		return(*this);
	}
	Angajat operator++(int) {
		Angajat temp = (*this);
		this->salariu += 10;
		return temp;
	}
	void afisare()
	{
		cout << "Numele angajatului: " << nume << "\nSalariul angajatului: " << salariu
			<< "\nImpozitul pe salariu este: " << impozitSalariu << "\nCNP-ul angajatului este: " << CNP <<
			"\nSalariul dupa impozitare este: " << salariu * (1 - impozitSalariu) << "\n\n";
	}
	friend ostream& operator<<(ostream& out, Angajat angajat)
	{
		angajat.afisare();
		return out;
	}
	//Functii prietene
	friend void afisareImpozitDinSalariu(Angajat x);
	friend void afisareSalariiCombinate(Angajat x, Angajat y);

	~Angajat()
	{
		if (this->nume != "NULL")
		{
			delete[]this->nume;
			this->nume = NULL;
		}
	}
	//Get-eri
	char* getNume() {
		return this->nume;
	}
	int getSalariu() {
		return this->salariu;
	}
	float getImpozit() {
		return impozitSalariu;
	}
	string getCNP() {
		return this->CNP;
	}
	//Set-eri
	void setNume(const char* nume)
	{
		if (this->nume != NULL) delete[]this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	void setSalariu(int salariu)
	{
		this->salariu = salariu;
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

	Moneda(const Moneda& moneda) : material(moneda.material)
	{
		this->forma = new char[strlen(moneda.forma) + 1];
		strcpy_s(this->forma, strlen(moneda.forma) + 1, moneda.forma);
		this->valoare = moneda.valoare;

	}
	void operator=(const Moneda& moneda)
	{
		if (this != &moneda)
		{
			this->forma = new char[strlen(moneda.forma) + 1];
			strcpy_s(this->forma, strlen(moneda.forma) + 1, moneda.forma);
			this->valoare = moneda.valoare;
		}
	}
	~Moneda()
	{
		if (this->forma != NULL)
			delete[]this->forma;
	}

	//Get-eri
	char* getForma() {
		return this->forma;
	}
	float getValoare() {
		return this->valoare;
	}
	string getMaterial() {
		return this->material;
	}
	string getValuta() {
		return valuta;
	}
	//Set-eri
	void setForma(const char* forma)
	{
		if (this->forma != NULL) delete[]this->forma;
		this->forma = new char[strlen(forma) + 1];
		strcpy_s(this->forma, strlen(forma) + 1, forma);
	}
	void setValoare(float valoare)
	{
		this->valoare = valoare;
	}
	static void setValuta(string valutaNoua)
	{
		valuta = valutaNoua;
	}

	void afisare()
	{
		cout << "Forma monedei este: " << forma << "\nValoarea este de: " << valoare << " " << valuta <<
			"\nMaterialul din care este realizata: " << material << "\n\n";
	}

	friend istream& operator>>(istream& input, Moneda &moneda) {
		cout << "Forma: ";
		if (moneda.forma) delete[]moneda.forma;
		moneda.forma = new char[10];
		input >> moneda.forma;
		cout << "Valoare: "; input >> moneda.valoare;
		cout << "Valuta: "; input >> moneda.valuta;

		return input;
	}
	friend ostream& operator<<(ostream& out, Moneda& moneda) {
		out << "Forma: ";
		out << moneda.forma;
		cout << "Valoare: "; out << moneda.valoare;
		cout << "Valuta: "; out << moneda.valuta;

		return out;
	}
	Moneda& operator+=(Moneda& moneda)
	{
		this->valoare += moneda.valoare;
		return(*this);
	}
	Moneda& operator+=(float val)
	{
		this->valoare += val;
		return(*this);
	}
	bool operator>(Moneda& moneda)
	{
		if (this->valoare > moneda.valoare) return true;
		return false;
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

	Bijuterie(const Bijuterie& bijuterie) : anConfectionare(bijuterie.anConfectionare)
	{
		this->tipBijuterie = bijuterie.tipBijuterie;
		this->tematica = bijuterie.tematica;
		this->nrMateriale = bijuterie.nrMateriale;
		if (this->nrMateriale > 0)
		{
			this->denumireMateriale = new char* [this->nrMateriale];
			for (int i = 0; i < nrMateriale; i++)
			{
				this->denumireMateriale[i] = new char[strlen(bijuterie.denumireMateriale[i]) + 1];
				strcpy_s(this->denumireMateriale[i], strlen(bijuterie.denumireMateriale[i]) + 1, bijuterie.denumireMateriale[i]);
			}
		}
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

	//Get-eri
	string getTipBijuterie() {
		return this->tipBijuterie;
	}
	string getTematica() {
		return this->tematica;
	}
	int getNrMateriale() {
		return this->nrMateriale;
	}
	char** getDenumireMateriale() {
		return this->denumireMateriale;
	}
	int getAnConfectionare() {
		return this->anConfectionare;
	}
	int getTVA() {
		return TVA;
	}
	void setTipBijuterie(string tipBijuterie) {
		this->tipBijuterie = tipBijuterie;
	}
	void setTematica(string tematica) {
		this->tematica = tematica;
	}
	void setDenumireMateriale(int nrMateriale, char** denumireMateriale)
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
		this->nrMateriale = nrMateriale;
		if (this->nrMateriale > 0)
		{
			this->denumireMateriale = new char* [(this->nrMateriale)];
			for (int i = 0; i < (this->nrMateriale); i++)
			{
				this->denumireMateriale[i] = new char[strlen(denumireMateriale[i]) + 1];
				strcpy_s(this->denumireMateriale[i], strlen(denumireMateriale[i]) + 1, denumireMateriale[i]);
			}
		}

	}
	static void setTVA(float tvaNou)
	{
		TVA = tvaNou;
	}
	void afisare()
	{
		cout << "Tipul Bijuteriei este: " << tipBijuterie << "\nTematica Bijuteriei este: " << tematica <<
			"\nAnul Confectionarii a fost: " << anConfectionare << "\nTVA-ul este de: " << TVA;
		if (nrMateriale != 0)
		{
			cout << "\nNr materiale folosite: " <<
				nrMateriale << "\nMaterialele folosite sunt: ";
			for (int i = 0; i < nrMateriale; i++)
				cout << denumireMateriale[i] << " ";
		}
		else cout << "\nNu exista materiale folosite!";
		cout << "\n\n";
	}

	friend istream& operator>>(istream& input, Bijuterie& bijuterie)
	{
		/*string tipBijuterie;
		string tematica;
		int nrMateriale;
		char** denumireMateriale;
		const int anConfectionare;
		static float TVA;*/
		cout << "\nTip bijuterie: "; input >> bijuterie.tipBijuterie;
		cout << "Tematica: "; input >> bijuterie.tematica;
		cout << "Nr materiale: "; input >> bijuterie.nrMateriale;
		bijuterie.denumireMateriale = new char* [bijuterie.nrMateriale];
		for (int i = 0; i < bijuterie.nrMateriale; i++)
		{
			bijuterie.denumireMateriale[i] = new char[20];
			cout << "Materialul " << i + 1 << " : "; input >> bijuterie.denumireMateriale[i];
		}
		cout << "TVA: "; input >> bijuterie.TVA;
		return input;
	}
	friend ostream& operator<<(ostream& out, Bijuterie& bijuterie)
	{
		cout << "Tipul Bijuteriei este: " << bijuterie.tipBijuterie << "\nTematica Bijuteriei este: " << bijuterie.tematica <<
			"\nAnul Confectionarii a fost: " << bijuterie.anConfectionare << "\nTVA-ul este de: " << TVA;
		if (bijuterie.nrMateriale != 0)
		{
			cout << "\nNr materiale folosite: " <<
				bijuterie.nrMateriale << "\nMaterialele folosite sunt: ";
			for (int i = 0; i < bijuterie.nrMateriale; i++)
				cout << bijuterie.denumireMateriale[i] << " ";
		}
		else cout << "\nNu exista materiale folosite!";
		cout << "\n\n";
		return out;
	}
	bool operator!=(Bijuterie bijuterie)
	{
		if (this->nrMateriale != bijuterie.nrMateriale) return true;
		return false;
	}
	
};
float Bijuterie::TVA = 0.19;

class Seif {
private:
	Moneda* monede;
	string denumireSeif;
	int nrMonede;
public:
	Seif()
	{
		this->nrMonede = 1;
		this->denumireSeif = "Seif Default";
		this->monede = new Moneda[this->nrMonede];
	}
	Seif(const Seif& seif)
	{
		this->nrMonede = seif.nrMonede;
		this->denumireSeif = seif.denumireSeif;
		this->monede = new Moneda[this->nrMonede];
	}
	void operator=(const Seif& seif) {
		if (this != &seif) {
			this->nrMonede = seif.nrMonede;
			this->denumireSeif = seif.denumireSeif;
			this->monede = new Moneda[this->nrMonede];
		}
	}
	friend istream& operator>>(istream& input, Seif& seif)
	{
		input >> seif.denumireSeif >> seif.nrMonede;
		if (seif.monede) delete[]seif.monede;
		seif.monede = new Moneda[seif.nrMonede];
		for (int i = 0; i < seif.nrMonede; i++)
			input >> seif.monede[i];
		return input;
	}
	friend ostream& operator<<(ostream& out, Seif& seif)
	{
		out << seif.denumireSeif << " " << seif.nrMonede << endl;
		for (int i = 0; i < seif.nrMonede; i++)
			out << seif.monede[i] << endl;
		return out;
	}
	int getNrMonede() {
		return this->nrMonede;
	}
	string getDenumire() {
		return this->denumireSeif;
	}
	Moneda* getMonede() {
		return this->monede;
	}
	void setMonede(int nrMonede, const Moneda* monede) {
		if (this->monede) delete[]this->monede;
		this->nrMonede = nrMonede;
		this->monede = new Moneda[this->nrMonede];
		for (int i = 0; i < this->nrMonede; i++)
			this->monede[i] = monede[i];
	}
	~Seif()
	{
		if (this->monede)
			delete[]this->monede;
	}

};

void afisareImpozitDinSalariu(Angajat x)
{
	cout << "\n\n\n\n" << x.salariu * x.impozitSalariu;
}
void afisareSalariiCombinate(Angajat x, Angajat y)
{
	cout << "\n\n\n\n" << x.salariu + y.salariu;
}

void afisareClasaAngajat()
{
	Angajat Marcel;
	Angajat Adrian("Adrian", 2000, "1234");
	Angajat Andrei("Andrei", "2341");
	/*Marcel.afisare();
	Adrian.afisare();
	Andrei.afisare();*/

	Angajat Gicu = Adrian;
	Angajat Testare;
	Testare.afisare();
	Testare = Adrian;
	Testare.afisare();

	//cout << Testare.getNume() << endl << Testare.getSalariu() << endl << Testare.getCNP() << endl << Testare.getImpozit() << endl;
	Testare.setNume("Padurarul Magic");
	//cout << Testare.getNume();

	//afisareImpozitDinSalariu(Adrian);
	//afisareSalariiCombinate(Adrian, Testare);
	Adrian = Adrian + Testare;
	cout << Adrian;
	Testare++;
	++Testare;
	cout << Testare;
	Angajat* npc;
	int nr; cout << "Cate npc-uri?: "; cin >> nr;
	npc = new Angajat[nr];
	for (int i = 0; i < nr; i++)
	{
		npc[i] = (++Testare);
	}
	for (int i = 0; i < nr; i++)
	{
		cout << npc[i];
	}


}
void afisareClasaMoneda()
{
	Moneda doiBani;
	Moneda cinciBani("Rotunda", 0.5, "Bronz");
	Moneda zeceBani("Patrata", 100);
	//doiBani.afisare();
	cinciBani.afisare();
	zeceBani.afisare();
	Moneda cinciZeciBani = cinciBani;
	cinciZeciBani.afisare();
	//cout << cinciZeciBani.getForma() << endl << cinciZeciBani.getValoare() << endl << cinciZeciBani.getMaterial() << endl <<
		//cinciZeciBani.getValuta() << endl;
	//cinciZeciBani.setForma("Tetrahexagonala");
	//cout << cinciZeciBani.getForma();
	/*cin >> cinciBani;
	cinciBani.afisare();
	cinciBani += 10.0;
	cinciBani.afisare();
	cinciBani += cinciBani;
	cinciBani.afisare();
	if (cinciBani > zeceBani) cout << "\nESTE MAI MARE\n";
	else cout << "\nNU ESTE MAI MARE\n";*/

	Moneda* xBani;
	cout << "Cati bani?: ";
	int bani; cin >> bani;
	xBani = new Moneda[bani];
	for (int i = 0; i < bani; i++)
		cin >> xBani[i];
	for (int i = 0; i < bani; i++)
		xBani[i].afisare();
	Moneda** matritaDeBani;
	matritaDeBani = new Moneda * [2];
	for (int i = 0; i < 2; i++)
	{
		matritaDeBani[i] = new Moneda[2];
		for (int j = 0; j < 2; j++)
			cin >> matritaDeBani[i][j];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			matritaDeBani[i][j].afisare();
	}

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


	/*Bijuterie lant;
	lant.afisare();*/
	Bijuterie inel("Inel", "Logodna", 2, materiale, 2023);
	inel.afisare();
	/*Bijuterie cercelObor("Cercel", "Copii", 2015);
	cercelObor.afisare();*/
	Bijuterie verigheta = inel;
	cout << verigheta;

	char** materiale1;
	materiale1 = new char* [3];
	materiale1[0] = new char[10];
	materiale1[1] = new char[10];
	materiale1[2] = new char[10];
	strcpy_s(materiale1[0], strlen("Argint") + 1, "Argint");
	strcpy_s(materiale1[1], strlen("Aur") + 1, "Aur");
	strcpy_s(materiale1[2], strlen("Diamant") + 1, "Diamant");

	char** testare = verigheta.getDenumireMateriale();
	int testareNrMateriale = verigheta.getNrMateriale();
	for (int i = 0; i < testareNrMateriale; i++)
		cout << testare[i] << endl;

	verigheta.setDenumireMateriale(3, materiale1);

	char** testare1 = verigheta.getDenumireMateriale();
	int testareNrMateriale1 = verigheta.getNrMateriale();
	for (int i = 0; i < testareNrMateriale1; i++)
		cout << testare1[i] << endl;

	/*Bijuterie test;
	cin >> test;
	cout << test;
	cout << (test != verigheta);*/

	Bijuterie* bijuterie;
	cout << "\nCate bijuterii trebuie citite?: ";
	int nrBijuterii;
	cin >> nrBijuterii;
	bijuterie = new Bijuterie[nrBijuterii];
	for (int i = 0; i < nrBijuterii; i++)
		cin >> bijuterie[i];
	for (int i = 0; i < nrBijuterii; i++)
		cout << bijuterie[i];
}

int main()
{
	//afisareClasaAngajat();
	//afisareClasaMoneda();
	//afisareClasaBijuterie();
	Seif s;
	cin >> s;
	cout << s;
}