# cpp-exercises

In this repository I host some implementations of C++ exercises.

Each file in `/src` corresponds to an exercise. A task description is given in each file. There are unit tests in `/test` which verify a correct implementation. They are based on [GoogleTest](<https://github.com/google/googletest>).

## Requirements

Developed and tested on the following setup:

- Debian 11.2
- macOS 12.2.1
- cmake 3.21.4

## Build

Run following commands on your terminal to compile the project:

```bash
mkdir build
cd build
cmake ..
make
```

## Run

The built binaries are stored in `/build`:

```bash
./cpp-exercises
./cpp-exercises-test
```

Or simply call `ctest` to execute the unit tests conveniently.
