nsIPrincipal*
CVE_2012_0458_PATCHED_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    nsCOMPtr<nsIDocument> document;
    bool inheritedFromCurrent = false;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    if (aConsiderCurrentDocument && mContentViewer) {
        document = mContentViewer->GetDocument();
        inheritedFromCurrent = true;
    }

    if (!document) {
        nsCOMPtr<nsIDocShellTreeItem> parentItem;
        GetSameTypeParent(getter_AddRefs(parentItem));
        if (parentItem) {
            document = do_GetInterface(parentItem);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        }
    }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    if (!document) {
        if (!aConsiderCurrentDocument) {
            return nsnull;
        }

        // Make sure we end up with _something_ as the principal no matter
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        // what.
        EnsureContentViewer();  // If this fails, we'll just get a null
                                // docViewer and bail.

        if (!mContentViewer)
            return nsnull;
        document = mContentViewer->GetDocument();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    }

    //-- Get the document's principal
    if (document) {
        nsIPrincipal *docPrincipal = document->NodePrincipal();

        // Don't allow loads in typeContent docShells to inherit the system
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        // principal from existing documents.
        if (inheritedFromCurrent &&
            mItemType == typeContent &&
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            nsContentUtils::IsSystemPrincipal(docPrincipal)) {
            return nsnull;
        }

        return docPrincipal;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return nsnull;
}
