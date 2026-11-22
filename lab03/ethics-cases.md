# Ethics Case Analyses – ITC Club Hub
Version 1.0 · 2026-11-22 · Leads: A = Tim Rommnea, B = Pres Samchara

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