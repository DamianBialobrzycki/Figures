#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

void PolishLetters();

void Controller();
void MainMenu();
char MenuOfBaseFields();

bool FieldOrCircuit();
bool FieldOrVolume();

double Circle(bool fieldOrCircuit);
double Square(bool fieldOrCircuit);
double Rectangle(bool fieldOrCircuit);
double Diamond(bool fieldOrCircuit);
double Parellelogram(bool fieldOrCircuit);
double Trapeze(bool fieldOrCircuit);
double Triangle(bool fieldOrCircuit);
double Pyramid(double base_field, double side_field, bool fieldOrVolume);
double Prism(double base_field, double side_field, bool fieldOrVolume);
double Cuboid(bool fieldOrVolume);
double Sphere(bool fieldOrVolume);
double Cylinder(bool fieldOrVolume);
double Cone(bool fieldOrVolume);

double BaseField(char choose);
double SideField(char choose);
