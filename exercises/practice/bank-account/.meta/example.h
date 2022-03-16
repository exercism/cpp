#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>

namespace Bankaccount {
class Bankaccount {
   public:
    void open();
    void deposit(int amount);
    void withdraw(int amount);
    void close();
    int balance();

   private:
    void check_account_open() const;
    void check_amount_greater_zero(int amount) const;

    int balance_{0};
    bool open_{false};
    std::mutex mutex_{};
};
}  // namespace Bankaccount
#endif  // BANK_ACCOUNT_H