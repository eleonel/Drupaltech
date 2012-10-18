ELMS: Workflow Purl Integration
Development Sponsored by The Pennsylvania State University
ELMS is Copyright (C) 2008-2012  The Pennsylvania State University

Bryan Ollendyke
bto108@psu.edu

Keith D. Bailey
kdb163@psu.edu

12 Borland
University Park,  PA 16802

***** USAGE *****
This provides the ability to tie workflow state changes to PURL changes.  Traditionally PURL is set manually by the end user, this allows for creating consistent naming conventions for Organic groups and Spaces via PURL.  This makes PURL work more like pathauto but is far more flexible as Spaces is a common provider for PURL activation.

Install the module, then go to the admin/settings/workflow-purl page and map your workflows states to purl values.  This works with tokens to allow for infinite flexibility.

Because of the nature of PURL, this module needs to fire last.  The installer will set it to run after all other modules but if you start to experience issues after installing this module, check that.