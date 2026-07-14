\# ADR-0005: Motor Abstraction



\*\*Status:\*\* Accepted



\*\*Date:\*\* 2026-07-11



\---



\## Context



The SDK is intended to support multiple motion systems, including CoreXY,

Cartesian, Delta and future kinematic models.



Motion planning operates on logical axes (X, Y, Z...), while the hardware

controls physical motors.



For example, in a CoreXY machine:



\- Logical axes: X, Y

\- Physical motors: A, B



A single movement along the X axis requires coordinated movement of both

physical motors.



Because of this, logical coordinates and physical motors represent different

concepts and must not be treated as the same abstraction.



\---



\## Decision



The Hardware Abstraction Layer (HAL) shall operate exclusively on physical

motors.



Logical axes shall be translated into motor commands by the Kinematics module.



The architecture therefore becomes:



Application



↓



Planner



↓



IKinematics



↓



Motion Engine



↓



HAL



↓



Hardware



The HAL is intentionally unaware of the machine kinematics.



\---



\## Rationale



Separating logical motion from physical motor control provides several

advantages:



\- Hardware independence

\- Kinematics independence

\- Cleaner software architecture

\- Easier testing

\- Support for multiple machine types without modifying HAL



Each module has a single responsibility.



\---



\## Consequences



The HAL API will eventually expose motor-oriented operations such as:



\- Set motor direction

\- Generate step pulse

\- Read motor-related hardware inputs



The Kinematics module will translate logical motion into physical motor

movements.



Motion Engine will execute those motor commands.



This allows the same Motion Engine and HAL to be reused for different machine

architectures.



\---



\## Alternatives Considered



\### HAL operating directly on X/Y axes



Rejected.



This approach couples the HAL to a specific machine architecture and prevents

reuse across different kinematic systems.



\---



\## Related ADRs



\- ADR-0001 SDK

\- ADR-0002 HAL

\- ADR-0003 Kinematics

