// Funciones de la clase KEY
#include "keysystem.hpp"

/*
// Notifica el uso de la cerradura
void KeySystem::notify() {
  std::cout << "Notificación: La cerradura está siendo accedida." << '\n';
}
*/

// Añade un usuario al sistema
void KeySystem::addUser(const std::string& name, const unsigned& id,
                        const unsigned& access_level) {
  User new_user(name, id, access_level);
  this->users_.reserve(1);
  this->users_.emplace_back(new_user);
}

// Añade una llave al sistema
void KeySystem::addKey(const unsigned& id, const std::string& password,
                       const User& user) {
  Key new_key(id, password, user);
  this->keys_.reserve(1);
  this->keys_.emplace_back(new_key);
}

// Eliminar usuario
void KeySystem::delUser(const User& user) {
  for (auto i{users_.begin()}; i != users_.end(); ++i) {
    if (i->getId() == user.getId()) {
      users_.erase(i);
    }
  }
}

// Eliminar cerradura
void KeySystem::delKey(const Key& key) {
  for (auto i{keys_.begin()}; i != keys_.end(); ++i) {
    if (i->getId() == key.getId()) {
      keys_.erase(i);
    }
  }
}

// Añadir usuario a cerradura
void KeySystem::addUserToKey(Key& key, const User& user) {
  key.setUserAccess(user, 1);
}

// Abrir cerradura
void KeySystem::openKey(Key& key, const User& user) { key.open(user); }
// Cerrar cerradura
void KeySystem::closeKey(Key& key, const User& user) { key.close(user); }

// Muestra las cerraduras
void KeySystem::showKeys() {
  std::cout << "\t###   Llaves   ###\n";
  if (keys_.empty()) std::cout << "No hay llaves aún.\n";
  for (auto key : keys_) {
    std::cout << "ID/Contraseña/Estado: " << key.getId() << '/';
    for (int i{0}; i < key.getPassword().length(); ++i) std::cout << '*';
    std::cout << '/' << (key.getState() ? "Abierta" : "Cerrada");
    std::cout << '\n';
  }
}

// Muestra los usuarios
void KeySystem::showUsers() {
  std::cout << "\t###   Usuarios   ###\n";
  if (users_.empty()) std::cout << "No hay usuarios aún.\n";
  for (auto usuario : users_)
    std::cout << "Nombre/ID: " << usuario.getName() << '/' << usuario.getId()
              << '\n';
}