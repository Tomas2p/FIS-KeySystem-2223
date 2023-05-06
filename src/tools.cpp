#include "tools.hpp"

// Lee el menu de menus.txt (de linea de inicio a linea final)
void read(const int& start, const int& end) {
  std::ifstream File("src/menus.txt");
  std::string file_text;
  for (int i{0}; i < start; ++i) {
    getline(File, file_text);
  }
  std::cout << '\n';
  for (int i{start}; i < end; ++i) {
    getline(File, file_text);
    std::cout << file_text << (i == end - 1 ? "" : "\n");
  }
  File.close();
}

// Opciones menu login
void loginMenu(KeySystem& system, const unsigned& option) {
  User user;
  std::string name, password;
  switch (option) {
    case 1:  // Iniciar sesión
      std::cout << "###   Inicia sesión   ###\n\nUsuario >>> ";
      std::cin >> name;
      std::cout << "Contraseña >>> ";
      std::cin >> password;
      if (system.getUsers().data()->getName() == name &&
          system.getUsers().data()->getPassword() == password) {
        std::cout << "\nCredenciales correctas\n";
      } else {
        std::cout << "\nCredenciales incorrectas\n";
        optionsMenu(system, 0);
      }
      break;
    case 2:  // Registrarse
      std::cout << "###   Registrate   ###\n\nUsuario >>> ";
      std::cin >> name;
      std::cout << "Contraseña >>> ";
      std::cin >> password;
      if (system.getUsers().data()->getName() != name &&
          system.getUsers().data()->getPassword() != password) {
        std::cout << "\nSe ha registrado correctamente\n";
        user.setName(name);
        user.setPassword(password);
      } else {
        std::cout << "\nUsuario ya existente\n";
        optionsMenu(system, 0);
      }
      break;
    case 3:  // Salir
      break;
  }
}

// Opciones menu cerradura administrador
void keyAdminMenu(KeySystem& system, const unsigned& option) {}

// Opciones menu usuario
void userMenu(KeySystem& system, const unsigned& option) {}

// Opciones menu general administrador
void generalAdminMenu(KeySystem& system, const unsigned& option) {
  int option, ID_user, ID_key, password;
  std::string name;
  // Limpia y muestra el menu correspondiente
  clear(), readGeneralAdminMenu();
  std::cin >> option;
  switch (option) {
    case 1:  // Añadir llave
      std::cout << "Contraseña?";
      std::cin >> password;
      system.addKey(ID_key, password, 1);
      break;

    case 2:  // Mostrar llave
      system.showKeys();
      break;

    case 3:  // Seleccionar llave

      break;

    case 4:  // Añadir usuario
      std::cout << "Nombre?";
      std::cin >> name;
      system.addUser(name, ID_user, 1);
      ID_user++;
      break;

    case 5:  // Mostrar usuarios
      system.showUsers();
      break;

    case 6:  // Salir
      break;

    default:
      break;
  }
}

// Muestra el menu correspondiente o la logica (0=text; 1=logic)
void whichMenu(const unsigned& menu, const bool& logic, KeySystem& system,
               const unsigned& option) {
  switch (menu) {
    case 0:
      logic ? readLoginMenu() : loginMenu(system, option);
      break;
    case 1:
      logic ? readGeneralAdminMenu() : generalAdminMenu(system, option);
      break;
    case 2:
      logic ? readKeyAdminMenu() : keyAdminMenu(system, option);
      break;
    case 3:
      logic ? readUserMenu() : userMenu(system, option);
      break;
  }
}

// Opciones menu (0=loginMenu; 1=generalAdminMenu; 2=keyAdminMenu; 3=userMenu)
void optionsMenu(KeySystem& system, const unsigned& menu) {
  // Limpia y muestra el texto del menu correspondiente
  clear(), whichMenu(menu, 0, system, NULL);
  // Inicializa variables
  unsigned option;
  // Elige la opción del menu
  std::cin >> option;
  // Muestra la lógica del menu correspondiente
  whichMenu(menu, 1, system, option);
}