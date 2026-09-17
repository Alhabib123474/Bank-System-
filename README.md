# Bank Management System (C++)

A console-based bank management system built in C++, simulating real-world banking operations for three types of users: **Clients**, **Employees**, and **Admins**. The project focuses on applying core **Object-Oriented Programming (OOP)** principles and **Data Structures** to build a role-based, file-persistent system from scratch.

## Features

- **Role-based access** — separate menus and permissions for Clients, Employees, and Admins.
- **Client operations** — deposit, withdraw, and transfer funds between accounts.
- **Employee operations** — add, search, edit, and list client accounts.
- **Admin operations** — manage employees in addition to full client management.
- **Input validation** — dedicated validation layer for names, passwords, balances, salaries, and numeric input (rejects invalid types and out-of-range values).
- **File-based persistence** — all client, employee, and admin data is saved to and loaded from text files, so data survives between program runs.
- **Menu navigation** — loop-safe menus with a "return to menu or exit" option after operations.

## Tech Stack

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (inheritance, polymorphism, encapsulation)
- **Data Structures:** `vector` (dynamic client/employee/admin storage), iterators for traversal and search
- **Persistence:** Custom file I/O layer (no external database)

## OOP Design

- `Person` — base class holding shared attributes (id, name, password) and common behavior.
- `Client`, `Employee`, `Admin` — derived classes extending `Person`, each with role-specific data and behavior (`Admin` further extends `Employee`).
- **Polymorphism** — each class overrides `display()` to show role-specific details.
- **Encapsulation** — private data members accessed only through validated setters/getters.
- **Interfaces** — a `DataSourceInterface` abstraction separates business logic from the file storage implementation (`FileManager`), making the persistence layer swappable.

## Project Structure

```
├── Person.h            # Base class for all user types
├── Client.h            # Client class + client operations (deposit, withdraw, transfer)
├── Employee.h          # Employee class + client management operations
├── Admin.h             # Admin class + employee/client management
├── Validation.h         # Input validation and console input helpers
├── Parser.h            # Parses raw file lines into Client/Employee/Admin objects
├── FileManager.h        # Handles reading/writing/updating data files
├── DataSourceInterface.h # Abstraction for data persistence
└── main.cpp             # Program entry point and menu flow
```

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   ```
2. Open the project in your preferred C++ IDE (Code::Blocks, Visual Studio, CLion, etc.) or compile directly:
   ```bash
   g++ main.cpp -o bank_system
   ./bank_system
   ```
3. Follow the on-screen menu to log in as a Client, Employee, or Admin and explore the available operations.

## What I Learned

Building this project involved debugging several subtle real-world issues, including:
- Correctly separating **validated input** (for new user data) from **trusted data loading** (for reading existing records from file), to avoid silently corrupting saved data.
- Avoiding **member variable shadowing** between base and derived classes.
- Writing safe **input validation loops** that handle both invalid values and non-numeric input without hanging or looping infinitely.
- Managing shared data structures (`vector`) accessed by pointer/reference across multiple classes to keep in-memory state and file state in sync.

## License

This project is open source and available under the [MIT License](LICENSE).
