# Ethics Case Analyses – ITC Club Hub
Version 1.0 · 2026-11-22 · Leads: A = Tim Rommnea, B = TSMonyrak

---

## Scenario A: "Just a small report"

| Step | Analysis |
|---|---|
| **1. Facts** | The Robotics Club leader requests a report showing which students attend other clubs' events. The report will only be visible to club leaders and will be used for recruitment. However, students may not know their attendance information is being shared. We need to find out whether students have agreed to this use, whether clubs have permission to share attendance records, and whether the administrator has formally approved the feature. |
| **2. Stakeholders and harms** | **Students:** Their attendance information could be shared without their knowledge, violating their privacy. **Club leaders:** They could misuse information or access data beyond their responsibilities. **Administrators:** Unauthorized sharing could damage trust. **Development team:** Implementing the feature without approval could create ethical and legal problems. |
| **3. Codes, law, policy** | **SE Code Principle 1 (Public), 1.03:** Approve software only when it does not diminish quality of life or privacy. **ACM 1.6:** Respect privacy. **GDPR Article 5(1)(a), (b), and (c):** Personal data must be processed fairly and transparently, used for specified purposes, and limited to what is necessary. GDPR applicability must be confirmed. |
| **4. Options** | (a) Build the report immediately as requested. (b) Refuse implementation until the administrator formally approves the purpose and access permissions. (c) Suggest an alternative, such as anonymous attendance statistics or a voluntary opt-in recruitment system. |
| **5. Tests** | **Option (a):** Harm – students may lose privacy. Rights – students' privacy expectations may be violated. Fairness – students may be treated differently based on attendance. Publicity – the team may struggle to justify sharing this information publicly. **Option (b):** Harm – prevents unauthorized data exposure. Rights – protects student privacy. Fairness – applies the same approval process to everyone. Publicity – the decision can be explained openly. **Option (c):** Harm – reduces exposure of personal information. Rights – students control whether their information is shared. Fairness – recruitment is transparent. Publicity – the approach can be publicly justified. |
| **6. Decision and action** | We choose options (b) and (c). We will not implement the individual attendance report without formal authorization and a clear purpose. Instead, we propose anonymous attendance statistics or a voluntary opt-in feature. Report access must also follow role-based permissions. |
| **7. Reflection** | This scenario teaches us that having access to information does not automatically give us permission to use it for another purpose. Developers must consider users' privacy and rights rather than simply following requests from people in authority. |

**Message sent:**

> Thank you for suggesting this feature. However, displaying individual students' attendance across different clubs could raise privacy concerns because students may not have agreed to share this information for recruitment. Before implementation, we would need formal administrator approval and confirmation of the data-sharing policy. We suggest using anonymous attendance statistics or a voluntary opt-in recruitment feature instead. This would still help clubs identify recruitment opportunities while respecting students' privacy.

**Preventive change:** Implement role-based access restrictions for attendance reports. Club leaders can only access attendance information belonging to their own clubs. Cross-club reports require administrator authorization.

**GitHub issue:** #2

---
## Scenario B: "Don't mention it in the demo"

| Step | Analysis |
|---|---|
| **1. Facts** | Two days before the Sprint 1 review, a developer discovers two defects: cancellations within 24 hours are incorrectly accepted, and cancelled registrations are counted as attendance in monthly reports. The Scrum Master suggests hiding these problems until Sprint 2. We need to investigate the affected functions, check the acceptance criteria, identify affected records, and determine whether the client has received inaccurate information. |
| **2. Stakeholders and harms** | **Students:** They may experience incorrect cancellation behavior. **Club leaders:** They may make decisions using inaccurate attendance reports. **Client/Product Owner:** They may misunderstand the actual quality of the system. **Development team:** Hiding defects damages professional credibility. **Administrators:** Incorrect reports could affect club planning. |
| **3. Codes, law, policy** | **SE Code Principle 1 (Public), 1.06:** Be fair and avoid deception in statements about software. **SE Code Principle 3 (Product), 3.10:** Ensure adequate testing, debugging, and review. **ACM 1.3:** Be honest and trustworthy. **ACM 2.5:** Provide thorough evaluations of computer systems and their risks. |
| **4. Options** | (a) Hide both defects during the demonstration and postpone fixes until Sprint 2. (b) Inform the Scrum Master and Product Owner, document both defects, and explain their impact during the review. (c) Fix the most critical defects before the review and disclose any unresolved issues with their planned solutions. |
| **5. Tests** | **Option (a):** Harm – users may continue experiencing incorrect behavior. Rights – the client is denied accurate information. Fairness – the team gains an unfair advantage by hiding defects. Publicity – hiding known problems is difficult to justify publicly. **Option (b):** Harm – allows the team to address defects. Rights – respects the client's right to accurate information. Fairness – provides an honest assessment. Publicity – the decision can be openly explained. **Option (c):** Harm – reduces risks by fixing critical problems. Rights – the client is informed about limitations. Fairness – demonstrates honest communication. Publicity – the decision can be publicly defended. |
| **6. Decision and action** | We choose option (c), supported by option (b). The developer must immediately report both defects to the Scrum Master and Product Owner. The team should prioritize fixing the cancellation rule and monthly attendance calculation. Both defects must be tested. Any unresolved issue must be documented and disclosed during the demonstration. |
| **7. Reflection** | This scenario demonstrates that meeting deadlines should never be more important than honesty and software quality. Hiding known defects can damage client trust and negatively affect users. Developers have a professional responsibility to report problems and communicate the actual condition of their software. |

**Message sent:**

> We discovered two defects that could affect the system's reliability: cancellations within 24 hours are incorrectly accepted, and cancelled registrations are included in monthly attendance reports. We believe these issues should be documented and communicated to the Product Owner before the Sprint 1 review. We will prioritize fixing and testing both defects. If either issue remains unresolved, we should disclose it during the demonstration and explain the planned correction in Sprint 2. We should provide an honest representation of the current system rather than hide known problems from the client.

**Preventive change:** Add automated regression tests for the 24-hour cancellation rule and monthly attendance calculation. Also add a known-issues section to the Sprint review template.

**Git Issue:** #3