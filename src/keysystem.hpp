#pragma once
// Gestión de la clase KeySystem -> Gestionar cerradura y usuarios

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "key.hpp"
#include "user.hpp"

class KeySystem {
 public:
  // Añadir usuario
  void addUser(User& user);
  // Eliminar usuario
  void delUser(const User& user);

  // Añadir cerradura
  void addKey(Key& key);
  // Eliminar cerradura
  void delKey(const Key& key);

  // Añadir usuario a cerradura
  void addUserToKey(Key& key, const User& user);

  // Abrir cerradura
  void openKey(Key& key, const User& user);
  // Cerrar cerradura
  void closeKey(Key& key, const User& user);

  // Muestra las cerraduras
  void showKeys();
  // Muestra las cerraduras a las que puede aceder un usuario
  void showKeysUser(const unsigned& id_user);
  // Muestra los usuarios
  void showUsers();

  // Devuelve la pos en vector a la id buscada en mapa
  int findVectorById(unsigned id, std::unordered_map<unsigned, unsigned> map);

  /*
  void setEncryptedCard(std::vector<int>& encrypted_card);
  void notify();
  void setTemporalAccess(const User& user, int minutes);
   */

  // Getters y setters
  std::vector<User> getUsers() const { return users_; }
  std::vector<Key> getKeys() const { return keys_; }
  std::unordered_map<unsigned, unsigned> getUserMap() const {return user_map_;}
  std::unordered_map<unsigned, unsigned> getKeyMap() const {return key_map_;}

 private:
  // Cerraduras
  std::vector<Key> keys_;
  std::unordered_map<unsigned, unsigned> key_map_;
  // Id cerraduras
  unsigned id_keys_{1};

  // Usuarios
  std::vector<User> users_;
  std::unordered_map<unsigned, unsigned> user_map_;
  // Id usuarios
  unsigned id_users_{1};
};
