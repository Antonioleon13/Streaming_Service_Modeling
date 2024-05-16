# Streaming Service Modeling

This repository contains a project for creating a streaming service interface in C++ using object-oriented programming principles such as classes, inheritance, and polymorphism. The main program is located in `main.cpp`.

## Overview

The project simulates a streaming service platform where users can browse and stream various media content. The implementation showcases the use of object-oriented programming concepts in C++, providing a modular and extensible design for a streaming service.

## Features

- **Classes:** Defines different types of media content and users.
- **Inheritance:** Utilizes inheritance to create a hierarchy of media content types.
- **Polymorphism:** Implements polymorphism to handle different media content through a common interface.

## Repository Structure

- `main.cpp`: The main program file that drives the application.
- `include/`: Contains the header files for class definitions.
- `src/`: Contains the source files for class implementations.
- `csv/`: Contains the data bases to use this repo

## Getting Started

### Prerequisites

To compile and run this project, you need a C++ compiler that supports C++11 or later. You can use GCC, Clang, or any other compatible compiler.

### Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/Antonioleon13/Streaming_Service_Modeling.git
    cd Streaming_Service_Modeling
    ```

2. Compile the project using the following command:
    ```bash
    g++ -std=c++11 -o streaming_service main.cpp src/*.cpp
    ```

### Usage

After compiling the project, you can run the executable:

```bash
./streaming_service
