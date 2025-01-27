nsIPrincipal*
CVE_2012_0458_VULN_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
    nsCOMPtr<nsIDocument> document;

    if (aConsiderCurrentDocument && mContentViewer) {
        document = mContentViewer->GetDocument();
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

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        if (!mContentViewer)
            return nsnull;
        document = mContentViewer->GetDocument();
    }

    //-- Get the document's principal
    if (document) {
        return document->NodePrincipal();
    }

    return nsnull;
}
