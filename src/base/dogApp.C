#include "dogApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<dogApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

dogApp::dogApp(InputParameters parameters) : MooseApp(parameters)
{
  dogApp::registerAll(_factory, _action_factory, _syntax);
}

dogApp::~dogApp() {}

void
dogApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"dogApp"});
  Registry::registerActionsTo(af, {"dogApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
dogApp::registerApps()
{
  registerApp(dogApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
dogApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  dogApp::registerAll(f, af, s);
}
extern "C" void
dogApp__registerApps()
{
  dogApp::registerApps();
}
