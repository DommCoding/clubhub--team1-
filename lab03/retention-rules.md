# Retention rules - ITC Club Hub
Version 0.1 · 2026-11-22 · Authors: Reach

| Kept field | Trigger | Action | Who or what runs it | How to verify it happened |
|------------|---------|--------|----------------------|----------------------------|
| studentId | Account deletion or 6 months after graduation | Delete | Scheduled/admin cleanup job (e.g., future `clubhub purge`) | Query/inspect student store and tests to confirm record is removed. |
| name | Account deletion or 6 months after graduation | Delete | Scheduled/admin cleanup job (e.g., future `clubhub purge`) | Confirm student record is removed and logs only contain `redacted()`. |
| email | Account deletion or 6 months after graduation | Delete | Scheduled/admin cleanup job (e.g., future `clubhub purge`) | Confirm email is removed from store and no reminder emails are sent. |
| phone | `withdrawSmsConsent()` or 6 months after graduation | Delete | `withdrawSmsConsent()` immediately; cleanup job on expiry | Check `student.phone().has_value() == false` and verify number is absent from stored data. |
| clubMemberships | Membership ends or 6 months after graduation | Delete | Cleanup/membership sync job | Verify membership entry is removed from membership records. |
| attendance | After 12 months (or 6 months post-graduation) | Aggregate | Monthly reporting/cleanup job | Verify only aggregate counts remain in reports with no raw attendee log left. |