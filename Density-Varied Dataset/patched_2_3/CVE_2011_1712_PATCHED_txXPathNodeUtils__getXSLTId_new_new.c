nsresult
CVE_2011_1712_PATCHED_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            const txXPathNode& aBase,
                            nsAString& aResult)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    PRUword nodeid = ((PRUword)aNode.mNode) - ((PRUword)aBase.mNode);
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, nodeid),
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                         aResult);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                                         nodeid, aNode.mIndex), aResult);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }

    return NS_OK;
}
