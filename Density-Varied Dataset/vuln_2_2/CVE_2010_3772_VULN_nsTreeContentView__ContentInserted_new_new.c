void
CVE_2010_3772_VULN_nsTreeContentView::ContentInserted(nsIDocument *aDocument,
                                   nsIContent* aContainer,
                                   nsIContent* aChild,
                                   PRInt32 aIndexInContainer)
{
int judge_para1 = 3;
int judge_para = 3;
  NS_ASSERTION(aChild, "null ptr");

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  // Make sure this notification concerns us.
  // First check the tag to see if it's one that we care about.
  nsIAtom *childTag = aChild->Tag();

  if (aChild->IsNodeOfType(nsINode::eHTML)) {
    if (childTag != nsGkAtoms::option &&
        childTag != nsGkAtoms::optgroup)
      return;
  }
  else if (aChild->IsNodeOfType(nsINode::eXUL)) {
    if (childTag != nsGkAtoms::treeitem &&
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        childTag != nsGkAtoms::treeseparator &&
        childTag != nsGkAtoms::treechildren &&
        childTag != nsGkAtoms::treerow &&
        childTag != nsGkAtoms::treecell)
      return;
    // Don't allow XUL nodes to be inserted under non-XUL nodes.
    if (!aContainer->IsNodeOfType(nsINode::eXUL))
      return;
  }
  else {
    return;
  }

  // If we have a legal tag, go up to the tree/select and make sure
  // that it's ours.

  for (nsIContent* element = aContainer; element != mBody; element = element->GetParent()) {
    if (!element)
      return; // this is not for us
    nsIAtom *parentTag = element->Tag();
    if ((element->IsNodeOfType(nsINode::eXUL) && parentTag == nsGkAtoms::tree) ||
        (element->IsNodeOfType(nsINode::eHTML) && parentTag == nsGkAtoms::select))
      return; // this is not for us
  }

  if (childTag == nsGkAtoms::treechildren) {
    PRInt32 index = FindContent(aContainer);
    if (index >= 0) {
      Row* row = mRows[index];
      row->SetEmpty(PR_FALSE);
      if (mBoxObject)
        mBoxObject->InvalidateRow(index);
      if (row->IsContainer() && row->IsOpen()) {
        PRInt32 count = EnsureSubtree(index);
        if (mBoxObject)
          mBoxObject->RowCountChanged(index + 1, count);
      }
    }
  }
  else if (childTag == nsGkAtoms::treeitem ||
           childTag == nsGkAtoms::treeseparator) {
    InsertRowFor(aContainer, aChild);
  }
  else if (childTag == nsGkAtoms::treerow) {
    PRInt32 index = FindContent(aContainer);
    if (index >= 0 && mBoxObject)
      mBoxObject->InvalidateRow(index);
  }
  else if (childTag == nsGkAtoms::treecell) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    nsCOMPtr<nsIContent> parent = aContainer->GetParent();
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (parent) {
      PRInt32 index = FindContent(parent);
      if (index >= 0 && mBoxObject)
        mBoxObject->InvalidateRow(index);
    }
  }
  else if (childTag == nsGkAtoms::optgroup) {
    InsertRowFor(aContainer, aChild);
  }
  else if (childTag == nsGkAtoms::option) {
    PRInt32 parentIndex = FindContent(aContainer);
    PRInt32 index = 0;
    GetIndexInSubtree(aContainer, aChild, &index);
    PRInt32 count = InsertRow(parentIndex, index, aChild);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (mBoxObject)
      mBoxObject->RowCountChanged(parentIndex + index + 1, count);
  }
}
