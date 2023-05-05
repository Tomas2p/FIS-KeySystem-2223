#pragma once
// Funciones utiles para main.cpp
#include <fstream>
#include <iostream>

#include "keysystem.hpp"

// Limpia la pantalla
inline void clear() { system("clear"); }

// Lee el menu de menus.art (de linea de inicio a linea final)
void ReadMenu(const int start, const int end);

// Menu General
void GeneralMenu();