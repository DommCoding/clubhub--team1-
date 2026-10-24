# Failure risks · ITC Club Hub (v0.1, 2026-10-20)

| # | How the project could fail | Chapter 01 topic | Early warning sign | First countermeasure | Owner |
|---|----------------------------|------------------|--------------------|----------------------|-------|
| F1 | Inconsistent capacity logic across files. | Essential difficulties (invisibility) | Same rule written in multiple files. | Centralize rule into a single validated function. | Techsamnang Monyrak  |
| F2 | Tightly coupled modules hindering future updates. | Scale and communication / Complexity | Rebuilding the whole project for a tiny change. | Enforce clear library and frontend boundaries. | Keo Maknioddom |
| F3 | Changing deadline requirements breaking code. | Changing requirements and cost of change | Frequent disputes over rule calculations. | Document rules and use flexible configuration values. | Tim rommnea |
| F4 | Real personal student data leaked via git. | Reliability, security and safety | Real data strings visible in `git status`. | Use synthetic mock data and add data paths to `.gitignore`. | Chea Sovannareach |
| F5 | Broken C++ and UI integration after merges. | Integration, legacy and technical debt | Build errors spike after merging PRs. | Require mandatory peer code reviews before merging. | Pres Samchara |