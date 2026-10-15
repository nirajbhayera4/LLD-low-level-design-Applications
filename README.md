# Low-Level Design Applications

A collection of standalone C++ examples that demonstrate object-oriented design patterns through small, practical programs.

## Examples

| File | Concept | What it demonstrates |
| --- | --- | --- |
| `SimpleFactoryDesign.cpp` | Simple Factory | Creates basic or special burgers from a requested type. |
| `FactoryMethod.cpp` | Factory Method | Lets different burger brands create their own burger variants through a shared factory interface. |
| `AbsFactoryMethod.cpp` | Abstract Factory | Creates related burger and garlic bread products for a selected meal brand. |
| `StrategyDesignPattern.cpp` | Strategy | Composes robot behavior from interchangeable walking and flying strategies. |
| `GoogleDocs.cpp` | Document editor example | Combines document elements with interchangeable persistence implementations (file or database). |

Each source file has its own `main()` and can be compiled and run independently.

## Requirements

- A C++ compiler with C++11 support or later
- A terminal in the project directory

## Build and run

Compile an example with `g++` (replace the filename and output name as needed):

```bash
g++ -std=c++11 -Wall -Wextra -pedantic SimpleFactoryDesign.cpp -o simple_factory
./simple_factory
```

For example, build the abstract factory example with:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic AbsFactoryMethod.cpp -o abstract_factory
./abstract_factory
```

On Windows, run the resulting executable as `.\simple_factory.exe` or `.\abstract_factory.exe` from PowerShell.

`GoogleDocs.cpp` writes its sample document to `document.txt` in the current working directory.

## Notes

These are learning examples focused on pattern structure. Names and implementation details are intentionally kept simple so the relationships between clients, abstractions, and concrete implementations are easy to follow.
