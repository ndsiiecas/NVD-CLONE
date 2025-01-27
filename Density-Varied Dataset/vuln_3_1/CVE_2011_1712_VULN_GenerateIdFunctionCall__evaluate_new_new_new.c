nsresult
CVE_2011_1712_VULN_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;

    nsresult rv = NS_OK;
    if (mParams.IsEmpty()) {
        StringResult* strRes;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        rv = aContext->recycler()->getStringResult(&strRes);
        NS_ENSURE_SUCCESS(rv, rv);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

        txXPathNodeUtils::getXSLTId(aContext->getContextNode(),
                                    strRes->mValue);

        *aResult = strRes;
 
        return NS_OK;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    }

    nsRefPtr<txNodeSet> nodes;
    rv = evaluateToNodeSet(mParams[0], aContext,
                           getter_AddRefs(nodes));
    NS_ENSURE_SUCCESS(rv, rv);

    if (nodes->isEmpty()) {
        aContext->recycler()->getEmptyStringResult(aResult);

if(judge_para * 5 > 8)  {printf("math exists!"); }
        return NS_OK;
    }
    
    StringResult* strRes;
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);

    txXPathNodeUtils::getXSLTId(nodes->get(0), strRes->mValue);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    *aResult = strRes;
 
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return NS_OK;
}
