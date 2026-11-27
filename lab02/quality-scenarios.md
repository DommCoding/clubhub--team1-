 # Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-03 · Reviewed by (Scrum Master):Keo Maknioddom

## QAS-01 · Availability · written by Pres Samchara
| Part             | Content |
|------------------|---------|
| Source           | Students using the ITC Club Hub system |
| Stimulus         | Open Club Hub on mobile data and try to register for an event the moment registrations open |
| Environment      |During normal system operation, including periods when approximately 3000 students access the system simultaneously|
| Artifact         | Club Hub Server – Student Registration Function |
| Response         | The system accepts the registration, shows the new status "Registered" and queues the confirmation email |
| Response measure | Monthly availability >= 99.5 % (30 days x 24 h x 60 min = 43,200 min; 0.5 % = 216 min = 3.6 h of downtime allowed per month); and 0 minutes of planned downtime. If the e-mail service is down, registration still succeeds and the e-mail is retried within 15 min |

## QAS-02 · Performance of check-in at the door · written by Pres Samchara
| Part             | Content |
|------------------|---------|
| Source           | An organiser at the entrance of a hall |
| Stimulus         | Scans student QR codes one after another |
| Environment      | Debate Night: 200 arrivals in 10 minutes at one entrance (200 / 10 = 20 scans per minute, one every 3 s), weak Wi-Fi, one organiser phone |
| Artifact         | Check-in function (RegistrationService::checkIn) on the organiser's phone and the server |
| Response         | The system validates the registration and shows a green tick (or a red reason) for each scan |
| Response measure | The result is shown within 1 s for 95 % of scans and within 2 s for 99 % of scans; throughput >= 20 scans per minute for 10 minutes with 0 scans lost |

## QAS-03 · Usability · written by Tim Rommea
| Part             | Content |
|------------------|---------|
| Source           | A first-time student, with no training, on an Android phone |
| Stimulus         | Wants to find the "Intro to Git" event and register for it |
| Environment      | Normal operation, mobile data (4G), one-handed use, first visit in the semester |
| Artifact         | Student interface: event list, event details, registration |
| Response         | The student finds the event and receives a clear confirmation of the registration status |
| Response measure | Registration done in <= 4 taps and <= 60 s; at least 9 of 10 test users succeed without help in a usability test with 10 students |

## QAS-04 · Security · written by Techsamnang Monyrak
| Part             | Content |
|------------------|---------|
| Source           | A logged-in student who is curious or malicious (not an organiser of that club) |
| Stimulus         | Changes the event id or student id in a request to read the attendance list of another club's event |
| Environment      | Normal operation, any day, from a personal phone on the campus network or on mobile data |
| Artifact         | Attendance records API (personal data at risk: student ID, name, e-mail, club membership, attendance records) |
| Response         | The system refuses the request, returns no personal data, and writes an entry in the security log |
| Response measure | 100 % of 100 scripted unauthorised requests are refused (0 records returned); each is logged within 1 min; after 5 failed logins in 10 min an organiser account is locked for 15 min |
 ## QAS-05 · Modifiability · written by Keo Maknioddom
| Part             | Content |
|------------------|---------|
| Source           | A developer of the team |
| Stimulus         | Replaces CSV file storage by a database (or JSON files), as planned in "database later" |
| Environment      | Design time, after Sprint 2, core already tested |
| Artifact         | Storage code in src/ (EventCsv and its successors); include/clubhub/ interfaces |
| Response         | The change is made in the storage layer only; business rules and the CLI keep working unchanged |
| Response measure | Done in <= 3 person-days; <= 5 files changed under src/ and include/; 0 changes to business rules in RegistrationService; 100 % of existing tests still pass |

## QAS-06 · Portability · written by Chea Sovannareach
| Part             | Content |
|------------------|---------|
| Source           | A student or organiser with their own phone; an administrator on an office PC |
| Stimulus         | Opens Club Hub (the PWA / web app) on a device the team did not choose |
| Environment      | Start of semester, mixed devices: Android phones and iPhones, mobile data or Wi-Fi, office PCs with Windows |
| Artifact         | Front ends (PWA and web app), installed or opened from a URL |
| Response         | All Must-have functions (browse, register, cancel, check-in, report) work with the same behaviour on every supported platform |
| Response measure | Works on Android 10+ with Chrome (latest 2 versions), iOS 16.4+ with Safari, and Chrome, Edge and Firefox (latest 2 versions) on desktop; 100 % of 10 acceptance tests pass on each platform, checked on at least 3 real phones plus a browser-testing service before release; 0 platform-specific code branches in the C++ core |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01 Availability | H (registrations open on Friday evenings; downtime loses the main use) | M | Students | **Yes** |
| QAS-02 Check-in performance | H (200 arrivals in 10 min; queues at the door ruin the event) | H (weak Wi-Fi, burst load) | Organisers | **Yes** |
| QAS-03 Usability | M | L | Students | No |
| QAS-04 Security | H (personal data of 3,000 students) | M | Students, organisers | No |
| QAS-05 Modifiability | M | M | Development team | No |
| QAS-06 Portability | M | M | Students, organisers, administrators | No |