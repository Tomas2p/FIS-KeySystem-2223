#include "tools.hpp"

// Lee el menu de menus.art (de linea de inicio a linea final)
void ReadMenu(const int start, const int end) {
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

// Menu General
void GeneralMenu() {
  int option;
  clear();
  // Muestra el texto del menu
  ReadMenu(0, 12);
  std::cin >> option;
  switch (option) {
    case 1:
      /* code */
      break;
    case 2:
      /* code */
      break;
    case 3:
      /* code */
      break;
    case 4:
      /* code */
      break;
    case 5:
      /* code */
      break;
    case 6:
      /* code */
      break;

    default:
      break;
  }
}