# Argos

Experimental backend & edge monitoring system built in modern C++.

Current focus:
learning and exploring networking, systems programming, protocol design and backend reliability through a real-world oriented project.

---

## Current state

Argos currently includes:

* TCP server built on POSIX sockets
* line-based protocol over TCP
* incremental stream parsing
* multiple message handling
* basic request/response workflow
* Linux command-line testing with `netcat`

The project is intentionally developed incrementally to better understand:

* networking fundamentals,
* backend architecture,
* reliability,
* protocol design,
* and systems programming concepts.

---

## Goals

Argos aims to progressively evolve into a small monitoring & automation platform for edge devices and environmental sensors.

Long-term exploration topics include:

* edge nodes on Raspberry Pi
* ESP32 sensor integration
* temperature / environment monitoring
* logging & observability
* persistence & WAL-based recovery
* multi-client handling
* reliability and fault tolerance
* lightweight automation & alerting

---

## Technical interests explored

* modern C++
* Linux systems programming
* TCP networking
* backend architecture
* protocol parsing
* RAII & ownership
* concurrency
* persistence & recovery
* observability

---

## Philosophy

Argos is built with a strong focus on:

* simplicity,
* explicit design,
* maintainability,
* incremental development,
* and understanding systems deeply before optimizing them.

The goal is not to build a “framework” or over-engineered platform,
but to progressively construct a small, understandable and reliable system.

---

## Build

Requirements:

* CMake >= 3.15
* C++20 compatible compiler

Build:

```bash
cmake -B build
cmake --build build
```

Run:

```bash
./build/server_app
```

Test with:

```bash
nc localhost 8080
```

---

## Status

Early experimental stage.

Architecture, protocol and implementation details will evolve progressively as the project grows.
