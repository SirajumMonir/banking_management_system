# Laxmi Chit Fund - System Architecture Document

## 1. High-Level Architecture Overview
The Laxmi Chit Fund Banking System utilizes a 3-Tier Layered Architecture Pattern designed for local terminal execution and decoupled data handling. This approach isolates user interactions from standard business rule parsing and persistent state serialization.

```
       +---------------------------------------------+
       |                 1. UI Layer                 |
       |     (main Event Loop & Switch Engine)       |
       +---------------------------------------------+
                              |
                              v (Passes Raw Parameters)
       +---------------------------------------------+
       |           2. Business Logic Layer           |
       |  (Abstract Account & Polymorphic Variants)  |
       +---------------------------------------------+
                              |
                              v (File Streaming I/O)
       +---------------------------------------------+
       |             3. Database Layer               |
       |       (bank_db.txt Persistent Ledger)       |
       +---------------------------------------------+
```

## 2. Layer Breakdowns

### I. User Interface (UI) Layer
* **Components:** Main terminal loop (`while(true)` structural layout) combined with a synchronous conditional engine (`switch-case`).
* **Responsibility:** Captures transactional operations (Investment entries, scheme setups, balance lookups) and passes primitives directly down to operational controllers.

### II. Business Logic Layer (BLL)
* **Components:** Polymorphic architecture abstractions consisting of `Account` (Base Interface), `SavingsAccount`, and `CurrentAccount`.
* **Responsibility:** Implements transactional logic routines. Enforces operational boundaries such as minimum balances for savings schemes and risk metrics for structural allocations without outside packages.

### III. Persistence & Database Layer
* **Components:** Local file handlers (`ifstream` and `ofstream`) targeted directly at a text-based storage array (`bank_db.txt`).
* **Responsibility:** Manages state data across application lifetimes. Synchronizes internal standard pointer structures (`std::vector<Account*>`) with local permanent disk records at startup and tear-down events.
