# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-11-04 · Status: Proposed · Deciders: Techsamnang Monyrak

## User groups

| Group | Device | Where | Connectivity | How often | Must never fail |
|---|---|---|---|---|---|
| Students | Android / iPhone | On campus / mobile | Mobile data or Wi-Fi | A few times a week | Registration and browsing without crashing |
| Organisers | Phones (1-2 at door) | Event venue entrance | Weak or overloaded Wi-Fi | Peak times (event arrivals) | Offline check-in at the door |
| Administrators | Desktop PCs | Office | Steady connection | Monthly / as needed | Monthly reports and club approvals |

## Options

* **A.** Native mobile apps (Android + iOS) for students/organisers + desktop app for administrators
* **B.** Progressive Web App (PWA) for students and organisers + responsive web app for administrators
* **C.** Standard responsive web app across all user groups
* **D.** Native mobile apps for everyone including administrators

## Weighted comparison (score 1-5 x weight)

| Criterion (weight) | Why this weight | A | B | C | D |
|---|---|---|---|---|---|
| Cost for our team in one semester (Weight: 3) | 5-person team with only one semester; multi-platform native code is too heavy. | 1 x 3 = 3 | 4 x 3 = 12 | 5 x 3 = 15 | 1 x 3 = 3 |
| Reach (Weight: 2) | Students shouldn't need to visit an app store binary just to check an event. | 2 x 2 = 4 | 5 x 2 = 10 | 5 x 2 = 10 | 2 x 2 = 4 |
| Offline check-in at the door (Weight: 3) | Event entrance Wi-Fi is notoriously weak or overloaded during peak arrivals. | 4 x 3 = 12 | 5 x 3 = 15 | 1 x 3 = 3 | 4 x 3 = 12 |
| Reminders (Weight: 2) | Students must receive timely notifications about registered club events. | 5 x 2 = 10 | 4 x 2 = 8 | 2 x 2 = 4 | 5 x 2 = 10 |
| Admin desktop usability & reports (Weight: 1) | Only 2-3 staff members use it monthly, but large tables need a wide screen. | 3 x 1 = 3 | 4 x 1 = 4 | 4 x 1 = 4 | 3 x 1 = 3 |
| ***Total*** | | **= 32** | **= 49** | **= 36** | **= 32** |

## Deal-breaker check
Option C (standard responsive web app) fails the critical "offline check-in at the door" requirement because web apps reload blank pages or fail when venue Wi-Fi drops. Option B wins, and we supplement it by adding an offline check-in queue (using service workers and local storage) to handle poor connectivity at event doors.

## Decision
We choose **Option B**: A Progressive Web App (PWA) for students and organisers, backed by the same responsive web application layout for administrators in the student affairs office.

## Consequences

### Positive (+)
* Single codebase and technology stack for web and mobile views, drastically reducing development overhead for a 5-person team in one semester.
* Organisers can scan tickets and handle check-ins offline at the door even when venue Wi-Fi drops completely.

### Negative (-)
* Push notifications and advanced device API integrations require users to install/add the PWA to their home screen; email reminders serve as the primary fallback.
* Browser compatibility quirks require additional testing across mobile Chrome and Safari versions.

## Rejected options
* **Option A (Native apps):** Building and maintaining separate native binaries for iOS, Android, and desktop requires too much engineering bandwidth for a 5-person team in a single semester.
* **Option C (Standard responsive web app):** Fails the offline check-in requirement during peak event arrivals due to poor venue connectivity.
* **Option D (Native mobile apps for everyone):** Inefficient for administrators who need to review broad monthly activity reports on desktop monitors.

## How the front ends reach the C++ core
The front-end applications (PWA and web views) will eventually communicate with an HTTP API layer (such as a REST or JSON API) that wraps and executes calls against our C++20 domain core (`clubhub_core`). In this course semester, our command-line interface (`src/cli/main.cpp`) directly executes and tests these core services locally.
