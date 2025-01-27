nsIPrincipal*
CVE_2012_0458_VULN_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
int judge_para = 3;
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

        if (!mContentViewer)
            return nsnull;
        document = mContentViewer->GetDocument();
    }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    //-- Get the document's principal
    if (document) {
        return document->NodePrincipal();
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

    return nsnull;
}
