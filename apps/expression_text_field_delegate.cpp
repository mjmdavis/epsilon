#include "expression_text_field_delegate.h"
#include "apps_container.h"
#include <math.h>

bool ExpressionTextFieldDelegate::textFieldDidReceiveEvent(TextField * textField, Ion::Events::Event event) {
  if (event == Ion::Events::Event::ENTER && Expression::parse(textField->text()) == nullptr) {
    if (textField->textLength() == 0) {
      return true;
    }
    textField->app()->displayWarning("Attention a la syntaxe jeune padawan");
    return true;
  }
  if (event == Ion::Events::Event::ENTER &&
    isnan(Expression::parse(textField->text())->approximate(*evaluateContext()))) {
      textField->app()->displayWarning("Relis ton cours de maths, veux tu?");
      return true;
  }
  //if (event == Ion::Events::Event::TOOL_BOX) {
  if (event == Ion::Events::Event::F5) {
    AppsContainer * appsContainer = (AppsContainer *)textField->app()->container();
    ToolBoxController * toolBoxController = appsContainer->toolBoxController();
    toolBoxController->setTextFieldCaller(textField);
    textField->app()->displayModalViewController(toolBoxController, 0.f, 0.f, 50, 50, 0, 50);
    return true;
  }
  return false;
}