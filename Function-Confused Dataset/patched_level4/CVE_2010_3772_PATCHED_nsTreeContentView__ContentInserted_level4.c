void
CVE_2010_3772_PATCHED_nsTreeContentView::ContentInserted(nsIDocument *aDocument,
                                   nsIContent* aContainer,
                                   nsIContent* aChild,
                                   PRInt32 aIndexInContainer)
{
int origin_a, origin_aa[4];
  NS_ASSERTION(aChild, "null ptr");

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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (!element)
      return; // this is not for us
    nsIAtom *parentTag = element->Tag();
    if ((element->IsNodeOfType(nsINode::eXUL) && parentTag == nsGkAtoms::tree) ||
        (element->IsNodeOfType(nsINode::eHTML) && parentTag == nsGkAtoms::select))
      return; // this is not for us
  }

  if (childTag == nsGkAtoms::treechildren) {
    PRInt32 index = FindContent(aContainer);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
    nsCOMPtr<nsIContent> parent = aContainer->GetParent();
    if (parent) {
      PRInt32 index = FindContent(parent);
      if (index >= 0 && mBoxObject)
        mBoxObject->InvalidateRow(index);
    }
  }
  else if (childTag == nsGkAtoms::optgroup) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    InsertRowFor(aContainer, aChild);
  }
  else if (childTag == nsGkAtoms::option) {
    PRInt32 parentIndex = FindContent(aContainer);

    if (parentIndex >= 0) {
      PRInt32 index = 0;
      GetIndexInSubtree(aContainer, aChild, &index);
      PRInt32 count = InsertRow(parentIndex, index, aChild);
      if (mBoxObject)
        mBoxObject->RowCountChanged(parentIndex + index + 1, count);
    }
  }
}
