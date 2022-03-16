# Instructions

Simulate a bank account supporting opening/closing, withdrawals, and deposits
of money. Watch out for concurrent transactions!

A bank account can be accessed in multiple ways. Clients can make
deposits and withdrawals using the internet, mobile phones, etc. Shops
can charge against the account.

Create an account that can be accessed from multiple threads/processes
(terminology depends on your programming language).

It should be possible to open and also reopen an account; reopening an account 
resets the balance to 0.

It should be possible to close an account; operations against a closed
account must fail.

It should not be possible to have a negative balance on an account.