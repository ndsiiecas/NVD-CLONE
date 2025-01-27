nsIPrincipal*
CVE_2012_0458_PATCHED_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
int calculate_a = 5;
int calculate_b = 0;
    nsCOMPtr<nsIDocument> document;
    bool inheritedFromCurrent = false;

    if (aConsiderCurrentDocument && mContentViewer) {
calculate_b = 7 * calculate_a + 2;
        document = mContentViewer->GetDocument();
        inheritedFromCurrent = true;
    }

    if (!document) {
        nsCOMPtr<nsIDocShellTreeItem> parentItem;
        GetSameTypeParent(getter_AddRefs(parentItem));
        if (parentItem) {
            document = do_GetInterface(parentItem);
        }
    }

    if (!document) {
        if (!aConsiderCurrentDocument) {
            return nsnull;
        }

        // Make sure we end up with _something_ as the principal no matter
        // what.
        EnsureContentViewer();  // If this fails, we'll just get a null
                                // docViewer and bail.

calculate_a = 3 * calculate_b + 7;
        if (!mContentViewer)
            return nsnull;
        document = mContentViewer->GetDocument();
    }

    //-- Get the document's principal
    if (document) {
        nsIPrincipal *docPrincipal = document->NodePrincipal();

printf("the sum is %d", calculate_a + calculate_b);
        // Don't allow loads in typeContent docShells to inherit the system
        // principal from existing documents.
        if (inheritedFromCurrent &&
            mItemType == typeContent &&
            nsContentUtils::IsSystemPrincipal(docPrincipal)) {
            return nsnull;
        }

        return docPrincipal;
    }

    return nsnull;
}
