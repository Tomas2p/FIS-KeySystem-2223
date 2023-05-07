#include <fstream>

#include "keysystem.hpp"
#include "tools.hpp"

int main(int argc, char* argv[]) {
  // Inicializa variables
  KeySystem system;
  // Usuario de prueba
  User admin("test", "1234", 0);
  system.addUser(admin);
  // Cerradura de prueba
  Key key_test("1234", admin);
  system.addKey(key_test);
  // Muestra el menu login
  optionsMenu(system, 0, 0);

  return 0;
}