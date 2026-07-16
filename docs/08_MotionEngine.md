\# Motion Engine



!\[Motion Engine Architecture](MotionEngine\_Architecture.png)



The Motion Engine is the orchestration layer of the Logos Robotics SDK.



Its responsibility is to coordinate the complete motion execution process while keeping motion planning, kinematic calculations, and hardware control cleanly separated.



The Motion Engine does \*\*not\*\* perform kinematic calculations and does \*\*not\*\* directly control hardware.



\---



\# Design Philosophy



The SDK follows a strict separation of responsibilities.



\- The application requests motion.

\- The Motion Engine orchestrates execution.

\- The kinematics module performs mathematical transformations.

\- The HAL controls the hardware.

\- The hardware produces physical motion.



Each layer has a single responsibility and communicates only with the layer directly below it.



\---



\# Motion Execution Flow



```

Application

&#x20;     │

&#x20;     ▼

Motion Engine

&#x20;     │

&#x20;     ▼

IKinematics

&#x20;     │

&#x20;     ▼

MotorCommandBuffer

&#x20;     │

&#x20;     ▼

IHal

&#x20;     │

&#x20;     ▼

Motors

```



The Motion Engine requests a kinematic transformation, receives a list of motor commands, and executes those commands through the Hardware Abstraction Layer.



\---



\# Responsibilities



\## Motion Engine



Responsible for:



\- coordinating the motion execution process

\- requesting kinematic transformation

\- receiving a MotorCommandBuffer

\- executing motor commands in sequence

\- reporting execution results



The Motion Engine never performs mathematical transformations or hardware-specific operations.



\---



\## IKinematics



Responsible for:



\- converting Cartesian coordinates into motor movements

\- generating a MotorCommandBuffer

\- supporting different kinematic models



Examples include:



\- CoreXY

\- Delta

\- SCARA



The Motion Engine remains independent of the selected kinematics implementation.



\---



\## Hardware Abstraction Layer (HAL)



The HAL is responsible only for hardware operations.



It knows nothing about:



\- kinematics

\- motion planning

\- coordinate systems

\- motion profiles

\- command buffers



The HAL only knows how to:



\- initialize hardware

\- enable a motor

\- set motor direction

\- generate STEP pulses

\- disable a motor



The HAL is an executor, not a decision maker.



\---



\# Architectural Decision



The Motion Engine executes motor commands one at a time.



The HAL never receives an entire MotorCommandBuffer.



This keeps the HAL completely independent from execution strategies, buffering, planning, and kinematic models.



As a result, the same Motion Engine can operate with different HAL implementations without modification.



\---



\# Design Principle



> \*\*Motion Engine orchestrates. Kinematics calculates. HAL executes.\*\*



This principle defines one of the core architectural rules of the Logos Robotics SDK.



\---



\# Current Status



Architecture approved.



The Motion Engine design serves as the reference implementation for all future hardware platforms supported by the SDK.

