# Failure case analysis · Mars Climate Orbiter (v1.0, 2026-10-20)
Authors: Keo Maknioddom

## 1. Context
The Mars Climate Orbiter was a 338-kilogram robotic space probe launched by NASA on December 11, 1998, to study the Martian atmosphere, climate, and surface changes. The mission was a critical component of the Mars Surveyor '98 program and aimed to provide long-term observations of Martian weather. On September 23, 1999, the spacecraft was lost when it entered Mars's atmosphere too low (about 57 kilometers instead of the planned 226 kilometers) and disintegrated due to atmospheric stresses and thermal friction. The failure mattered immensely because it resulted in a total loss of a $327.6 million mission and damaged public confidence in NASA's interplanetary exploration paradigm.

## 2. Timeline
| Date                           | Event                                                                                                   |
|--------------------------------|---------------------------------------------------------------------------------------------------------|
| December 11, 1998              | Mars Climate Orbiter successfully launches from Cape Canaveral.                                         |
| December 1998 – September 1999 | The spacecraft cruises through interplanetary space toward Mars.                                        |
| September 8, 1999              | Trajectory Correction Maneuver-4 (TCM-4) is executed to align the probe for orbital insertion.          |
| September 23, 1999 (09:04 UTC) | The spacecraft begins its Mars Orbit Insertion (MOI) main engine burn.                                  |
| September 23, 1999 (09:09 UTC) | Spacecraft goes behind Mars as planned, but communication fails to re-establish after occultation.      |
| September 24, 1999             | Deep Space Network telemetry searches fail to pick up any signal from the orbiter.                      |
| November 10, 1999              | NASA's Mishap Investigation Board releases its report identifying the metric-to-imperial unit mismatch. |

## 3. What failed
The root technical failure was a unit mismatch caused by a discrepancy between two software systems: the ground-based navigation team's software (produced by Lockheed Martin) generated thruster performance data (Small Forces impulse data) using imperial units (pound-seconds, lbf·s), while the spacecraft's onboard flight software, developed by NASA's Jet Propulsion Laboratory (JPL), expected the data to be in metric units (newton-seconds, N·s). Because the values were never converted, the navigation software drastically underestimated the cumulative momentum imparted by the thrusters over nine months of cruise. This compounding navigation error caused the spacecraft's predicted entry altitude at Mars to be off by tens of kilometers, leading it to plunge into the atmosphere at a catastrophic altitude.

## 4. Root causes
| #  | Root cause                                              | Type           | Essential difficulty | Why                                     |
|----|---------------------------------------------------------|----------------|----------------------|----------------------------------------------|
| R1 | Unenforced unit validation contracts between subsystems | process        | invisibility         | Unit assumptions were never explicitly visible in specs. |
| R2 | Inadequate end-to-end integration testing pre-launch    | process        | complexity           | Too many interacting modules for manual verification. |
| R3 | Lack of unified cross-team interface standards          | organisational | conformity           | Teams followed isolated legacy standards. |

## 5. Practices that would have prevented or limited it
| Root cause | Practice | Chapter |
|------------|----------|---------|
| R1 | Strict interface contracts and unit-safety wrappers | [Chapter 01 slides](https://gicitc.com/courses/introduction-to-software-engineering/01-SoftwareDevelopmentChallenges/01-SoftwareDevelopmentChallenges.html) |
| R2 | Automated system-level integration testing | [Chapter 01 slides](https://gicitc.com/courses/introduction-to-software-engineering/01-SoftwareDevelopmentChallenges/01-SoftwareDevelopmentChallenges.html) |
| R3 | Formal architecture and cross-team peer reviews | [Chapter 01 slides](https://gicitc.com/courses/introduction-to-software-engineering/01-SoftwareDevelopmentChallenges/01-SoftwareDevelopmentChallenges.html) |

## 6. Lessons for ITC Club Hub
1. Our data input layer must reject invalid capacities or formats that fail schema validation.
2. Cross-module interfaces must use shared, documented data contracts verified by unit tests.

## 7. Sources
1. NASA Mars Climate Orbiter Mishap Investigation Board, *Phase 'A' Report*, 1999. (primary)
2. Spaceflight Now, *Mars Climate Orbiter metric mix-up detailed*, 1999.
3. National Geographic, *Why the Mars Climate Orbiter Crashed*, 2019.