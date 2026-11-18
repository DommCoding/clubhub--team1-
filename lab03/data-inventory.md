# Data inventory · ITC Club Hub
Version 0.1 · 2026-11-18 · Authors: <TSMonyrak>

| Field | Subject | Purpose | Legal basis / consent | Retention | Who can see it | Stored in | Decision |
|-------|---------|---------|-----------------------|-----------|----------------|-----------|----------|
| studentId | student | Identify student; prevent double registration for the same event | Necessary for the service | 6 months after graduation or account deletion | Student (full); Organisers (masked); Administrator (full for audits) | data/students.csv | Mask for organisers: Organisers only need to verify check-in identity without exposing full IDs. |
| name | student | Display on registration lists and door check-in screens | Necessary for the service | 6 months after graduation or account deletion | Student, Club leader, Organiser, Administrator | data/students.csv | Keep: Essential for human verification during event door check-in. |
| email | student | Account login, registration confirmation, and opt-in email reminders | Necessary for the service (confirmations); Consent (reminders) | 6 months after graduation or account deletion | Student; Administrator (for support) | data/students.csv | Keep: Required for core account notifications and optional email reminders. |
| phone | student | SMS reminder 24 h before an event, only if chosen | Consent (explicit opt-in, withdrawable in My profile) | Deleted immediately on withdrawal, otherwise 6 months after graduation | Nobody on screen; read only by the automated reminder sender | data/students.csv | Keep optional: SMS reaches students who do not have active mobile data. |
| clubMemberships | student | Track which clubs a student belongs to and manage club rosters | Necessary for the service | Until student leaves the club or 6 months after graduation | Student, respective Club leader, Administrator | data/clubs.csv | Keep: Core functionality required to manage club membership and access. |
| attendance | student | Door check-in tracking and monthly cross-club activity reporting | Legitimate interest: clubs office requires participation metrics to allocate funding | Anonymised/aggregated 30 days after event; raw logs deleted | Organiser (during event); Administrator (aggregated monthly report only) | data/registrations.csv | Aggregate for reports: Monthly cross-club reports only need headcount statistics, not individual student histories. |
| dateOfBirth | student | None: no feature, rule, or report uses age | None | Not collected | Nobody | Not stored | Drop: Collecting birth dates "just in case" violates data minimisation. |
| profilePhoto | student | None: door check-in uses student ID and name | None | Not collected | Nobody | Not stored | Drop: Storing image files adds security risk and storage overhead with no functional need. |
| telegramHandle | student | None: reminders use email or SMS | None | Not collected | Nobody | Not stored | Drop: Third-party social handles are unnecessary when institutional email and optional SMS are supported. |
| gender | student | Demographic statistics for annual clubs office diversity report | Consent (optional survey field during registration) | Aggregated immediately upon submission; individual response not stored | Administrator (aggregated percentages only) | data/stats.csv | Aggregate: Individual gender data is never needed on screen and must be stored only as anonymous counts. |

## Copies of personal data

| Copy | Rule |
|------|------|
| log files | Output `Student::redacted()` only (e.g., `Student{id=e2******7}`); never log raw names, emails, or phone numbers. |
| CSV exports | Strip `phone` and `email` columns before exporting; mask `studentId` unless exported by an Administrator for an official audit. |
| test fixtures | Use strictly invented data (`e2099xxxx`, `test@example.edu`, `012 345 678`); never copy production CSVs into `tests/`. |
| backups | Store in an access-restricted directory outside the public repository; purge backups older than 30 days so deleted users are not restored. |
| screenshots in docs | Use a local test account with fake names and masked IDs; blur any visible email addresses before committing images to `lab03/`. |

## Lifecycle of the phone field

```mermaid
flowchart LR
  C["Collect only after explicit SMS opt-in"] --> S["Store in phone column, data/students.csv"]
  S --> U["Use for 24h event reminder sender only"]
  U --> SH["Share with SMS gateway provider, nobody else"]
  SH --> D["Delete immediately on