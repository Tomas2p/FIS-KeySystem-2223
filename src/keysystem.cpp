// Funciones de la clase KEY
#include "keysystem.hpp"

/*
// Notifica el uso de la cerradura
void KeySystem::notify() {
  std::cout << "Notificación: La cerradura está siendo accedida." << '\n';
}
*/

// Añade un usuario al sistema
void KeySystem::addUser(User& user) {
  user.setId(id_users_++);
  this->users_.reserve(1);
  this->users_.emplace_back(user);
  user_map_[user.getId()] = users_.size() - 1;
}

// Añade una llave al sistema
void KeySystem::addKey(Key& key) {
  key.setId(id_keys_++);
  this->keys_.reserve(1);
  this->keys_.emplace_back(key);
  key_map_[key.getId()] = keys_.size() - 1;
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
  std::cout << "###   Llaves   ###\n\n";
  if (keys_.empty()) std::cout << "No hay llaves aún.\n";
  for (auto key : keys_) {
    std::cout << "ID/Contraseña/Estado: " << key.getId() << '/';
    for (int i{0}; i < key.getPassword().length(); ++i) std::cout << '*';
    std::cout << '/' << (key.getState() ? "Abierta" : "Cerrada");
    std::cout << '\n';
  }
}

// Muestra las cerraduras a las que puede aceder un usuario
void KeySystem::showKeysUser(const unsigned& id_user) {
  std::cout << "###   Llaves con accesso   ###\n\n";
  if (keys_.empty()) std::cout << "No hay llaves aún.\n";
  for (auto key : keys_) {
    for (auto access : key.getUsers()) {
      if (access.second == 1) {
        std::cout << "ID/Contraseña/Estado: " << key.getId() << '/';
        for (int i{0}; i < key.getPassword().length(); ++i) std::cout << '*';
        std::cout << '/' << (key.getState() ? "Abierta" : "Cerrada");
        std::cout << '\n';
      }
    }
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

// Devuelve la pos en vector a la id buscada en mapa
int KeySystem::findVectorById(unsigned id,
                              std::unordered_map<unsigned, unsigned> map) {
  if (map.count(id) > 0) {
    return map[id];
  }
  // No se encuentra
  return -1;
}
