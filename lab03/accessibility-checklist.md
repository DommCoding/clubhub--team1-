# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-18 · Authors: TSMonyrak

## WCAG 2.2 Level AA Checklist (POUR)

| SC | Name | Level | Screen | How we meet it | How we test it |
|----|------|-------|--------|----------------|----------------|
| 1.1.1 | Non-text Content (Perceivable) | A | Event list | All club logos and status icons include descriptive `alt` text or `aria-label` attributes. | Inspect DOM attributes and navigate the list using NVDA/VoiceOver. |
| 1.3.1 | Info and Relationships (Perceivable) | A | Registration form | Every `<input>` has a programmatic `<label for="...">` and error messages link via `aria-describedby`. | Run axe-core automated accessibility scan and verify screen reader announcements. |
| 1.4.1 | Use of Color (Perceivable) | A | Event list | Status badges pair background colour with explicit uppercase text (`[FULL]`, `[CANCELLED]`, `[OPEN]`). | View the page in browser greyscale mode to verify statuses remain distinguishable. |
| 1.4.3 | Contrast (Minimum) (Perceivable) | AA | All screens | Body text uses `#1E293B` on `#FFFFFF` (14.6:1 contrast ratio, exceeding the 4.5:1 requirement). | Verify all foreground/background hex pairs in the WebAIM Contrast Checker. |
| 2.1.1 | Keyboard (Operable) | A | Event list | All event cards, filter dropdowns, and register buttons are reachable and operable via `Tab` and `Enter`. | Unplug mouse and complete event discovery and registration using keyboard only. |
| 2.4.11 | Focus Not Obscured (Minimum) (Operable · 2.2) | AA | Registration form | Sticky top navigation uses `scroll-margin-top: 80px` so focused inputs are never hidden behind headers. | Tab through the entire form at 200% zoom and confirm the focus ring is always visible. |
| 2.5.7 | Dragging Movements (Operable · 2.2) | AA | Organiser check-in | Attendance check-in uses single-tap/click toggle buttons rather than swipe-to-check-in gestures. | Verify all check-in actions can be completed with single pointer clicks without dragging. |
| 2.5.8 | Target Size (Minimum) (Operable · 2.2) | AA | Registration form | All interactive buttons, checkboxes, and inputs have a minimum clickable area of `44x44px` with `8px` spacing. | Measure computed bounding boxes in browser DevTools across mobile and desktop viewports. |
| 3.2.6 | Consistent Help (Understandable · 2.2) | A | All screens | A "Clubs Office Help" link and contact email appear in the exact same footer slot on every screen. | Navigate across all planned views and verify identical placement and label of help links. |
| 3.3.7 | Redundant Entry (Understandable · 2.2) | A | Registration form | Student ID, name, and email auto-populate from the active session instead of asking students to re-type them. | Register for two events in one session and confirm profile fields are pre-filled automatically. |
| 3.3.8 | Accessible Authentication (Minimum) (Understandable · 2.2) | AA | Login screen | Login supports browser password managers (no `onpaste` blocking) and avoids cognitive puzzles/CAPTCHAs. | Test logging in via password manager autofill and copy-pasting a one-time token. |
| 4.1.2 | Name, Role, Value (Robust) | A | Event list | Custom filter chips use native `<button aria-pressed="true/false">` elements rather than generic `<div>` tags. | Inspect accessibility tree in browser DevTools to confirm valid roles and states. |

---

## Screen Design Decisions & Measured Contrast

### Screen 1: Event List (Web & Mobile)
1. **Card-based layout with explicit text badges:** Each event displays a high-contrast pill badge (`[OPEN]`, `[WAITLIST]`, `[FULL]`) alongside a calendar icon so status is never conveyed by colour alone.
2. **Minimum touch targets and spacing:** "Register" and "Details" buttons are sized at `48px` height with `12px` vertical separation to prevent accidental taps on mobile screens.
3. **Keyboard focus indicators:** Focused event links render a `3px solid #1D4ED8` outline with a `2px` white offset.
* **Measured Contrast Ratios (WebAIM Contrast Checker):**
  * Primary event title (`#0F172A` on `#FFFFFF` card background): **17.9:1** (Passes AA 4.5:1)
  * Secondary date/location metadata (`#475569` on `#FFFFFF` card background): **7.6:1** (Passes AA 4.5:1)
  * Primary "Register" button (`#FFFFFF` text on `#1D4ED8` button background): **6.7:1** (Passes AA 4.5:1 and UI 3:1)

### Screen 2: Event Registration Form
1. **Auto-filled identity fields with read-only summary:** Student ID, name, and email are pre-populated from the student's profile to eliminate redundant typing (WCAG 3.3.7).
2. **Inline error summaries linked to inputs:** Validation errors appear directly below the relevant field in red text accompanied by an exclamation icon and `aria-describedby` linkage.
3. **Clear focus clearance:** Form containers include top/bottom scroll padding so mobile on-screen keyboards and sticky headers never obscure the active input field (WCAG 2.4.11).
* **Measured Contrast Ratios (WebAIM Contrast Checker):**
  * Form field labels (`#1E293B` on `#F8FAFC` page background): **14.0:1** (Passes AA 4.5:1)
  * Input field border (`#64748B` border on `#FFFFFF` input background): **4.8:1** (Passes AA 3:1 for UI components)
  * Inline validation error text (`#B91C1C` on `#FEF2F2` alert background): **6.5:1** (Passes AA 4.5:1)