# Second-Semester Coursework — C++, MASM and Qt

[Русская версия](README.ru.md)

A collection of university exercises from the second semester of Applied Informatics. The repository keeps individual labs and variants separate rather than presenting them as a single application.

## What is represented

| Area | Materials in this repository |
|---|---|
| **C++ programming and data structures** | Class templates, arrays and structures, text-file processing, regular expressions, linked lists, and record processing. |
| **Assembly / machine-oriented programming** | MASM source files and C++ programs that work alongside assembly exercises. |
| **Qt desktop programming** | Small Qt projects, including a list-oriented exercise and a medicine-record interface. |
| **Files and data representation** | Example text inputs, sample student records, and files used by the coursework. Keep these separate from generated files produced by local builds. |
| **Visual Studio / Qt Creator** | Original project files (`.vcxproj`, `.filters`, `.pro`) are kept so each exercise can be opened in its intended IDE. |

## Repository layout

- `2 сем лаб №2 С++ Классы-шаблоны/` — class-template exercise with examples of array/structure input and sample student records.
- `Лаба №3 С++ Регулярные/` — regular-expression exercise with a corresponding input and output example.
- `Лаба №4 2 сем С++ Реализация двухсвязного списка/` — linked-list exercise and related source/header files.
- `Lab5_2sem_QT_list/` — Qt list-oriented exercise.
- `untitled9/` — Qt Widgets medicine-record exercise using a template header and a UI form.
- `asm/`, `assembler/`, `Кр асм2/`, `лаба ассемблер/`, and `лаба ассемблер массивы/` — separate assembly and mixed C++/assembly exercises.

Folder names intentionally preserve the original coursework naming so the projects can be matched to their assignments.

## Build and run

There is no single root-level build for the collection. Open the relevant `.sln`, `.vcxproj`, or `.pro` file in a compatible Visual Studio or Qt Creator setup and build that exercise independently.

- C++ projects may require the MSVC toolchain.
- Assembly projects may require the MASM tools configured for Visual Studio.
- Qt projects require a compatible Qt kit and qmake setup.
- Several exercises read files relative to the process working directory; use the matching lab folder as the working directory unless its project configuration says otherwise.

No claim is made that every lab builds on every platform. Some exercises are incomplete or retain legacy implementation details.

## Cleanup

Committed build output, compiler diagnostics, IDE-specific user settings, and generated intermediates have been removed from this branch. Source files, project definitions, and coursework input examples were retained. The root `.gitignore` helps prevent these local artefacts from being committed again.

## Academic context

These materials relate to the programming-focused part of the second-year curriculum, including **Algorithms and Data Structures**, **machine-oriented programming**, **computer-graphics programming**, **industrial programming**, and **computational methods**. This repository is a source archive of separate exercises, not a statement that every topic listed above is fully implemented here.
