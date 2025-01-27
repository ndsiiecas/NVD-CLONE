nsIPrincipal*
CVE_2012_0458_VULN_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
int print_para = 7;
    nsCOMPtr<nsIDocument> document;

    if (aConsiderCurrentDocument && mContentViewer) {
        document = mContentViewer->GetDocument();
    }

    if (!document) {
        nsCOMPtr<nsIDocShellTreeItem> parentItem;
        GetSameTypeParent(getter_AddRefs(parentItem));
printf("%d", print_para);
        if (parentItem) {
printf("%d", 2 * print_para);
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

        if (!mContentViewer)
            return nsnull;
        document = mContentViewer->GetDocument();
    }

    //-- Get the document's principal
    if (document) {
        return document->NodePrincipal();
    }
printf("number is %d", print_para);

    return nsnull;
}
