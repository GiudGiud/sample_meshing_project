//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sample_meshing_projectTestApp.h"
#include "sample_meshing_projectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
sample_meshing_projectTestApp::validParams()
{
  InputParameters params = sample_meshing_projectApp::validParams();
  return params;
}

sample_meshing_projectTestApp::sample_meshing_projectTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sample_meshing_projectTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sample_meshing_projectTestApp::~sample_meshing_projectTestApp() {}

void
sample_meshing_projectTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sample_meshing_projectApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sample_meshing_projectTestApp"});
    Registry::registerActionsTo(af, {"sample_meshing_projectTestApp"});
  }
}

void
sample_meshing_projectTestApp::registerApps()
{
  registerApp(sample_meshing_projectApp);
  registerApp(sample_meshing_projectTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sample_meshing_projectTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sample_meshing_projectTestApp::registerAll(f, af, s);
}
extern "C" void
sample_meshing_projectTestApp__registerApps()
{
  sample_meshing_projectTestApp::registerApps();
}
