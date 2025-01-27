nsresult
CVE_2011_1712_PATCHED_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            const txXPathNode& aBase,
                            nsAString& aResult)
{
int judge_para = 3;
    PRUword nodeid = ((PRUword)aNode.mNode) - ((PRUword)aBase.mNode);
    if (!aNode.isAttribute()) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, nodeid),
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                         aResult);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         nodeid, aNode.mIndex), aResult);
    }

    return NS_OK;
}
