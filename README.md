# cRegister

[![Build Status](https://travis-ci.org/j-bruel/cRegister.svg?branch=develop)](https://travis-ci.org/j-bruel/cRegister)
[![Build status](https://ci.appveyor.com/api/projects/status/yu3pueottceo7711?svg=true)](https://ci.appveyor.com/project/j-bruel/cregister)
[![codecov](https://codecov.io/gh/j-bruel/cRegister/branch/develop/graph/badge.svg)](https://codecov.io/gh/j-bruel/cRegister)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/c1027b37f11442529e84810a6fed5aa3)](https://www.codacy.com/app/j-bruel/cRegister?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=j-bruel/cRegister&amp;utm_campaign=Badge_Grade)
[![Documentation](https://codedocs.xyz/j-bruel/cRegister.svg)](https://codedocs.xyz/j-bruel/cRegister/)
[![Open Source Love](https://badges.frapsoft.com/os/mit/mit.svg?v=102)](https://github.com/j-bruel/cRegister/blob/master/LICENSE)

## Overview

Modern cross platforms C++ API for cRegisters. Register are smart memory, data manager, allowing to interact and persist data in an architectural, dynamic and simplified way.

## What is a Register

### Philosophy

### How does it work

## Features

## Usage

### Platforms

cRegister API platforms available :

* `Linux`
* `MacOS`
* `Windows`

### Requirements

cRegister library is designed to have fairly minimal requirements to build and use with your projects, but there are some.
In addition, the library is build in `c++14`.
These are the base requirements to build and use cRegister library from a source package (as described below):

#### Buidling library

##### Windows

* `CMake` At least v3.1
* Windows `command prompt`
* Microsoft `Visual C++ 2015`

##### Linux & MacOS

* GNU-compatible `CMake` and `Make` (at least v3.1).
* POSIX-standard `shell`.
* A `C++14`-standard-compliant compiler

#### Documentation

- `Doxygen`

#### Testing

- `gcov`
- `lcov`

### Build and install

#### Variables

| Variable           | Description                                                                                    | Possible Values                                 | Default Value |
|--------------------|------------------------------------------------------------------------------------------------|-------------------------------------------------|---------------|
| `CMAKE_BUILD_TYPE` | On a single configuration generator, this string determines the build type of the application. | `Debug`/`Release`/`RelWithDebInfo`/`MinSizeRel` | `Release`     |
| `GEN_DOCS`         | An option used to determine if documentation will or will not be generated.                    | `ON`/`OFF`                                      | `ON`          |
| `BUILD_TESTS`      | An option used to determine if the test executable should or should not be built.              | `ON`/`OFF`                                      | `ON`          |
| `ENABLE_COVERAGE`  | An option used to determine whether coverage should be enabled or not                          | `ON`/`OFF`                                      | `ON`          |

#### Targets

| Target           | Description                                                    |
|------------------|----------------------------------------------------------------|
| `[Nothing]`      | Build the application (Including `test` if `BUILD_TESTS=ON`).  |
| `install`        | Install all built targets.                                     |
| `test`           | If tests were built, then run all tests.                       |
| `doc`            | If `GEN_DOCS=ON`, then generate documentation using `Doxygen`. |
| `coverage`       | If `ENABLE_COVERAGE=ON`, then generate code coverage.          |
| `clean`          | Clean all built targets.                                       |

#### Windows

* `mkdir build` **_## In the root project directory_**
* `cd build`
* `cmake .. -DBUILD_TESTS=<ON|OFF> -DGEN_DOCS=<ON|OFF> -DENABLE_COVERAGE=<ON|OFF>`
* `cmake --build .`

Launching test or coverage (after build) : 

* `cmake --build . --target RUN_TESTS`
* `cmake --build . --target coverage`

Installing the library :

* `cmake --build . --target install`

Launch documentation building :

* `cmake --build . --target doc`

#### Linux & MacOS

To build the library on linux or MacOS :

* `mkdir build` **_## In the root project directory_**
* `cd build`
* `cmake .. -DBUILD_TESTS=<ON|OFF> -DGEN_DOCS=<ON|OFF> -DENABLE_COVERAGE=<ON|OFF>`
* `make`

Launching test or coverage (after build) : 

* `make test`
* `make coverage`

Installing the library :

* `make install`

Launch documentation building :

* `make doc`

This will generate a shared library `libcRegister.[so][dll]` and a testing application `cRegister[.exe]`.

### Building with

Now, let take a look on how to build a custom application with the cRegister library.

You must link the library in your CMakeLists.txt.

```cmake
target_link_libraries(${PROJECT_NAME}   cRegister)
```

Finaly, you simply need to include all cRegister headers needed like this :

```c++
#include <jbr/cRegister/HelloWorld.hpp>
```

If any difficulties persist, samples with full CMakeLists.txt are here to help too.

### Example

This next example is here to guide, understand and / or test the cRegister library.

```c++
#include <jbr/reg/HelloWorld.hpp>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    jbr::reg::HelloWorld    hw;

    std::cout << hw.hello() << std::endl;
    std::cout << hw.world() << std::endl;
    std::cout << hw.generateRandomNumber() << std::endl;
    std::cout << hw.headerFunction(3) << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    return (0);
}
```

## Contributing

cRegister project is developed on GitHub at [cRegister](https://github.com/j-bruel/cRegister).
To report an issue or send a pull request, use the [issue tracker](https://github.com/j-bruel/cRegister/issues).

## License

This software is distributed under [MIT license](http://www.opensource.org/licenses/mit-license.php), so feel free to integrate it in your commercial products.
