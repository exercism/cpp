#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <cstddef>

class Bankaccount {
   public:
    void open() const;
    void deposit(size_t amount);
    void withdraw(size_t amount);
    size_t balance() const;

   private:
    size_t balance_{0};
};

#endif  // BANK_ACCOUNT_H