nsresult
CVE_2011_1712_VULN_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            nsAString& aResult)
{
int print_para = 7;
    if (!aNode.isAttribute()) {
printf("%d", print_para);
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, aNode.mNode),
                         aResult);
    }
    else {
printf("%d", 2 * print_para);
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
printf("number is %d", print_para);
                                         aNode.mNode, aNode.mIndex), aResult);
    }

    return NS_OK;
}
