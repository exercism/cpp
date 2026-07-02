#pragma once

namespace Bankaccount {
class Bankaccount {
  public:
    Bankaccount() {
    }

    void open();
    void close();
    void deposit(int amount);
    int balance();
    void withdraw();
 private:
   bool is_open_ = false;
   int amount_;
    
    
    

};  // class Bankaccount

}  // namespace Bankaccount
