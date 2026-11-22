# AI feature proposal: "Recommended for you"
Version 1.0 · 2026-11-22 · Authors: TSMonyrak

## 1. Problem and non-personalised baseline

### User Problem
Students often miss campus events because notifications get lost in busy chat groups, or they struggle to sift through the full list of club events to find activities matching their academic schedules and personal interests. 

### Non-Personalised Baseline
Before introducing any recommendation algorithm, the system provides a standard, rule-based baseline:
* **"Popular this week":** Displays top events ranked by total registration count across the entire university.
* **"My clubs":** Displays upcoming events hosted strictly by the clubs the student has officially joined.

This baseline solves 70% of discovery friction transparently, deterministically, and without collecting any extra personal data or building user behavioral profiles.

---

## 2. Data needed

To move from the baseline to personalized recommendations, the feature requires specific historical data points. Every field is mapped against our Task 1 `data-inventory.md`:

| Field | Source | In inventory? | New purpose / consent? | Minimisation applied |
| :--- | :--- | :--- | :--- | :--- |
| `studentId` | `data/students.csv` | Yes | Used for querying attendance history | None (already minimised) |
| `clubMemberships` | `data/students.csv` | Yes | Identifies subscribed clubs | None |
| `attendanceHistory` | `data/registrations.csv` | Yes | **New purpose:** Computes historical category/club affinity scores | Aggregated and processed locally; raw notes/messages excluded |
| `eventTags` | `data/events.csv` | Yes | Matches event categories against user history | Restricted to predefined university tags |

### Task 1 Impact
No new fields are added to `Student.h`. However, the *Purpose* column for attendance records in `data-inventory.md` must be updated to include algorithmic event recommendation, requiring an explicit opt-in checkbox during profile setup.

---

## 3. Bias risks and mitigations

| Risk | Who is harmed | Mitigation | Fairness check (metric, threshold) |
| :--- | :--- | :--- | :--- |
| **1. Cold-start problem** | First-year students with zero attendance history | Fall back entirely to the non-personalised baseline ("Popular this week") until 3 events are attended. | Share of recommendations served to first-year students matches their proportion of active users (threshold: $\ge$ 90% parity). |
| **2. Popularity feedback loop** | Small clubs (e.g., Chess Club) get buried beneath large clubs (e.g., Tech Club) | Inject a mandatory exploration quota: at least 2 out of 5 recommendation slots must feature clubs the student has never interacted with. | Small clubs with <20 members receive at least 80% of their fair share of total campus impressions. |
| **3. Proxy discrimination** | Students with rigid academic timetables or part-time jobs are penalised for missing evening events | Exclude event timestamps from ranking weights; base affinity purely on club category tags rather than time slots. | Recommendation variance across student faculties/departments must not deviate by >15%. |
| **4. Echo chamber effect** | Students get locked into a single club category | Diversify recommendation tags so that no single category occupies more than 60% of the recommendation widget. | Maximum single-category concentration cap of 60% per student profile. |

---

## 4. Transparency

### "Why am I seeing this?" Example
When a student clicks the info icon next to a recommended event (*"Intro to Machine Learning Workshop"*), the UI displays:

> **Why am I seeing this recommendation?**
> You are seeing this event because:
> 1. You attended 2 past events hosted by the **Computer Science Club** (`clubMemberships`).
> 2. This event is tagged with **Technology**, which matches your attendance history.
> 3. 3 slots are based on your history, and 2 slots are new clubs recommended for you to explore.

### Ranking Inputs Published for the Clubs Office
* Club category similarity weight: 50%
* Past attendance frequency weight: 30%
* Exploration injection (randomised new clubs): 20%

---

## 5. Opt-out design

Recommendations are **opt-in** by default. Students must explicitly check a box in their profile settings to enable personalised suggestions.

```mermaid
flowchart TD
    A["My profile: Personalised Recommendations switch"] --> B{"Switched on?"}
    B -- No --> C["Serve non-personalised baseline ('Popular this week')"]
    B -- Yes --> D["Compute affinity score using attendance history"]
    D --> E["Render 5 personalised recommendations"]
    C --> F["Switch toggled off by student"]
    E --> F
    F --> G["Immediately wipe cached affinity profile data within 24 hours"]