#ifndef SEQUENCE_SEQUENCE_EXPRESSION_CELL_H
#define SEQUENCE_SEQUENCE_EXPRESSION_CELL_H

#include "../sequence.h"
#include "sequence_cell.h"
#include "../../shared/text_field_delegate.h"
#include <escher.h>

namespace Sequence {

class SequenceExpressionCell : public SequenceCell, public Shared::TextFieldDelegate {
public:
  SequenceExpressionCell(Responder * parentResponder);
  void setSequence(Sequence * sequence) override;
  Sequence * sequence();
  void drawRect(KDContext * ctx, KDRect rect) const override;
  bool handleEvent(Ion::Events::Event event) override;
  Toolbox * toolboxForTextField(TextField * textField) override;
private:
  Shared::TextFieldDelegateApp * textFieldDelegateApp() override;
  EvenOddCell * viewAtIndex(int index) override;
  void editExpression(Ion::Events::Event event);
  EvenOddExpressionCell m_expressionView;
  EvenOddExpressionCell m_firstInitialConditionView;
  EvenOddExpressionCell m_secondInitialConditionView;
};

}

#endif