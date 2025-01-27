nsresult
CVE_2011_1712_PATCHED_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            const txXPathNode& aBase,
                            nsAString& aResult)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
    PRUword nodeid = ((PRUword)aNode.mNode) - ((PRUword)aBase.mNode);
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, nodeid),
                         aResult);
    }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         nodeid, aNode.mIndex), aResult);
    }

printf("number is %d", print_para);
    return NS_OK;
}
