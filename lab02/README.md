Lab-02 · System Design (v1.0, 2026-11-08)

1. Lab-02 Files

|File	                |Description	                                                |Main Author     |
|:----------------------|:--------------------------------------------------------------|:---------------|
|`lab02/app-classification.md`|Describes the classification of the Club Hub application. |Keo Maknioddom|
|`lab02/app-quadrant.mmd`     |Mermaid source code for the application classification quadrant diagram.|Keo Maknioddom|
|`lab02/adr-001-application-type.md`	|Records the architectural decision and rationale for the Club Hub application type.| Techsamnang Monyrak|
|`lab02/quality-scenarios.md `	|Documents quality attribute scenarios and system requirements. |Pres Samchara|
|`lab02/context-diagram.mmd`	    |Mermaid source code for the Club Hub context diagram.|Tim Rommnea|
|`lab02/context-diagram.png`	    |PNG export of the Club Hub context diagram.|Tim Rommnea|
|`lab02/architecture.mmd`	    |Mermaid source code for the three-tier architecture diagram.|Tim Rommnea|
|`lab02/architecture.png`	    |PNG export of the three-tier architecture diagram.	            |Tim Rommnea|
|`lab02/challenge/offline-checkin.md`	|Describes the offline check-in challenge, including its requirements and conflict-handling rules.|Pres Samchara|
|`lab02/README.md`	            |Documents Lab-02 files, reused inputs, diagrams, and changes.	|Tim Rommnea, Chea Sovannareach, Techsamnang Monyrak |
|`include/clubhub/event.hpp  `	|Declares the Event class, time-point type, and date-time functions.|Chea Sovannareach|
|`include/clubhub/event_csv.hpp`	        |Declares the CSV loading functions and error/result structures.|Chea Sovannareach|
|`include/clubhub/queued_checkin.hpp `	            |Declares the queued check-in functionality for offline registration.	|Tim Rommnea|
|` src/event.cpp`	            |Implements event validation and date-time parsing and formatting.	|Chea Sovannareach|
|` src/event_csv.cpp`	            |Implements CSV loading, event creation, and invalid-row handling.|Chea Sovannareach|
|`src/cli/main.cpp `	            |Implements the command-line interface, including the list-events command.|Chea Sovannareach|
|` data/events.csv  `	            |Stores sample event records used to test the CSV loader.|Pres Samchara|
|` CMakeLists.txt`	            |Configures the C++20 project, core library, and CLI executable.|Keo Maknioddom|
1. Inputs Reused

|Lab-01 File             |Version / Commit Hash	|How It Was Used                                            |
|:----------------------|:----------------------|:----------------------------------------------------------|
|`lab01/team-charter.md`	|3265603       	|Used as a reference for team roles and responsibilities.   |
|`lab01/decisions.md`	    |3265603	    |Used as a reference for previous project decisions.        |

1. Diagrams

## 1. Context Diagram

This diagram shows the Club Hub system, its users,
external systems, and the data flowing between them.

![Club Hub Context Diagram](context-diagram.png)

## 2. Three-Tier Architecture

This diagram shows the three layers of Club Hub:
Presentation, Logic, and Data.

![Club Hub Architecture](architecture.png)

4. Change Log

|Date	|Version	|Changes     |Authors   |
|:------|:----------|:----------------------------------------------------------|:----------------|
|2026-11-08	|1.0	|Completed Lab-02 documentation, system diagrams, event core, and list-events CLI.	|Everyone|