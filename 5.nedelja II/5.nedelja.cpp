// 5.nedelja.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
enum trenutno_stanje {ISKLJUCEN = 1, UKLJUCEN, POKVAREN};


class Televizor
{
public:
	Televizor();
	Televizor(trenutno_stanje,int, int);
	Televizor(const Televizor* );
	bool ukljuci();
	bool iskljuci();
	bool pokvari();
	bool popravi();
	bool pojacajZvuk();
	bool smanjiZvuk();
	bool sledeciKanal();
	bool prethodniKanal();
	trenutno_stanje getStanje() const;
	int getZvuk() const;
	int getKanal() const;
	void ispis();

private:
	trenutno_stanje stanje_televizora;
	int trenutni_zvuk;
	int trenutni_kanal;
};

Televizor::Televizor()
{
	stanje_televizora = ISKLJUCEN;
	trenutni_zvuk = 0;
	trenutni_kanal = 1;
}

Televizor::Televizor(trenutno_stanje stanje, int zvuk, int kanal)
{
	stanje_televizora = stanje;
	trenutni_zvuk = zvuk;
	trenutni_kanal = kanal;
}
Televizor::Televizor(const Televizor* o)
{
	stanje_televizora = o->stanje_televizora;
	trenutni_zvuk = o->trenutni_zvuk;
	trenutni_kanal = o->trenutni_kanal;
}
bool Televizor::ukljuci() {
	if (getStanje() == ISKLJUCEN) {
		stanje_televizora = UKLJUCEN;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::iskljuci() {
	if (getStanje() == UKLJUCEN) {
		stanje_televizora = ISKLJUCEN;
		trenutni_zvuk = 0;
		trenutni_kanal = 1;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::pokvari() {
	if (getStanje() != POKVAREN) {
		stanje_televizora = POKVAREN;
		trenutni_zvuk = 0;
		trenutni_kanal = 1;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::popravi() {
	if (getStanje() == POKVAREN) {
		stanje_televizora = ISKLJUCEN;
		trenutni_zvuk = 0;
		trenutni_kanal = 1;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::pojacajZvuk() {
	if (stanje_televizora != UKLJUCEN) {
		return 1;
	}
	if (trenutni_zvuk < 20) {
		trenutni_zvuk++;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::smanjiZvuk() {
	if (stanje_televizora != UKLJUCEN) {
		return 1;
	}
	if (trenutni_zvuk > 0) {
		trenutni_zvuk--;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::sledeciKanal() {
	if (stanje_televizora != UKLJUCEN) {
		return 1;
	}
	if (trenutni_kanal < 5) {
		trenutni_kanal++;
		return 0;
	}
	else {
		return 1;
	}
}
bool Televizor::prethodniKanal() {
	if (stanje_televizora != UKLJUCEN) {
		return 1;
	}
	if (trenutni_kanal > 1) {
		trenutni_kanal--;
		return 0;
	}
	else {
		return 1;
	}
}
trenutno_stanje Televizor::getStanje()const {
	return stanje_televizora;
}
int Televizor::getZvuk()const {
	return trenutni_zvuk;
}
int Televizor::getKanal()const {
	return trenutni_kanal;
}
void Televizor::ispis() {
	std::cout << "Televizor je trenutno ";
	switch (stanje_televizora) {
	case 1:{
		std::cout << "iskljucen." << std::endl;
	break;
		}
	case 2:{
		std::cout << "ukljucen." << std::endl;
	break;
		}
	case 3:{
		std::cout << "pokvaren." << std::endl;
	break;
		}
	}
	
	std::cout << "Trenutan zvuk je " << getZvuk() << std::endl;
	std::cout << "Trenutni kanal je " << getKanal() << std::endl;
}

void meni(Televizor* tel) {
	int n = 100;
	do {
		std::cout << std::endl << std::endl<< "Unesite 1 da ukljucite televizor. " << std::endl;
		std::cout << "Unesite 2 da iskljucite televizor. " << std::endl;
		std::cout << "Unesite 3 da pokvarite televizor. " << std::endl;
		std::cout << "Unesite 4 da popravite televizor. " << std::endl;
		std::cout << "Unesite 5 da smanjite zvuk. " << std::endl;
		std::cout << "Unesite 6 da pojacate zvuk. " << std::endl;
		std::cout << "Unesite 7 da prebacite na prethodni kanal. " << std::endl;
		std::cout << "Unesite 8 da prebacite na sledeci kanal. " << std::endl;
		std::cout << "Unesite 9 da prikazete trenutni televizor. " << std::endl;
		std::cout << "Unesite 0 da izadjete iz programa. " << std::endl << std::endl;
		std::cin >> n;

		switch (n) {
		case 1: {
			if (tel->ukljuci()) {
				std::cout << "Televizor je vec ukljucen ili je pokvaren!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste ukljlucili televizor." << std::endl;
			}
			break;
		}
		case 2: {
			if (tel->iskljuci()) {
				std::cout << "Televizor je vec iskljucen ili je pokvaren!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste iskljucili televizor." << std::endl;
			}
			break;
		}
		case 3: {
			if (tel->pokvari()) {
				std::cout << "Televizor je vec pokvaren!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste pokvarili televizor." << std::endl;
			}
			break;
		}
		case 4: {
			if (tel->popravi()) {
				std::cout << "Televizor nije pokvaren!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste popravili televizor." << std::endl;
			}
			break;
		}
		case 5: {
			if (tel->smanjiZvuk()) {
				std::cout << "Televizor je na minimalnom zvuku, ili nije ukljucen!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste smanjili zvuk." << std::endl;
			}
			break;
		}
		case 6: {
			if (tel->pojacajZvuk()) {
				std::cout << "Televizor je na maximalnom zvuku, ili nije ukljucen!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste povecali zvuk." << std::endl;
			}
			break;
		}
		case 7: {
			if (tel->prethodniKanal()) {
				std::cout << "Televizor je na kanalu 1, ili nije ukljucen!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste prebacili kanal." << std::endl;
			}
			break;
		}
		case 8: {
			if (tel->sledeciKanal()) {
				std::cout << "Televizor je na kanalu 5, ili nije ukljucen!" << std::endl;
			}
			else {
				std::cout << "Uspesno ste promenili kanal." << std::endl;
			}
			break;
		}
		case 9: {
			tel->ispis();
			break;
		}
		case 0: {
			break;
		}
		default: {
			std::cout << "Uneli ste pogresan broj operacije!!!" << std::endl;
			std::fflush(stdin);
			continue;
		}
		}


	} while (n != 0);
	std::cout << "Kraj" << std::endl;
	return;
}

int main()
{
	Televizor tel1;
	Televizor tel2(UKLJUCEN,5,3);
	Televizor tel3(tel2);
	meni(&tel3);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
