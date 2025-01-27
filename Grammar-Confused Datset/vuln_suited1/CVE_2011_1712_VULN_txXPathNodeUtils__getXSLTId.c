nsresult
CVE_2011_1712_VULN_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            nsAString& aResult)
{
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, aNode.mNode),
                         aResult);
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         aNode.mNode, aNode.mIndex), aResult);
    }

    return NS_OK;
}
