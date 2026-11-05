# Lab-02: Types of Applications
Version 1.0 • Date: 2026-11-04

## Overview of Lab-02 Files
| File Path                           | Description                                         | Main Author |
| ----------------------------------- | --------------------------------------------------- | ----------- |
| `lab02/app-classification.md`       | Classification of 5 everyday applications           | Maknioddom Keo      |
| `lab02/app-quadrant.md`             | Mermaid timing vs availability quadrant chart       | Maknioddom Keo      |
| `lab02/adr-001-application-type.md` | Architecture Decision Record for ITC Club Hub       | Techsamnang monyrak |
| `lab02/quality-scenarios.md`        | Six quality attribute scenarios and risk priorities | Team                |
| `lab02/context-diagram.md`          | Black-box context diagram for Club Hub              | Team                |
| `lab02/architecture.md`             | Three-tier architecture structure and mapping       | Team                |
| `include/clubhub/event.hpp`         | Event class and parser definitions                  | Sovannareach        |
| `include/clubhub/event_csv.hpp`     | CSV loader interface and error types                | Sovannareach        |
| `src/event.cpp`                     | Event implementation and date-time validation       | Sovannareach        |
| `src/event_csv.cpp`                 | CSV line parsing logic                              | Sovannareach        |
| `src/cli/main.cpp`                  | Command-line output and error reporter              | Sovannareach        | 

## Reused Inputs from Lab-01
| Input File              | Reused Details                                 | Commit Hash / Version |
| ----------------------- | ---------------------------------------------- | --------------------- |
| `lab01/team-charter.md` | Team member roles and consensus decision rules | Commit Hash           |
| `lab01/decisions.md`    | Architecture record linking setup              | Commit Hash           |

## System Diagrams
### Context Diagram
![Context Diagram](context-diagram.png)

### Three-Tier Architecture
![Three-Tier Diagram](architecture.png)

## Change Log
| Date       | Version | What Changed                                            | Author    |
| ---------- | ------- | ------------------------------------------------------- | --------- |
| 2026-11-04 | 1.0     | Added C++ core, CSV parser, list-events CLI, and README | Sovannareach |