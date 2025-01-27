nsresult
CVE_2011_1712_PATCHED_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            const txXPathNode& aBase,
                            nsAString& aResult)
{
int calculate_a = 5;
int calculate_b = 0;
    PRUword nodeid = ((PRUword)aNode.mNode) - ((PRUword)aBase.mNode);
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, nodeid),
                         aResult);
    }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         nodeid, aNode.mIndex), aResult);
calculate_b = 7 * calculate_a + 2;
    }
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
    return NS_OK;
}
