# Argos

An experimental Edge Monitoring & Automation System designed for Smart Buildings and industrial IoT environments. 

Argos is an architectural exploration of how a lightweight, resilient edge controller can orchestrate distributed micro-automates (sensors/actuators) on a local network without relying on cloud dependencies.

## Architecture Overview

The system is built as a hybrid, multi-language architecture to optimize performance and development efficiency:
* **Argos Server (Edge Controller):** Built in Go (Golang) for efficient, asynchronous multi-client networking and high-concurrency stream processing.
* **Field Nodes (Micro-automates):** Built in modern C++ on ESP32 microcontrollers for direct hardware control and low-level protocol compliance.



## Current State & Features

Argos is developed incrementally with a focus on understanding networking and system fundamentals from first principles:
* **Asynchronous TCP Engine:** Multi-client TCP server utilizing Go's native high-concurrency model (Goroutines).
* **Line-based Protocol:** Stream parsing over TCP for structural validation of incoming environmental data.
* **Basic Request/Response:** Synchronous acknowledgment workflow between the edge controller and field clients.
* **Edge Simulation:** Tested locally under Linux environments using standard network utilities (`netcat`).

## Roadmap & GTB Strategy (2-3 Weeks Focus)

The project is moving toward a concrete Smart Building hardware showcase:
- [ ] **Go Core Migration:** Porting the initial POSIX C++ socket architecture into a clean, concurrent Go network layer.
- [ ] **Hardware Node (C++):** Deploying an ESP32 node wired to a DS18B20 thermal sensor via a One-Wire bus.
- [ ] **Local Storage (Mini-WAL):** Implementing an append-only Write-Ahead Log for crash-resilient metric persistence.
- [ ] **Industrial Standard Exploration:** Transitioning the application layer toward standard automation protocols (Modbus TCP / MQTT).

## Core Technical Interests

* **Hybrid Engineering:** Combining C++ (Hardware/Embedded) and Go (Systems/Networking).
* **Industrial Networking:** Sockets, TCP/IP streams, protocol parsing, and local infrastructure security.
* **System Resilience:** Fault tolerance, WAL-based data recovery, and edge autonomy.
* **Observability:** Time-series data logging and localized monitoring.

## Philosophy

Argos strictly follows a **pragmatic, explicit, and anti-over-engineering** philosophy. 
The goal is to deeply master the underlying systems (network layers, hardware constraints, file I/O operations) before building abstractions. It values software craftsmanship, simple codebases, and physical real-world utility over corporate framework bloat.

## Getting Started

### Prerequisites
* Go compiler (1.20+)
* C++20 compatible compiler & PlatformIO (for ESP32 firmware)

### Running the Server

```bash
go run main.go
```
Testing the Network Layer
```bash
nc localhost 8080
```

## Status
Active experimental stage. Evolving from a pure network playground into a functional, localized Smart Building telemetry platform.
