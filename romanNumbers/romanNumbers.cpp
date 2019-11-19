#pragma once

#include <iostream>
#include "romanNumbers.h"

#include <string>
#include <algorithm>
#include <stdexcept>


int Roman::toInt_(std::string s, int acc) {
	if (s.empty()) return acc;
	else if (std::toupper(s[0]) == 'I') {
		int d = acc % 10;
		if (d < 3 || (d > 4 && d < 8)) {
			return Roman::toInt_(s.substr(1), acc + 1);
		}
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'V') {
		int d = acc % 10;
		if (d == 0) {
			return Roman::toInt_(s.substr(1), acc + 5);
		}
		else if (d == 1) {
			return Roman::toInt_(s.substr(1), acc + 3);
		}
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'X') {
		int d = acc % 100;
		if (d == 0 || d == 10 || d == 20 || d == 50 || d == 60 || d == 70)
			return Roman::toInt_(s.substr(1), acc + 10);
		else if (d % 10 == 1)
			return toInt_(s.substr(1), acc + 8);
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'L') {
		int d = acc % 100;
		if (d == 0)
			return toInt_(s.substr(1), acc + 50);
		else if (d == 10)
			return toInt_(s.substr(1), acc + 30);
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'C') {
		int d = acc % 1000;
		if (d == 0 || d == 100 || d == 200 || d == 500 || d == 600 || d == 700)
			return toInt_(s.substr(1), acc + 100);
		else if (d % 100 == 10)
			return toInt_(s.substr(1), acc + 80);

		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'D') {
		int d = acc % 1000;
		if (d == 0)
			return toInt_(s.substr(1), acc + 500);
		else if (d == 100)
			return toInt_(s.substr(1), acc + 300);
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else if (std::toupper(s[0]) == 'M') {
		int d = acc % 1000;
		if (d == 0)
			return toInt_(s.substr(1), acc + 1000);
		else if (d == 100)
			return toInt_(s.substr(1), acc + 800);
		else throw std::invalid_argument("The string is not a Roman number");
	}
	else throw std::invalid_argument("The string is not a Roman number");
}

int Roman::toInt(std::string s) {
	return Roman::toInt_(s, 0);
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
