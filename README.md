# DA7281-Haptic-Driver-HAL
DA7281 is a linear resonant actuator (LRA) and eccentric rotating mass (ERM) haptic driver offering automatic closed-loop LRA resonant frequency tracking. The feature guarantees consistency across LRA production tolerances, operating temperature, aging, and mechanical coupling. DA7281 offers wideband operation that fully utilizes the capabilities of newer wideband and multi-directional LRAs.
To reduce system complexity, an integrated Waveform Memory allows haptic sequences to be preloaded to DA7281. Independent sequences can be triggered, with low-latency (0.75 ms), by the GPI pin without host interaction. Haptic sequences can also be streamed to DA7281 from an external source via I2C or pulse width modulated (PWM) signal.
DA7281 actively monitors the back electromotive force (BEMF) while continuously driving and applies closed-loop Active Acceleration and Rapid Stopping for sharper clicks and a higher fidelity user experience. This offers significant advantages over existing solutions that need to move into a high-impedance state during drive to measure the BEMF, which adds a considerable amount of inactive time to the sequence and lowers the effective click strength for a given LRA.

# Overview
This repository contains a low-level firmware driver (HAL) for the Renesas DA7281 haptic driver IC, designed for precise control of LRA/ERM actuators in embedded systems.
The driver is intended to be hardware-agnostic and suitable for board bring-up, integration, and production firmware.

# Interfaces & Dependencies
Communication: Inter Integrated Communication (I2C)
MCU: MCU-agnostic
Language: C (MISRA-aware style)

The driver does not depend on any vendor HAL and can be integrated into bare-metal or RTOS-based systems.
