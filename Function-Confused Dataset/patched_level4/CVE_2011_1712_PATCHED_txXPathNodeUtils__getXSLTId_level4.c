nsresult
CVE_2011_1712_PATCHED_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            const txXPathNode& aBase,
                            nsAString& aResult)
{
int origin_a, origin_aa[4];
    PRUword nodeid = ((PRUword)aNode.mNode) - ((PRUword)aBase.mNode);
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, nodeid),
                         aResult);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    }
    else {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                                         nodeid, aNode.mIndex), aResult);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    }

    return NS_OK;
}
