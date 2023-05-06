#pragma once
// Gestión de la clase user (user.hpp)
#include <iostream>
#include <string>

class User {
 public:
  // Constructor vacio
  User() : id_(count_id_users++) {}
  // Constructor usuario normal
  User(const std::string& name, const std::string& password)
      : name_(name), password_(password), id_(count_id_users++) {}

  // Getters y Setters
  std::string getName() const { return name_; }
  void setName(const std::string& name) { name_ = name; }
  std::string getPassword() const { return password_; }
  void setPassword(const std::string& password) { password_ = password; }
  unsigned getId() const { return id_; }
  unsigned getAccessLevel() const { return access_level_; }

  static unsigned count_id_users;

 private:
  // Nombre del usuario
  std::string name_;
  // Contraseña del usuario
  std::string password_;
  // ID del usuario
  unsigned id_;
  // Nivel de acceso del usuario (0=normal; 1=administrador)
  unsigned access_level_;
};