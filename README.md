# Logos Robotics SDK

> **An educational open-source robotics motion control SDK designed to teach as much as it controls.**

**Logos Robotics SDK** is an educational open-source Software Development Kit (SDK) for robotics motion control.

The project focuses on clean software architecture, modular design, and real hardware verification. Its purpose is not only to build reliable motion control systems, but also to serve as an educational reference for embedded software engineering, robotics software architecture, and motion control design.

---

# Vision

The goal of Logos Robotics SDK is to create a modular, hardware-independent motion control platform that can be reused across different robotics projects.

The first reference implementation targets a CoreXY motion system running on ESP32 using the Arduino Framework. The architecture is designed to support additional kinematic models and hardware platforms in future releases.

---

# Project Goals

- Educational
- Open Source
- Motion Control SDK
- Clean Architecture
- Hardware Independent
- Modular Design
- Verified on Real Hardware

---

# Engineering Principles

- Every commit must compile.
- Every major feature must be verified before becoming part of the project.
- Documentation is part of the code.
- No magic numbers.
- Readable code over clever code.
- No feature enters the project without successful testing.
- Architecture first. Implementation second.

---

# Architecture

The SDK follows a layered architecture.

```text
                Application
                     │
                     ▼
                 IPlanner
                     │
                     ▼
               IKinematics
                     │
                     ▼
              IMotionEngine
                     │
                     ▼
                    IHal
                     │
                     ▼
             Esp32ArduinoHal
                     │
                     ▼
                 Hardware
```

Each layer has a single responsibility and communicates only with the layer directly below it.

---

# Current Status

**Build 002 – Core Foundation Verified**

Completed:

- Core module
- Core data types
- Core interfaces
- CoreXY kinematics
- Desktop CMake build
- Desktop verification tests
- Architecture documentation

Current status:

- Desktop build verified
- CoreXY transformation verified
- Ready for HAL implementation

---

# Repository Structure

```text
docs/
sdk/
examples/
tests/
```

Documentation and software evolve together.

---

# Development Philosophy

> **Built to understand, not only to work.**

Logos Robotics SDK is developed through small, verifiable engineering steps.

Every architectural decision is documented.

Every important feature is validated before becoming part of the SDK.

The objective is not only to create reliable software, but also to help others understand how professional robotics software is designed.

---

# Reference Platform

Current reference platform:

- ESP32
- Arduino Framework
- CoreXY Motion System

Future platforms may include:

- ESP-IDF
- STM32
- Raspberry Pi
- Linux

Future kinematic models may include:

- Cartesian
- Delta
- Polar
- SCARA

---

# Contributors

## Project Founder

**Prele Prelević**

## Software Architecture and Development

Developed in collaboration with OpenAI ChatGPT.

---

# License

MIT License

---

## Current Development

The project is under active development.

The architecture is considered stable, while new functionality is implemented and verified incrementally.