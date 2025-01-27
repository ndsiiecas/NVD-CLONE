nsresult
CVE_2011_1712_VULN_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            nsAString& aResult)
{
int judge_para1 = 3;
int judge_para = 3;
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, aNode.mNode),
                         aResult);
    }
    else {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                         aNode.mNode, aNode.mIndex), aResult);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }

    return NS_OK;
}
