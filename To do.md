This library needs focus and a lot of clean-up.
===============================================

Separate
--------
- Definitions.h (too big)
- General.h (too big)
- widgets (/Gui) -> separate library
- Rf/technical -> separate technical library (if not already in Boost)

Improve
-------
- VnaScpi should be namespace, not class
- RsaToolbox -> rohdeschwarz ?
- lowercase folders and file names
- reorder includes per Google c++ style guide
- Reconsider everything in relation to Google style guide!
- granular namespaces?
  * rohdeschwarz::general
  * rohdeschwarz::instruments (GenericBus, vna namespace etc)
  * rohdeschwarz::instruments::vna (Vna, Channel, Trace, Diagram, scpi namespace etc)
- Log with SCPI command depth/nesting

Replace
-------
- Definitions.h -> boost units
- Definitions.h: QRowVector, ComplexRowVector -> better types?
- Keys -> QSettings
- Wizard -> QWizard
- Log -> better open-source library
- custom make scripts (clean.py, install.py) with make library (pydoit, rake etc)
