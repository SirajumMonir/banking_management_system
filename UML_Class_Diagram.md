# Laxmi Chit Fund - UML Class Diagram Explanation

## 1. Visual Object Layout Model

```text
+-------------------------------------------------------------+
|                          Account                            |  <--- [Abstract Base Class]
+-------------------------------------------------------------+
| # accNumber: string                                         |  (# = Protected Fields)
| # balance: double                                           |  (Encapsulation Target)
| # type: string                                              |
+-------------------------------------------------------------+
| + Account(num: string, initialBalance: double, t: string)   |  (+ = Public Interface)
| + virtual ~Account()                                        |
| + getAccountNumber(): string                                |  (Getter Method)
| + getBalance(): double                                      |  (Getter Method)
| + getType(): string                                         |
| + deposit(amount: double): void                             |
| + virtual withdraw(amount: double): void = 0                |  (Pure Virtual - Abstraction)
| + virtual displayDetails(): void                            |
+-------------------------------------------------------------+
                               ^
                               |
                        [ Inheritance ]
                               |
        +----------------------+----------------------+
        |                                             |
+-----------------------------------+   +-----------------------------------+
|          SavingsAccount           |   |          CurrentAccount           |
+-----------------------------------+   +-----------------------------------+
| - minBalance: double (1000.0)     |   |                                   |
+-----------------------------------+   +-----------------------------------+
| + SavingsAccount(num, initialBal) |   | + CurrentAccount(num, initialBal) |
| + withdraw(amount): void override |   | + withdraw(amount): void override |
| + displayDetails(): void override |   | + displayDetails(): void override |
+-----------------------------------+   +-----------------------------------+
                  \                                       /
                   \                                     /
                    +-----------------+-----------------+
                                      |
                               [ Polymorphism ]
                                      |
                                      v
                    +----------------------------------+
                    |       std::vector<Account*>      |  <--- [ Central In-Memory DB ]
                    +----------------------------------+
```

## 2. Object-Oriented Blueprint Matrix

* **Abstraction:** Realized through the pure virtual declaration `Account::withdraw() = 0`. Prevents illegal allocation of basic abstract entities and isolates interface invocation from child execution parameters.
* **Encapsulation:** Protects mutable runtime variables (`accNumber`, `balance`) by setting access boundaries to `protected`. State alterations can only occur via predefined domain access controls like `deposit()`.
* **Inheritance:** `SavingsAccount` and `CurrentAccount` extend `Account` via `public` access modification, gaining full base structures automatically while reducing functional drift.
* **Polymorphism:** Achieved via dynamic binding layout parameters. Base pointer registries (`Account*`) track execution locations dynamically at runtime, matching user references to accurate overridden concrete logic loops.
