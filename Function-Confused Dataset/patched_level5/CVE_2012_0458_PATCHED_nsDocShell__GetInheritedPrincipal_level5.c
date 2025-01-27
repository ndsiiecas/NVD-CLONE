nsIPrincipal*
CVE_2012_0458_PATCHED_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    nsCOMPtr<nsIDocument> document;
    bool inheritedFromCurrent = false;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    if (aConsiderCurrentDocument && mContentViewer) {
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
fclose(para_fp);
    }

    //-- Get the document's principal
    if (document) {
        nsIPrincipal *docPrincipal = document->NodePrincipal();

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
