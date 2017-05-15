#include "functions.h"

void PolishLetters()
{
	locale locpl("Polish_Poland");
	locale::global(locpl);		
	cout.imbue(locpl);			
	cin.imbue(locpl);
}

void Controller()
{
	char choose;
	char chooseBF;
	double result = 0;
	double base_field = 0;
	double side_field = 0;

	bool fieldOrCircuit = false;
	bool fieldOrVolume = false;
	bool quit = false;

	do
	{
		system("cls");
		do
		{
			MainMenu();

			cout << "Wybieram: ";

			cin.clear();
			cin.sync();
			cin >> choose;

			if (choose >= 65 && choose <= 90 || choose >= 97 && choose <= 122)
			{
				break;
			}
			else
			{
				system("cls");
			}

		} while (true);

		system("cls");

		switch (choose)
		{
		case 'a':
		case 'A':
			fieldOrCircuit = FieldOrCircuit();
			result = Circle(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'b':
		case 'B':
			fieldOrCircuit = FieldOrCircuit();
			result = Square(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'c':
		case 'C':
			fieldOrCircuit = FieldOrCircuit();
			result = Rectangle(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'd':
		case 'D':
			fieldOrCircuit = FieldOrCircuit();
			result = Diamond(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'e':
		case 'E':
			fieldOrCircuit = FieldOrCircuit();
			result = Parellelogram(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'f':
		case 'F':
			fieldOrCircuit = FieldOrCircuit();
			result = Trapeze(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'g':
		case 'G':
			fieldOrCircuit = FieldOrCircuit();
			result = Triangle(fieldOrCircuit);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'h':
		case 'H':
			fieldOrVolume = FieldOrVolume();
			chooseBF = MenuOfBaseFields();
			cout << "Po wciœniêciu przycisku zostaniesz poproszony o podanie danych pola podstawy." << endl;
			_getch();
			base_field = BaseField(chooseBF);
			if (!fieldOrVolume)
			{
				cout << "Po wciœniêciu przycisku zostaniesz poproszony o podanie danych pola bocznego." << endl;
				_getch();
				side_field = SideField(chooseBF);
			}
			else
				side_field = 0;
			result = Pyramid(base_field, side_field, fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'i':
		case 'I':
			fieldOrVolume = FieldOrVolume();
			chooseBF = MenuOfBaseFields();
			cout << "Po wciœniêciu przycisku zostaniesz poproszony o podanie danych pola podstawy." << endl;
			_getch();
			base_field = BaseField(chooseBF);
			if (!fieldOrVolume)
			{
				cout << "Po wciœniêciu przycisku zostaniesz poproszony o podanie danych pola bocznego." << endl;
				_getch();
				side_field = SideField(chooseBF);
			}
			else
				side_field = 0;
			result = Prism(base_field, side_field, fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'j':
		case 'J':
			fieldOrVolume = FieldOrVolume();
			result = Cuboid(fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'k':
		case 'K':
			fieldOrVolume = FieldOrVolume();
			result = Sphere(fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'm':
		case 'M':
			fieldOrVolume = FieldOrVolume();
			result = Cylinder(fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'n':
		case 'N':
			fieldOrVolume = FieldOrVolume();
			result = Cone(fieldOrVolume);
			cout << "Wynik: " << result << "\n";
			_getch();
			break;
		case 'q':
		case 'Q':
			quit = true;
			break;
		}
	} while (!quit);
}

bool FieldOrCircuit()
{
	char choose;
	bool isNumber = false;
	do
	{
		system("cls");

		cout << "Wybierz czy liczyæ obwód czy pole:\n\n";
		cout << "1. Obwód.\n";
		cout << "2. Pole.\n\n";

		cout << "Wybieram: ";
		cin >> choose;
		if (choose >= 48 && choose <= 57)
			isNumber = true;
	} while (choose != '1' && choose != '2' && !isNumber);

	if (choose == '1')
		return true;
		
	return false;
}

bool FieldOrVolume()
{
	char choose;
	bool isNumber = false;
	do
	{
		system("cls");

		cout << "Wybierz czy liczyæ objêtoœæ czy pole:\n\n";
		cout << "1. Objêtoœæ.\n";
		cout << "2. Pole.\n\n";

		cout << "Wybieram: ";
		cin >> choose;
		if (choose >= 48 && choose <= 57)
			isNumber = true;
	} while (choose != '1' && choose != '2' && !isNumber);

	if (choose == '1')
		return true;

	return false;
}

double Circle(bool fieldOrCircuit)
{
	double result = 0;
	double r;

	do
	{
		system("cls");
		cout << "Podaj promieñ: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> r;
		if (!isnan(r) && r > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
		result = 2 * 3.14 * r;
	else
		result = 3.14 * r * r;

	return result;
}

double Square(bool fieldOrCircuit)
{
	double result = 0;
	double a;
	
	do
	{
		system("cls");
		cout << "Podaj rozmiar boku: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
		result = 4 * a;
	else
		result = a * a;

	return result;
}

double Rectangle(bool fieldOrCircuit)
{
	double result = 0;
	double a, b;

	do
	{
		system("cls");
		cout << "Podaj rozmiar boku A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj rozmiar boku B: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> b;
		if (!isnan(b) && b > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
		result = a + a + b + b;
	else
		result = a * b;

	return result;
}

double Diamond(bool fieldOrCircuit)
{
	double result = 0;
	double a, h;

	do
	{
		system("cls");
		cout << "Podaj bok A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj wyskoœæ H: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> h;
		if (!isnan(h) && h > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
		result = 4 * a;
	else
		result = a * h;

	return result;
}

double Parellelogram(bool fieldOrCircuit)
{
	double result = 0;
	double a, h;

	do
	{
		system("cls");
		cout << "Podaj bok A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj wyskoœæ H: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> h;
		if (!isnan(h) && h > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
		result = 4 * a;
	else
		result = a * h;

	return result;
}

double Trapeze(bool fieldOrCircuit)
{
	double result = 0;
	double a, b, c, d, h;

	do
	{
		system("cls");
		cout << "Podaj bok A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj bok B: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> b;
		if (!isnan(b) && b > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
	{
		do
		{
			system("cls");
			cout << "Podaj bok C: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> c;
			if (!isnan(c) && c > 0)
				break;

		} while (true);

		do
		{
			system("cls");
			cout << "Podaj bok D: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> d;
			if (!isnan(d) && d > 0)
				break;

		} while (true);
	}
	else
	{
		do
		{
			system("cls");
			cout << "Podaj wyskoœæ H: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> h;
			if (!isnan(h) && h > 0)
				break;

		} while (true);
	}
	

	if (fieldOrCircuit)
		result = a + b + c + d;
	else
		result = ((a+b) * h) / 2;

	return result;
}

double Triangle(bool fieldOrCircuit)
{

	double result = 0;
	double a, b, c, h = 0;

	do
	{
		system("cls");
		cout << "Podaj bok A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	if (fieldOrCircuit)
	{
		do
		{
			system("cls");
			cout << "Podaj bok B: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> b;
			if (!isnan(b) && b > 0)
				break;

		} while (true);

		do
		{
			system("cls");
			cout << "Podaj bok C: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> c;
			if (!isnan(c) && c > 0)
				break;

		} while (true);
	}
	else
	{
		do
		{
			system("cls");
			cout << "Podaj wyskoœæ H: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> h;
			if (!isnan(h) && h > 0)
				break;

		} while (true);
	}

	

	if (fieldOrCircuit)
		if (a + b > c)
			result = a + b + c;
		else
		{
			cout << "Niespelniono warunków tworzenia trójk¹ta, po wciœniêciu dowolnego klawisza nast¹pi powrót do menu." << endl;
			_getch();
			Controller();
		}
			
	else
		result = (a * h) / 2 ;

	return result;
}

double Pyramid(double base_field, double side_field, bool fieldOrVolume)
{
	double result = 0;
	double h;

	if (fieldOrVolume)
	{

		do
		{
			system("cls");
			cout << "Podaj wysokoœæ ostros³upa: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> h;
			if (!isnan(h) && h > 0)
				break;

		} while (true);

		result = (base_field / 3) * h;
	}	
	else
	{
		result = base_field + (side_field * h);
	}
		

	return result;
}

double Prism(double base_field, double side_field, bool fieldOrVolume)
{
	double result = 0;
	double h;

	if (fieldOrVolume)
	{
		do
		{
			system("cls");
			cout << "Podaj wysokoœæ granaistos³upa: ";
			cin.clear();
			cin.sync();
			cin.ignore();
			cin >> h;
			if (!isnan(h) && h > 0)
				break;

		} while (true);

		result = base_field * h;
	}	
	else
		result = (2 * base_field) + (side_field);

	return result;
}

double Cuboid(bool fieldOrVolume)
{
	double a, b, c, result;

	do
	{
		system("cls");
		cout << "Podaj bok A: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> a;
		if (!isnan(a) && a > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj bok B: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> b;
		if (!isnan(b) && b > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj bok C: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> c;
		if (!isnan(c) && c > 0)
			break;

	} while (true);

	if (fieldOrVolume)
		result = a * b * c;
	else
		result = 2 * ((a*b) + (a*c) + (b*c));

	return result;
}

double Sphere(bool fieldOrVolume)
{
	double result = 0;
	double r;

	do
	{
		system("cls");
		cout << "Podaj promieñ: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> r;
		if (!isnan(r) && r > 0)
			break;

	} while (true);

	if (fieldOrVolume)
		result = 4/3 * 3.14 * r * r * r;
	else
		result = 4 * 3.14 * r * r;

	return result;
}

double Cylinder(bool fieldOrVolume)
{

	double result = 0;
	double r, h;

	do
	{
		system("cls");
		cout << "Podaj promieñ: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> r;
		if (!isnan(r) && r > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj wysokoœæ: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> h;
		if (!isnan(h) && h > 0)
			break;

	} while (true);

	if (fieldOrVolume)
		result = (3.14 * r * r) * h;
	else
		result = (2 * 3.14 * r * r) + (2 * 3.14 * r * h);

	return result;
}

double Cone(bool fieldOrVolume)
{
	double result = 0;
	double r, h, l;

	do
	{
		system("cls");
		cout << "Podaj promieñ R: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> r;
		if (!isnan(r) && r > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj wysokoœæ H: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> h;
		if (!isnan(h) && h > 0)
			break;

	} while (true);

	do
	{
		system("cls");
		cout << "Podaj brzeg L: ";
		cin.clear();
		cin.sync();
		cin.ignore();
		cin >> l;
		if (!isnan(l) && l > 0)
			break;

	} while (true);

	if (fieldOrVolume)
		result = ((3.14 * r * r)/3) * h;
	else
		result = (3.14 * r * r) + (3.14 * r * l);

	return result;
}

double SideField(char choose)
{
	double result = 0;


	system("cls");

	switch (choose)
	{
	case 'a':
	case 'A':
		result = Rectangle(true);
		break;
	case 'b':
	case 'B':
		result = Diamond(true);
		break;
	case 'c':
	case 'C':
		result = Parellelogram(true);
		break;
	case 'd':
	case 'D':
		result = Trapeze(true);
		break;
	case 'e':
	case 'E':
		result = Triangle(true);
		break;
	}
	return result;
}

double BaseField(char choose)
{
	double result = 0;
	

	system("cls");

	switch (choose)
	{
	case 'a':
	case 'A':
		result = Rectangle(false);
		break;
	case 'b':
	case 'B':
		result = Diamond(false);
		break;
	case 'c':
	case 'C':
		result = Parellelogram(false);
		break;
	case 'd':
	case 'D':
		result = Trapeze(false);
		break;
	case 'e':
	case 'E':
		result = Triangle(false);
		break;
	}
	return result;
}

char MenuOfBaseFields()
{
	char choose;
	system("cls");
	do
	{
		cout << "Wybierz figurê która jest podstaw¹ bry³y:\n\n";
		cout << "A. Prostok¹t.\n";
		cout << "B. Romb.\n";
		cout << "C. Równoleg³obok\n";
		cout << "D. Trapez.\n";
		cout << "E. Trójk¹t.\n";

		cout << "Wybieram: ";

		cin.clear();
		cin.sync();
		cin >> choose;

		if (choose >= 65 && choose <= 69 || choose >= 97 && choose <= 101)
		{
			break;
		}
		else
		{
			system("cls");
		}

	} while (true);

	return choose;
}

void MainMenu()
{
	cout << "Wybierz figurê lub bry³ê:\n\n";
	cout << "A. Ko³o.\n";
	cout << "B. Kwadrat.\n";
	cout << "C. Prostok¹t.\n";
	cout << "D. Romb.\n";
	cout << "E. Równoleg³obok\n";
	cout << "F. Trapez.\n";
	cout << "G. Trójk¹t.\n";
	cout << "H. Ostros³up.\n";
	cout << "I. Graniastos³up.\n";
	cout << "J. Prostopad³oœcian.\n";
	cout << "K. Kula.\n";
	cout << "M. Walec.\n";
	cout << "N. Sto¿ek.\n";
	cout << "Q. Wyjœcie.\n";
}

