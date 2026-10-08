# Contributing

See README.txt for the supported ROM and Windows source-build instructions.
Never upload ROMs, game assets, personal settings, saves or credentials.

For gameplay feedback, include the release version, what happened and steps to
reproduce it. Report feedback at https://x.com/JJ_Retro. Keep security reports
private as described in SECURITY.md.

Pull requests must preserve native static-core execution, the PAL master-clock
model and fail-closed diagnostics. GitHub Windows CI compiles the production
core and frontend and checks source integrity and release version; it does not
claim gameplay or audio qualification.
