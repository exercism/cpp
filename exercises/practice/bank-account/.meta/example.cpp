#include "example.h"

void Bankaccount::open() const { return; }

void Bankaccount::deposit(size_t amount) { balance_ += amount; }

void Bankaccount::withdraw(size_t amount) { balance_ -= amount; }

size_t Bankaccount::balance() const { return balance_; }