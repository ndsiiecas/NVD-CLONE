nsIPrincipal*
CVE_2012_0458_VULN_nsDocShell::GetInheritedPrincipal(bool aConsiderCurrentDocument)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    if (!document) {
        if (!aConsiderCurrentDocument) {
            return nsnull;
        }

        // Make sure we end up with _something_ as the principal no matter
        // what.
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        EnsureContentViewer();  // If this fails, we'll just get a null
                                // docViewer and bail.
fclose(para_fp);

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
