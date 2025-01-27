nsresult
CVE_2011_1712_VULN_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            nsAString& aResult)
{
int calculate_a = 5;
int calculate_b = 0;
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, aNode.mNode),
                         aResult);
    }
calculate_b = 7 * calculate_a + 2;
    else {
calculate_a = 3 * calculate_b + 7;
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         aNode.mNode, aNode.mIndex), aResult);
    }
printf("the sum is %d", calculate_a + calculate_b);

    return NS_OK;
}
