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

// Pausa por los segundos introducidos
void pause(const unsigned seconds) {
#ifdef _WIN32
  Sleep(seconds * 1000);
#else
  sleep(seconds);
#endif
}

// Opciones menu login
void loginMenu(KeySystem& system, const unsigned& option) {
  clear();
  User user;
  // Usuario de prueba
  User admin_user("admin", "admin", 1);
  system.addUser(admin_user);
  std::string name, password, is_admin;
  switch (option) {
    case 1:  // Iniciar sesión
      std::cout << "###   Inicia sesión   ###\n\nUsuario >>> ";
      std::cin >> name;
      std::cout << "Contraseña >>> ";
      std::cin >> password;
      for (int i{0}; i < system.getUsers().size(); ++i) {
        if (system.getUsers()[i].getName() == name &&
            system.getUsers()[i].getPassword() == password) {
          std::cout << "\nCredenciales correctas\n";
          pause(5);
          // Muestra el adminGeneralMenu si accesslevel es 0 o userMenu si 1
          optionsMenu(system, system.getUsers()[i].getAccessLevel() ? 1 : 3);
        } else {
          std::cout << "\nCredenciales incorrectas\n";
          pause(5);
          optionsMenu(system, 0);
        }
      }
      break;
    case 2:  // Registrarse
      std::cout << "###   Registrate   ###\n\nUsuario >>> ";
      std::cin >> name;
      std::cout << "Contraseña >>> ";
      std::cin >> password;
      std::cout << "Administrador(s/n) >>> ";
      std::cin >> is_admin;
      for (int i{0}; i < system.getUsers().size(); ++i) {
        if (system.getUsers()[i].getName() != name &&
            system.getUsers()[i].getPassword() != password) {
          std::cout << "\nSe ha registrado correctamente\n";
          user.setName(name);
          user.setPassword(password);
          user.setAccessLevel(is_admin == "s" ? 1 : 0);
          system.addUser(user);
          // Muestra el adminGeneralMenu si accesslevel es 0 o userMenu si 1
          optionsMenu(system, system.getUsers().back().getAccessLevel() ? 1 : 3);
        } else {
          std::cout << "\nUsuario ya existente\n";
          optionsMenu(system, 0);
        }
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
  /* int ID_user, ID_key, password;
  std::string name;
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

    case 4:  // Mostrar usuarios
      system.showUsers();
      break;

    case 5:  // Salir
      break;

    default:
      break;
  } */
}

// Muestra el menu correspondiente o la logica (0=text; 1=logic)
void whichMenu(const unsigned& menu, const bool& logic, KeySystem& system,
               const unsigned& option) {
  switch (menu) {
    case 0:
      !logic ? readLoginMenu() : loginMenu(system, option);
      break;
    case 1:
      !logic ? readGeneralAdminMenu() : generalAdminMenu(system, option);
      break;
    case 2:
      !logic ? readKeyAdminMenu() : keyAdminMenu(system, option);
      break;
    case 3:
      !logic ? readUserMenu() : userMenu(system, option);
      break;
  }
}

// Opciones menu (0=loginMenu; 1=generalAdminMenu; 2=keyAdminMenu; 3=userMenu)
void optionsMenu(KeySystem& system, const unsigned& menu) {
  // Limpia y muestra el texto del menu correspondiente
  clear(), whichMenu(menu, 0, system, 0);
  // Inicializa variables
  unsigned option;
  // Elige la opción del menu
  std::cin >> option;
  // Muestra la lógica del menu correspondiente
  whichMenu(menu, 1, system, option);
}