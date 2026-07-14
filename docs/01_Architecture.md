\# Logos Robotics SDK Architecture



\## Overview



Logos Robotics SDK is an educational, open-source motion control SDK designed

to separate motion planning, kinematics, motion execution and hardware control

into independent, reusable modules.



The SDK is hardware-independent and is intended to support multiple motion

systems and multiple hardware platforms.



\---



\# Layered Architecture



```

&#x20;               Application

&#x20;                    │

&#x20;                    ▼

&#x20;               IPlanner

&#x20;                    │

&#x20;                    ▼

&#x20;             IKinematics

&#x20;                    │

&#x20;                    ▼

&#x20;            IMotionEngine

&#x20;                    │

&#x20;                    ▼

&#x20;                 IHal

&#x20;                    │

&#x20;                    ▼

&#x20;                Hardware

```



Each layer communicates only with the layer directly below it.



\---



\# Module Responsibilities



\## Planner



Responsible for high-level motion planning.



Examples:



\- Home machine

\- Move to position

\- Execute motion sequence

\- Stop motion



Planner never accesses hardware directly.



\---



\## Kinematics



Responsible for transforming logical coordinates into motor movements.



Examples:



\- CoreXY

\- Cartesian

\- Delta

\- SCARA



Kinematics contains only mathematical transformations.



\---



\## Motion Engine



Responsible for executing motor movements.



Responsibilities include:



\- Motor stepping

\- Motion timing

\- Synchronization

\- Motion state



Motion Engine is independent of machine geometry.



\---



\## HAL (Hardware Abstraction Layer)



Responsible for direct hardware access.



Examples:



\- GPIO

\- Timers

\- Limit switches

\- Step outputs

\- Direction outputs



Only HAL communicates with the hardware.



\---



\# Core Module



The Core module contains shared SDK concepts.



Examples:



\- Position

\- Axis

\- Motor

\- Direction

\- Result

\- Status

\- MotorCommand



Core contains no hardware-specific code.



\---



\# Data Flow



```

Application



↓



Position



↓



Planner



↓



IKinematics



↓



MotorCommandBuffer



↓



Motion Engine



↓



HAL



↓



Hardware

```



\---



\# Design Principles



\- Single Responsibility

\- Hardware Independence

\- Clean Interfaces

\- No Dynamic Memory Allocation in Core

\- Readable Code over Clever Code

\- Documentation is Part of the Code



\---



\# Current Status



Build: 001



Status:



✔ Core module completed



✔ HAL interface completed



✔ Motion interface completed



✔ Kinematics interface completed



✔ Planner interface completed



Implementation phase begins after architecture validation.



## Current Reference Implementation

The first reference implementation targets:

- ESP32
- Arduino Framework
- CoreXY motion system

Future implementations may support:

- ESP-IDF
- STM32
- Linux
- Raspberry Pi
- Additional kinematic models

Current Implementations

✔ CoreXYKinematics

Upcoming

• Hardware Abstraction Layer (HAL)
• ESP32 Arduino HAL
• Desktop Mock HAL
• Motion Engine