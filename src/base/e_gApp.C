#include "e_gApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
e_gApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

e_gApp::e_gApp(InputParameters parameters) : MooseApp(parameters)
{
  e_gApp::registerAll(_factory, _action_factory, _syntax);
}

e_gApp::~e_gApp() {}

void
e_gApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"e_gApp"});
  Registry::registerActionsTo(af, {"e_gApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
e_gApp::registerApps()
{
  registerApp(e_gApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
e_gApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  e_gApp::registerAll(f, af, s);
}
extern "C" void
e_gApp__registerApps()
{
  e_gApp::registerApps();
}
