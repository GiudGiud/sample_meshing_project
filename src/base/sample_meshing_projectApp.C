#include "sample_meshing_projectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sample_meshing_projectApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

sample_meshing_projectApp::sample_meshing_projectApp(InputParameters parameters) : MooseApp(parameters)
{
  sample_meshing_projectApp::registerAll(_factory, _action_factory, _syntax);
}

sample_meshing_projectApp::~sample_meshing_projectApp() {}

void
sample_meshing_projectApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"sample_meshing_projectApp"});
  Registry::registerActionsTo(af, {"sample_meshing_projectApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sample_meshing_projectApp::registerApps()
{
  registerApp(sample_meshing_projectApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sample_meshing_projectApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sample_meshing_projectApp::registerAll(f, af, s);
}
extern "C" void
sample_meshing_projectApp__registerApps()
{
  sample_meshing_projectApp::registerApps();
}
